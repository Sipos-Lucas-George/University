% pred(l1..ln, c)
% 	[], n = 0
% 	[9], n = 1 and l1 = 0
% 	[l1 - 1], n = 1 and l1 != 0
% 	9 + pred(l2..ln, 1), c = 1 and l1 = 0
% 	(l1 - c) + pred(l2..ln, c), otherwise

% flow mode: (i,o,o), (i,i,i)
pred([], _, []) :- !.
pred([0], 1, [9]) :- !.
pred([N], 0, [NR]) :- NR is N - 1, !.
pred([0|T], 1, [9|R]) :- pred(T, 1, R), !.
pred([H|T], 0, [HR|R]) :- pred(T, C, R), HR is H - C.

mainPred(A, B) :- pred(A, 0, B).

testPred() :- mainPred([1, 9, 3, 6, 0, 0], [1, 9, 3, 5, 9, 9]),
			mainPred([1, 0], [0, 9]),
			mainPred([], []).