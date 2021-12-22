#!r6rs
(import (rnrs) (rnrs(6)) (rnrs mutable-pairs (6)))


(define (magnitude x)
  (cond ((pair? (car x)) (+ (magnitude x) (magnitude (car x)))
        ((pair? (car (cdr x))) (+ (magnitude x) (magnitude (car (cdr x))))
        (else (+ (* 3 (car x)) (* 2 (car(cdr x))))))
  )

(define (explode x)
  (cond (= 4 (
         (pair? (car x) 1)
         (pair? (car))
           #t))))