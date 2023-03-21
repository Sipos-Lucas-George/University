; 11.a)Determine the least common multiple of the numerical values of a nonlinear list.
; b)Write a function to test if a linear list of numbers has a "mountain" aspect (a list has a "mountain" aspect if the items increase to a certain point and then decreases. Eg. (10 18 29 17 11 10). The list must have at least 3 atomsto fullfil this criteria.
; c)Remove all occurrences of a maximum numerical element from a nonlinear list.
; d)Write a function which returns the product of numerical even atoms from a list, to any level.
; e) same as d) but odd atoms
; a)

; myGCD(a, b) = 
; = a , if b is not a number
; = b , if a is not a number
; = a , if b = 0
; = myGCD(b, a%b) , otherwise
(defun myGCD(a b)
	(cond
		((and (not (numberp a)) (not (numberp b))) nil)
		((not (numberp a)) b)
		((not (numberp b)) a)
		((= b 0) a)
		(T (myGCD b (mod a b)))
	)
)

; myLCM(a, b) = 
; = a , if b is not a number
; = b , if a is not a number
; = a * b / myGCD(a, b) , otherwise
(defun myLCM(a b)
	(cond
		((and (not (numberp a)) (not (numberp b))) nil)
        ((not (numberp a)) b)
        ((not (numberp b)) a)
		(T (/ (* a b) (myGCD a b)))
	)
)

; lcmForList(l1l2...ln) = 
; = l1 , if n = 1
; = myLCM(lcmForList(l1) , lcmForList(l2...ln)) , if l1 is a list
; = myLCM(l1, lcmForList(l2...ln) , otherwise
(defun listCM(l)
	(cond
		((and (atom(car l)) (null (cdr l))) (car l))
		((listp (car l)) (myLCM (listCM (car l)) (listCM (cdr l))))
		(T (myLCM (car l) (listCM (cdr l))))
	)
)

(defun testA()
	(assert 
		(and
			(equal nil (listCM nil))
			(equal 1 (listCM '(1)))
			(equal 144 (listCM '(24 (16 (12 A B)) 72)))	
		)	
	)
)
; (print (listCM '(24 (16 (12 A B)) 72)))

; b)

; mountain(l1l2...ln, f) = 
; = true , if n <= 1 and f = false
; = mountain(l2...ln, true), if l1 <= l2 and f = true
; = mountain(l2...ln, false), if l1 >= l2 and f = true
; = mountain(l2...ln, false), if l1 >= l2 and f = false
; = false , otherwise
(defun mountain(l d)
	(cond
		((null (cdr l)) (if d nil T))
		((and (< (car l) (cadr l)) (not d)) nil)
		((and (> (car l) (cadr l)) d) (mountain (cdr l) nil))
		(T (mountain (cdr l) d))
	)
)

(defun main(l)
	(if (< (list-length l) 3) nil (mountain l T))
)

(defun testB()
    (assert
        (and			
			(equal nil (main '(1)))
			(equal nil (main '(1 2)))
			(equal T (main '(1 2 1)))
			(equal T (main '(10 18 29 17 11 10)))
			(equal nil (main '(10 18 29 17 11 29 10)))
		)
    )
)

; (print(main '(10 18 29 17 11 10)))
; (print(main '(10 18 29 17 11 29 10)))

; c)
(defun maxNum(a b)
	(if (> a b) a b)
)

; maxList(l1l2...ln) = 
; = nil , if n = 0
; = maxNum(maxForList(l1), maxForList(l2...ln)) , if l1 is a list
; = maxNum(l1, maxList(l2...ln)) , otherwise
(defun maxList(l)
	(cond
		((null l) -1)
		((and (null (cdr l)) (numberp (car l))) (car l))
		((numberp(car l)) (maxNum (car l) (maxList (cdr l))))
		((listp(car l)) (maxNum (maxList(car l)) (maxList(cdr l))))
		(T (maxList (cdr l)))
	)
)

(defun testC()
	(assert
		(and
			(equal -1 (maxList nil))
			(equal -1 (maxList '(a b (c))))
			(equal 1 (maxList '(1 0)))
			(equal 5 (maxList '(1 2 (3 (a) (1 3)) 4 5)))
		)
	)
)

; (print(maxList '(1 2 (3 (a) (1 3)) 4 5)))

; d)
(defun lookForNumbers (l)
	(cond
    	((null l) nil)
    	((listp (car l)) (or (lookForNumbers (car l)) (lookForNumbers (cdr l))))
    	((numberp (car l)) t)
    	(t (lookForNumbers (cdr l)))
  	)
)

(defun isEven(a)
	(if (= (mod a 2) 0) t nil)
)

; productEvenNumbers(l1l2...ln) = 
; = 1, if n = 0
; = productEvenNumbers(l1) * productEvenNumbers(l2...ln) , if l1 is a list
; = l1 * productEvenNumbers(l2...ln) , if l1 is a number and is even
; = productEvenNumbers(l2...ln) , otherwise
(defun productEvenNumbers(l)
  	(cond
    	((null l) 1)
    	((listp (car l)) (* (productEvenNumbers (car l)) (productEvenNumbers (cdr l))))
    	((and (numberp (car l)) (isEven (car l))) (* (car l) (productEvenNumbers (cdr l))))
    	(t (productEvenNumbers (cdr l)))
  	)
)

(defun mainD(l)
  	(cond
   		((lookForNumbers l) (productEvenNumbers l))
    	(t 0)
  	)
)

(defun testD()
    (assert
        (and
            (equal 0 (mainD nil))
            (equal 0 (mainD '(a b (c))))
            (equal 0 (mainD '(1 0)))
            (equal 48 (mainD '(1 2 (3 4) 5 (6) 7)))
        )
    )
)

;(print(mainD '(1 2 (3 4) 5 (6) 7)))

; e)
(defun productNumE(l)
    (cond
        ((and (numberp l) (= (mod l 2) 1)) l)
        ((atom l) 1)
        (T (apply '* (mapcar 'productNumE l)))
    )
)

(defun isOdd(a)
    (if (= (mod a 2) 1) t nil)
)

; productOddNumbers(l1l2...ln) = 
; = 1, if n = 0
; = productOddNumbers(l1) * productOddNumbers(l2...ln) , if l1 is a list
; = l1 * productOddNumbers(l2...ln) , if l1 is a number and is odd
; = productOddNumbers(l2...ln) , otherwise
(defun productOddNumbers(l)
    (cond
        ((null l) 1)
        ((listp (car l)) (* (productOddNumbers (car l)) (productOddNumbers (cdr l))))
        ((and (numberp (car l)) (isOdd (car l))) (* (car l) (productOddNumbers (cdr l))))
        (t (productOddNumbers (cdr l)))
    )
)

(defun mainE(l)
    (cond
        ((lookForNumbers l) (productOddNumbers l))
        (t 0)
    )
)

(defun testE()
    (assert
        (and
            (equal 0 (mainE '()))
            (equal 0 (mainE '(a b (c))))
            (equal 1 (mainE '(1 0)))
            (equal 105 (mainE '(1 2 (3 4) 5 (6) 7)))
        )
    )
)

;(print(productNumE '(1 2 (3 4) 5 (6) 7)))
(testA)
(testB)
(testC)
(testD)
(testE)





