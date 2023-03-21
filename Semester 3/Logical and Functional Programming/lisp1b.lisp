; Write recursive Lisp functions for the following problems (optionally, you may use MAP functions):
; A binary tree is memorised in the following two ways:
; (node no-subtrees list-subtree-1 list-subtree-2 ...) (1)
; (node (list-subtree-1) (list-subtree-2) ...) (2)
;As an example, the tree
;     A
;    / \
;   B   C
;      / \
;     D   E
; is represented as follows:
; (A 2 B 0 C 2 D 0 E 0) (1)
; (A (B) (C (D) (E))) (2)
; Except for problems 4 and 9, conversion between types is not allowed
; a direct method should be used instead.
; 9. Convert a tree of type (1) to type (2).

(defun traverseLeft (l n e)
	(cond
    	((null l) nil)
    	((= n (+ 1 e)) nil)
    	(t (cons (car l) (cons (cadr l) (traverseLeft (cddr l) (+ 1 n) (+ (cadr l) e)))))
	)
)

(defun traverseRight (l n e)
	(cond
    	((null l) nil)
    	((= n (+ 1 e)) l)
    	(t (traverseRight (cddr l) (+ 1 n) (+ (cadr l) e)))
	)
)

(defun left(l)
  	(traverseLeft (cddr l) 0 0)
)

(defun right(l)
  	(traverseRight (cddr l) 0 0)
)

(defun myAppend(l p)
  	(cond
   		((null l) p)
    	(t (cons (car l) (myAppend (cdr l) p)))
  	)
)

; conv(l1l2..ln) = 
; = nil , if n = 0
; = myAppend(list(l1), conv(left(l1l2...ln)) U list(conv(right(l1l2...ln)))), if l2 = 2
; = myAppend(list(l1), list(conv(left(l1l2...ln)))), if l2 = 1
; = list(l1), if l2 = 0
(defun conv(l)
  	(cond
    	((null l) nil)
    	((equal (cadr l) 2) (myAppend (list (car l)) (cons (conv(left l)) (list (conv(right l))))))
    	((equal (cadr l) 1) (myAppend (list (car l)) (list (conv(left l)))))
    	(t (list (car l)))
  	)
)

; (print(conv '(A 2 B 0 C 2 D 0 E 0)))

(defun test()
	(assert 
		(and 
			(equal nil (conv nil))
			(equal '(A (B) (C (D) (E))) (conv '(A 2 B 0 C 2 D 0 E 0)))	
		)
	)
)
(test)

