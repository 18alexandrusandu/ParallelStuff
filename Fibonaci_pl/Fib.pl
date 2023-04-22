


sqrt5helper(R,R2,Precision):-pow(10,2*Precision,N1), N2 is 5*N1,nth_integer_root_and_remainder(2,N2,R,_),pow(10,Precision,R2) .
sqrt5(R,R2):-sqrt5helper(R,R2,650).
phi(P1,P2):- sqrt5(R1,R2),P1 is R2+R1,P2 is 2*R2.

phin(N,Pn1,Pn2):-phi(P1,P2),pow(P1,N,Pn1),pow(P2,N,Pn2).


:- dynamic fibResult/2.

fib(N,Fn):-phin(N,Pn1,Pn2),sqrt5(R1,R2), 
                 Fup1 is Pn1*R2,Fdn1 is Pn2*R1, 
                 Fup2 is Fdn1+2*Fup1,Fdn2 is 2*Fdn1,
                 Fn is Fup2//Fdn2.


worker(L,L,_):-thread_self(_),fib(L,FIB),assertz(fibResult(L,FIB)),
                                                               write("Hello"),!.

worker(Begin,Limit,Step):-  thread_self(_),
                                                               Begin<Limit,
                                                               fib(Begin,FIB),assertz(fibResult(Begin,FIB)), NStep is Begin+Step, 
                                                               worker(NStep,Limit,Step).
worker(Begin,Limit,_):- Begin>Limit.


fork_threads(0,_,[],_):-!.
fork_threads(N,NN,[H|T],Limit):-
 N1 is N-1, 
 fork_threads(N1,NN,T,Limit), 
 thread_create(worker(N,Limit,NN), H, []).


 % join N threads
join_threads([]).
join_threads([H|T]):-thread_join(H, _),
  join_threads(T).
% fork-join N threads
nt(N,Limit):-
   get_time(T0),
    fork_threads(N,N,List,Limit),
    join_threads(List),
    get_time(T1),
    T is T1-T0,
    fibResult(1000,F1000),
    write("F1000:"),
    write(F1000),
    write("\next"),
    write("\n"), 
      write("F2000:"),
    fibResult(2000,F2000),
    write(F2000),
    write("\next"),
    write("\n"), 
    fibResult(3000,F3000),
    write("F3000:"),
    write(F3000),
    write("\next"),
    write("\n"), 
write('Elapsed Time : '),
write(T),
write("for n threads"),
write(N),
write("\n"),
 nl.

nt_for_all(0,L):-nt(1,L).
nt_for_all(Power2,LimitFib):-pow(2,Power2,P2),nt(P2,LimitFib),
    retractall(fibResult(_,_)),
    Next is Power2-1,nt_for_all(Next,LimitFib).








