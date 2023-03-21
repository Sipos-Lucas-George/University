insert(E, L, [E|L]).
insert(E, [H|T], [H|R]) :-
	insert(E, T, R).

srt([],[]).
srt([H|T], R) :-
	srt(T,R1),
	insert(H, R1, R).

subs([],[]).
subs([H|T], [H|R]) :-
	subs(T,R).
subs([_|T], R):-
	subs(T, R).

imp([], 0).
imp([H|T], R) :-
	imp(T, R1),
	H mod 2 =:= 1,
	R is R1 + 1.

prg([H1, H2], R) :- R is H1 - H2.
prg([H1,H2|T], R) :- 
	prg([H2|T], R),
	R =:= H1 - H2.

progression([H1,H2,H3]):- H2 =:= (H1 + H3) /2.
progression([H1,H2,H3|T]):-
    H2 =:= (H1 + H3) /2,
    progression([H2,H3|T]).

ones(L, K, R) :-
	subs(L, R),
	imp(R, R1),
	R1 >= K,
	prg(R, _).

alls(L, K, R) :-
	srt(L, RL),
	findall(Res, ones(RL, K, Res), R).