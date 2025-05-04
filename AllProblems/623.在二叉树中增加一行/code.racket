; Definition for a binary tree node.
#|

; val : integer?
; left : (or/c tree-node? #f)
; right : (or/c tree-node? #f)
(struct tree-node
  (val left right) #:mutable #:transparent)

; constructor
(define (make-tree-node [val 0])
  (tree-node val #f #f))

|#

(define/contract (add-one-row root val depth)
  (-> (or/c tree-node? #f) exact-integer? exact-integer? (or/c tree-node? #f))
  )