(defun main(l e lvl)
	(cond
		((and (and (numberp l) (> l e)) (= (mod lvl 2) 1)) (- l 1))
		((atom l) l)
		(T (mapcar #'(lambda (a) (main a e (+ lvl 1))) l))
	)
)
(print (main '(1 s 4 (3 f (7))) 0 0))	
