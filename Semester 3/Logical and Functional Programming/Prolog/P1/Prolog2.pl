% altSum(l1..ln) =
% 	0, n=0
%	l1, n=1
%	l1-l2 + altSum(l3..ln), otherwise 

% flow mode: (i,i) (i,o)
% altSum(L - list, E - integer)
altSum([], 0).
altSum([H], H):- !.
altSum([H1,H2|T], S):-
	altSum(T, N),
	S is N+H1-H2.	