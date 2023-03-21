valley([_], 0):-!.
valley([H1, H2|T], _) :- H1 < H2, !,
	valley([H2|T], 0), !.
valley([_, H2|T], 1) :- 
	valley([H2|T], 1), !.

alter([], 0).
alter([H1,H2|T], S) :-
	alter(T, S1),
	S is S1+H1-H2, !.
alter([H],H).
