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
	subs(L, R),
	check(R, Len),
	Len >= N,
	sumE(R, S),
	S mod 3 =:= 0.

realMain(L, N, R) :-
	findall(Res, main(L, N, Res), R).