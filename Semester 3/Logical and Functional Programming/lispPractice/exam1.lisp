(defun replaceElems(l level k)
  (cond
    ((and (atom l) (equal level k)) 0)
    ((atom l) l)
    (t (mapcar #' (lambda (a) (replaceElems a (+ 1 level) k)) l))
  )
)


(defun main(l k)
  (replaceElems l 0 k)
)
(trace replaceElems)
(print (main '(a (1 (2 b)) (c (d))) 2))
