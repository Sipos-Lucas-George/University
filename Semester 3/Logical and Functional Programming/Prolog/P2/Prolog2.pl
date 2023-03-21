% pred(l1..ln, c)
% 	[], n = 0
% 	[9], n = 1 and l1 = 0
% 	[l1 - 1], n = 1 and l1 != 0
% 	9 + pred(l2..ln, 1), c = 1 and l1 = 0
% 	(l1 - c) + pred(l2..ln, c), otherwise

% flow model: (i,o,o), (i,i,i)
pred([], _, []) :- !.
pred([0], 1, [9]) :- !.
pred([N], 0, [NR]) :- NR is N - 1, !.
pred([0|T], 1, [9|R]) :- pred(T, 1, R), !.
pred([H|T], 0, [HR|R]) :- pred(T, C, R), HR is H - C.

mainPred(A, B) :- pred(A, _, B).

% straightList(l1...ln) = 
% 	[], n = 0
% 	pred(l1..ln, 0) + straightList(l2...ln), is_list(l1) = True
% 	l1 + straightList(l2...ln), otherwise

% flow model: (i,o), (i,i)
straightList([], []).
straightList([H|T], [HR|R]) :- is_list(H), !,
	mainPred(H, HR),
	straightList(T, R).
straightList([H|T], [H|R]) :- straightList(T, R).

%testa() :- straightList([], []),
%	     straightList(
%			[1, [2, 3], 4, 5, [6, 7, 9], 10, 11, [1, 2, 0], 6],
%			[1, [2, 2], 4, 5, [6, 7, 8], 10, 11, [1, 1, 9], 6]
%		),
%	     straightList([1, 2, 3], [1, 2, 3]),
%	     straightList([[1]], [[0]]).

sList([], [], []).
sList([H|T], [HR|R], Q) :- is_list(H), !,
	mainPred(H, HR),
	sList(T, R, Q).
sList([H|T], R, L) :- sList(T, R, Q), append(Q, [H], L).

test2() :- sList([], [], []),
	     sList([1, [2, 3], 6], [[2, 2]], [6, 1]).