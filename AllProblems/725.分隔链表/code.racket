; Definition for singly-linked list:
#|

; val : integer?
; next : (or/c list-node? #f)
(struct list-node
  (val next) #:mutable #:transparent)

; constructor
(define (make-list-node [val 0])
  (list-node val #f))

|#

(define/contract (split-list-to-parts head k)
  (-> (or/c list-node? #f) exact-integer? (listof (or/c list-node? #f)))
  )