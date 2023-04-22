:-set_prolog_stack(global,2000000000).
:-set_prolog_stack(trail,200000000).
:-set_prolog_stack(local,20000000).

generate_bytes(0,[]).
generate_bytes(N,[E|L]):-  N1 is N -1,random(0,255,E), generate_bytes(N1,L).

number_of_one_in_byte(0,0).
number_of_one_in_byte(1,1). 
number_of_one_in_byte(A,N1+1):-  A1 is A-1, A2 is A/\A1,number_of_one_in_byte(A2,N1).


number_one_list([],0).
number_one_list([H|T],R):-number_of_one_in_byte(H,N),number_one_list(T,R1),R is R1+N.

entropy_list(L,E):- number_one_list(L,O),
                                    length(L,N),
                                   Totalbits is 8*N, 
                                   Z is Totalbits-O,
                                   P1 is O/ Totalbits,
                                   P2 is Z/Totalbits,
                                  log(P1,Lg1),
                                  log(P2,Lg2),
                                  log(2,L2),
                                  E1 is -P1*(Lg1/ L2),
                                  E2 is -P2*(Lg2 / L2),
                                  E is E1+E2.

main_program(N,E,L,T0,T1,T):-get_time(T0),generate_bytes(N,L),entropy_list(L,E),get_time(T1),T is T1-T0.

/*run seesion
?- main_program(1 000 000,L,E,T0,T1,T).
L = 0.9999869199872911,
E = [167, 26, 237, 35, 43, 64, 169, 227, 172|...],
T0 = 1678195752.16185,
T1 = 1678195754.575202,
T = 2.4133520126342773 

*/





