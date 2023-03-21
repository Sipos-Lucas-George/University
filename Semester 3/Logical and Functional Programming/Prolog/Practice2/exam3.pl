insert(E, L, [E|L]).
insert(E, [H|T], [H|R]) :-
	insert(E, T, R).

perm([], []).
perm([H|T], R) :-
	perm(T, R1),
	insert(H, R1, R).

abse(A, B, R) :-
	A>=B, R is A - B; R is B-A. 

abs([_]).
abs([H1,H2|T]) :-
	abs([H2|T]),
	abse(H1,H2,R),
	R>=2.

ones(L, R):-
	perm(L, R),
	abs(R).

alls(L, R) :-
	findall(Res, ones(L, Res), R).