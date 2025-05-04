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

(define/contract (del-nodes root to_delete)
  (-> (or/c tree-node? #f) (listof exact-integer?) (listof (or/c tree-node? #f)))

  )