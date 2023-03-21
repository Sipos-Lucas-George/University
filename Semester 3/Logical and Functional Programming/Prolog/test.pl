% pred(L1, L2, Carry, Res)
% flow model(i,i,i,o)(i,i,i,i)(i,i,o,o)(i,i,o,i)
pred([], [], 0, []) :- !.
pred([_|T], R, C, Res) :- not(is_list(R)), !, pred(T, R, C, Res).
pred([H|T], [L|R], C, [HR|Res]) :- 
	H - C < L, !,
	pred(T, R, 1, Res),
	HR is H*10 - C.
pred([H|T], [L|R], 0, [HR|Res]) :-
	pred(T, R, 0, Res),
	HR is H - C - L.

% pred(l1..ln, p1..pm, c) =
%	[], n=0
%	l1..ln, m=0
%	li-pi-c + pred(li+1..ln,pi+1..pn, 0), li-pi-c >= 0
%	li*10-pi-c + pred(li+1..ln,pi+1..pn, 1), li-pi-c <= 0
%	ln-m - c, m = m+1