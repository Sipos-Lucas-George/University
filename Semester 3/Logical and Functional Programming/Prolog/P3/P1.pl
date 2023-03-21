% par() =
%	'('
%	')'

paranthesis('(').
paranthesis(')').

% check(l1..ln, s) =
% 	check(l2..ln, s + 1), l1 = '('
% 	check(l2..ln, s - 1), l1 = ')' and s > 0

% flow model: (i,i)
check([], 0).
check([H|T], S) :-
	H == '(',
	SI is S + 1,
	check(T, SI).
check([H|T], S) :-
	H == ')',
	S > 0,
	SI is S - 1,
	check(T, SI).

% allP(n, s) =
% 	s, n = 0
% 	allP(n - 1, paranthesis(x) + s), otherwise

% flow model: (i,i,i), (i,i,o)
allP(0, S, S) :- !.
allP(N, S, R) :-
	paranthesis(X),
	NI is N - 1,
	allP(NI, [X|S], R).

sol(N, R) :-
	allP(N, [], R),
	check(R, 0).

allSol(N, R) :- findall(Res, sol(N, Res), R).


test() :- 
	allSol(0, [[]]),
	allSol(1, []),
	allSol(2, [['(',')']]),
	allSol(3, []),
	allSol(4, [['(',')','(',')'], ['(','(',')',')']]).