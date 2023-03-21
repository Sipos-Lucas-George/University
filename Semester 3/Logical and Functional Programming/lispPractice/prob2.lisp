; dot product on 2 vectors
(defun dot(l1 l2)
	(cond
		((and (null (car l1)) (null (car l2))) nil)
		((null (car l1)) l2)
		((null (car l2)) l1)
		(T (cons (* (car l1) (car l2)) (dot (cdr l1) (cdr l2))))
	)
)
(print (dot '(1) '(2 3 2 2 3)))

; depth of a list
(defun depth(l)
	(cond 
		((null l) 1)
		((listp (car l)) (max (+ (depth (car l)) 1) (depth (cdr l))))
		(T (depth (cdr l)))
	)
)
(print (depth '(1 2 (3 (4 5) (11 22) (11 (22 (33) 44) 55) 6) 7)))

; delete duplicate values linear sorted list
(defun del(l e)
	(cond
		((null l) nil)
		((null e) (cons (car l) (del (cdr l) (car l))))
		((= (car l) e) (del (cdr l) e))
		(T (cons (car l) (del (cdr l) (car l))))
	)
)
(print (del '(1 1 2 2 2 2 3 3 4 4) nil))

; sort linear list without double values
(defun insert (l e)
  	(cond
    	((null l) (list e))
    	((= (car l) e) l)
    	((< e (car l)) (cons e l))
    	(t (cons (car l) (insert (cdr l) e)))
  	)
)
(defun sortL (l)
  	(cond
    	((null l) nil)
    	(t (insert (sortL (cdr l)) (car l)))
  	)
)
(print (sortL '(8 9 3 2 7 5 1 4 0)))

; intersection of 2 sets
(defun check(l e)
	(cond
		((null l) (list e))
		((= e (car l)) l)
		(T (cons (car l) (check (cdr l) e)))
	)
)
(defun inter(l1 l2)
	(cond
		((null l2) l1)
		(T (inter (check l1 (car l2)) (cdr l2)))
	)
)
;(trace inter)
(print (inter '(1 2 3 4 5) '(1 5 2 6 8 9 3)))
