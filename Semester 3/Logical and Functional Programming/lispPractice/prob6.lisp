; test if list linear
(defun test(l)
	(cond
		((null l) T)
		((listp (car l)) nil)
		(T (test (cdr l)))
	)	
)
(print (test '(1 (2))))

; replace first occ of element
(defun replace1(l e o)
	(cond
		((null l) nil)
		((= (car l) e) (cons o (cdr l)))
		(T (cons (car l) (replace1 (cdr l) e o)))
	)
)
(print (replace1 '(1 2 3) 3 4))

; replace sublist with last elem of sublist
(defun replace2(l)
	(cond
		((null l) nil)
		((listp (car l)) (cons (lastE (car l)) (replace2 (cdr l))))
		(T (cons (car l) (replace2 (cdr l))))
	)
)
(defun lastE(l)
	(cond
		((and (null (cdr l)) (not (listp (car l)))) (car l))
		((null l) nil)
		((listp (car l)) (or (lastE (cdr l)) (lastE (car l))))
		(T (lastE (cdr l)))
	)
)
(print (replace2 '(a (b c) (d (e (f g))))))

; merge 2 sorted list unique values
(defun uniq(l)
	(cond
		((null (cdr l)) l)
		((= (car l) (cadr l)) (uniq (cdr l)))
		(T (cons (car l) (uniq (cdr l))))
	)
)
;(print (uniq '(1 2 3 3 4 4 5)))
(defun mergeL(l1 l2)
	(cond
		((null l1) l2)
		((null l2) l1)
		((< (car l1) (car l2)) (cons (car l1) (mergeL (cdr l1) l2)))	
		(T (cons (car l2) (mergeL l1 (cdr l2))))
	)
)
(defun main(l1 l2)
	(uniq (mergeL (uniq l1) (uniq l2)))
)
(print (main '(1 2 2 3 3 4 4 4 5) '(3 4 5 6 6 7 7)))




