(defun main(l lvl)
	(cond
		((and (and (atom l) (not (numberp l))) (= (mod lvl 2) 0)) nil)
		((atom l) (list l))
		(T (list (mapcan #'(lambda (a) (main a (+ lvl 1))) l)))
	)
)
(print (main '(a (1 (2 b)) (c (d))) 0))
