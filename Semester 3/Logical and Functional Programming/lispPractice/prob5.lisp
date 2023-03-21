; write twice the n-th element
(defun twice(l n)
	(cond
		((null l) nil)
		((= n 1) (cons (car l) (cons (car l) (twice (cdr l) (- n 1)))))
		(T (cons (car l) (twice (cdr l) (- n 1))))
	)
)
(print (twice '(10 20 30 40 50) 3))

; my append list
(defun mapp(l1 l2)
	(cond
		((null l1) l2) ; (list l2) if l2 element
		(T (cons (car l1) (mapp (cdr l1) l2)))
	)	
)
;(print (mapp '(1) '(3)))

; association of 2 lists
(defun assL(l1 l2)
	(cond
		((null l1) nil)
		(T (cons (cons (car l1) (list (car l2))) (assL (cdr l1) (cdr l2))))
	)
)
(print (assL '(A B C) '(1 2 3)))

; count nr of sublists
(defun cnt(l)
	(cond 
		((null l) 1)
		((listp (car l)) (+ (cnt (car l)) (cnt (cdr l))))
		(T (cnt (cdr l)))
	)
)
(print (cnt '(1 2 (3 (4 5) (6 7)) 8 (9 10))))
