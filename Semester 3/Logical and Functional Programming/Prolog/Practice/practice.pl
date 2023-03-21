% (A, B, Res)
gcd(A, 0, A) :- !.
gcd(0, B, B) :- !.
gcd(A, B, R) :- 
	A >= B,
	A1 is A mod B,
	gcd(A1, B, R), !.
gcd(A, B, R) :- 
	A < B,
	B1 is B mod A,
	gcd(A, B1, R), !.


lcm(A, B, R) :-
	gcd(A, B, Res),
	R is A * B / Res.


remove_occ([], _, []) :- !.
remove_occ([H|T], E, R) :- 
	H =:= E, !,
	remove_occ(T, E, R).
remove_occ([H|T], E, [H|R]) :-
	remove_occ(T, E, R).

% bubble start
bubblesort(List, SortedList) :-
    swap(List, List1), !,
    bubblesort(List1, SortedList).
bubblesort(List, List).

swap([X,Y|Rest], [Y,X|Rest]) :-
    X > Y, !.
swap([Z|Rest], [Z|Rest1]) :-
	swap(Rest, Rest1).
% bubble end


% single elem
append([], E, [E]).
append([H|T], E, [H|R]) :- 
	append(T, E, R).

% list
appendL([], E, E).
appendL([H|T], E, [H|R]) :- 
	appendL(T, E, R).

% problem 1
% divs(E, Div, List)
divs(1, _, L, L) :- !.
divs(E, D, L, L) :- 
	E =:= D,
	!.
divs(E, D, Res, R) :- 
	E mod D =:= 0, !,
	D1 is D + 1,
	divs(E, D1, [D|Res], R).
divs(E, D, Res, R) :-
	D1 is D + 1,
	divs(E, D1, Res, R).
divsmain(E, R) :- divs(E, 2, [], R).


parseList([],[]).
parseList([H|T], [H|R]) :- 
	parseList(T, RD),	
	divs(H, 2, RD, R).
		

% hetoList(List, Res)
hetoList([], []) :- !.
hetoList([H|L], [HR|R]) :- 
	is_list(H), !,
	parseList(H, HR),
	hetoList(L, R).
hetoList([H|L], [H|R]) :- hetoList(L, R).


% problem 2
maxn(A,B,A) :- A >= B, !.
maxn(A,B,B) :- B > A, !.

maxList([H], H) :- !.
maxList([H|T], Res) :- 
	maxList(T, newRes),
	maxn(H, newRes, Res).



