

perfectNumbersCall(A,B,L,Time):- get_time(T0),perfectNumbers(A,B,L),get_time(T1),Time is T1-T0.
perfectNumbers(A,B,[]):- A>B,!.
perfectNumbers(A,B,[A|R]) :- perfectNumber(A),!,A1 is A+1,perfectNumbers(A1,B,R).
perfectNumbers(A,B,R) :- A1 is A+1,perfectNumbers(A1,B,R).

perfectNumber(A):- divisors(A,L),sum(L,S),S is A.

divisors(A,L):- divisorsHelp(A,1,L).

divisorsHelp(A,A,[]).
divisorsHelp(A,X,[X|L]):-X<A,0 is A mod X ,!,X1 is X+1,divisorsHelp(A,X1,L).
divisorsHelp(A,X,L):-  X<A,!,X1 is X+1,divisorsHelp(A,X1,L).

sum([],0).
sum([H|T],S):-  sum(T,S1),S is S1+H.

/* to find out the perfect numnbers and time of execution use call 

?perfectNumbersCall(A,B,L,Time).

Ex:
?perfectNumbersCall(1,10000,L,T).
L= [6, 28, 496, 8128],
T= 12.93991994857788.
*/