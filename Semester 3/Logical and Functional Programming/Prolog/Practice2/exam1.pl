f([], 0).
f([H|T], S) :-
	f(T, S1),
	S1 < H, !,
	S is H.
f([_|T], S) :-
	f(T, S1),
	S is S1.

p(apple).
t([], 0).
t([H,H1], S) :-
	H > 0, S is 11, !; H1 > 0, !,
	S is 10.


insert(E,L,[E|L]).
insert(E,[H|T],[H|R]):-
    insert(E,T,R).

f([], -1):-!.
f([_|T], Y):- f(T,S), S<1, !, Y is S+2.
f([H|T], Y):- f(T,S), S<0, !, Y is S+H.
f([_|T], Y):- f(T,S), Y is S.


fa([], -1):-!.
fa([_|T], Y):- fa(T,S), a(S, _, Y).

a(S, _, Y) :- S<1, !, Y is S+2.
a(S, H, Y) :- S<0, !, Y is S+H.
a(S, _, S).



insert(H, L, [H|L]).
insert(E, [H|T], [H|R]) :-
	insert(E,T,R).

perm([], []).
perm([H|T], R):-
	perm(T, R1),
	insert(H,R1,R).

arm([H|_], 1, [H]).
arm([_|T], K, R):-
	arm(T, K, R).
arm([H|T], K, R) :-
	K > 1,
	K1 is K-1,
	arm(T, K1, R1),
	insert(H, R1, R).


comb([H|_], 1, [H]).
comb([_|T], K, R):-
	comb(T, K, R).
comb([H|T], K, [H|R]):-
	K > 1,
	K1 is K - 1,
	comb(T, K1, R).

subs([], []).
subs([H|T], [H|R]):-
	subs(T, R).
subs([_|T], R):-
	subs(T, R).

check([], 0).
check([_|T], R) :-
	check(T, R1),
	R is R1 + 1.

sumE([], 0).
sumE([H|T], R) :-
	sumE(T, R1),
	R is R1 + H.

main(L, N, R) :-
	subs(L, R1),
	check(R1, Len),
	Len >= N,
	sumE(R1,  S),
	S mod 3 =:= 0,
	R is R1.

realMain(L, N, R) :-
	findall(Res, main(L, N, Res), R).