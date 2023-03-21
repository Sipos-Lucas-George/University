; insert element after every 2nd 4th 6th .. element
(defun insertA(l e i)
	(cond
		((null l) nil)
		((= (mod i 2) 0) (cons (car l) (cons e (insertA (cdr l) e (+ i 1)))))
		(T (cons (car l) (insertA (cdr l) e (+ i 1))))
	)
)
(print (insertA '(1 2 3 4 5 6 7 8) 0 1))

; reverse non-linear list of atoms 
(defun rev(l)
	(cond
		((null l) nil)
		((listp (car l)) (append (rev (cdr l)) (rev (car l))))
		(T (append (rev (cdr l)) (list(car l))))
	)
)
(print (rev '(((A B) C) (D E))))

; gcd non-linear list
(defun gcdE(e1 e2)
	(cond
		((null e2) e1)
		((= e2 0) e1)
		((< e1 e2) (gcdE e2 e1))
		(T (gcdE e2 (mod e1 e2)))
	)
)
(defun gcdL(l)
	(cond
		((null l) nil)
		((listp (car l)) (gcdE (gcdL(car l)) (gcdL (cdr l))))
		(T (gcdE (car l) (gcdL (cdr l))))
	)
)
;(trace gcdL)
(print (gcdL '(16 (32 4) 8 (16 (32 (64))))))

; number of occ of a given element in a non-linear list
(defun occ(l e)
	(cond 
		((null l) 0)
		((and (atom (car l)) (= e (car l))) (+ 1 (occ (cdr l) e)))
		((listp (car l)) (+ (occ (car l) e) (occ (cdr l) e)))
		(T (occ (cdr l) e))
	)	
)
(print (occ '(1 2 2 (2 3 2 (2 4) 2) 2) 2))
