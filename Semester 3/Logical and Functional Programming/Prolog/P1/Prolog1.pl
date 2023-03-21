% valley(l1..ln, f) = 
% 	true, n=1 and f=0
% 	valley(l2..ln, 0), l1 < l2
% 	valley(l2..ln, 1), l1 > l2
% 	false, otherwise

% flow mode: (i,i) (i,o)
% valley(L - list, E - boolean)
valley([_],0).
valley([H1,H2|T],_):-
    H1 < H2,
    valley([H2|T],0),
    !.
valley([H1,H2|T],1):-
    H1 > H2,
    valley([H2|T],1),
    !.

