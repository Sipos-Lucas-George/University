; find the n-th element if exists
(defun func(l)
	(cond
		((null (car l)) nil)
		((listp (car l)) (append (func (car l)) (func (cdr l))))
		(T (cons (car l) (func (cdr l))))
	)
)

(defun nElem(l n)
	(cond
		((= n 1) (car l))
		((null l) nil) 
		((listp (car l)) (nElem (car l) n))
		(T (nElem (cdr l) (- n 1)))
	)
)


(print (nElem (func '((2 3 4) (6 (7 8) (7 9) 8) (6 8) 9)) 14))

; find element if exists
(defun findE(l e)
	(cond
		((null (car l)) nil)
		((and (atom (car l)) (equal (car l) e)) T)
		((listp (car l)) (or (findE (car l) e) (findE (cdr l) e)))
		(T (findE (cdr l) e))
	)
)

(print (findE '(1 2 (3 (4 5) 6) 7) 5))

; append sublists of list in new list
(defun main(l)
	(cond
		((null (car l)) nil)
		((listp (car l)) (append (append (list (car l)) (main (car l))) (main (cdr l))))	
		(T (main (cdr l)))
	)
)

(print (main '(1 2 (3 (4 5) (11 22) (11 (22 (33) 44) 55) 6) 7)))

; list to set
(defun searchE(l e i)
	(cond
		((null (car l)) nil)
		((and (= i 0) (= (car l) e)) (if (listp (car l)) (append (car l) (searchE (cdr l) e (+ i 1))) (append (list (car l)) (searchE (cdr l) e (+ i 1)))))
		((and (> i 0) (= (car l) e)) (searchE (cdr l) e i))
		(T (if (listp (car l)) (append (car l) (searchE (cdr l) e i)) (append (list (car l)) (searchE (cdr l) e i))))
	)
)

(defun setL(l li)
	(cond
		((null (car l)) li)
		(T (setL (cdr l) (searchE li (car l) 0)))
	)	
)


(defun mainM(l)
	(setL l l)
)

(print (mainM '(1 2 3 4 5 11 22 11 22 3 4 5 6 7)))
