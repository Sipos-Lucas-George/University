gcd(A,0,A) :- !.
gcd(0,B,B) :- !.
gcd(A,B,R) :- 
	A1 is A mod B,
	gcd(B, A1, R).

lcm(A,B,R) :-
	gcd(A,B,R1),
	R is A*B/R1.

% L, E, I, Pow, Res
pw([], _, _, _, []) :- !.
pw([H|T], E, I, P, [H,E|R]):- 
	I =:= P,
	P2 is P * 2,
	I2 is I + 1,
	pw(T, E, I2, P2, R), !.
pw([H|T], E, I, P, [H|R]):- 
	I =\= P,
	I2 is I + 1,
	pw(T, E, I2, P, R), !.