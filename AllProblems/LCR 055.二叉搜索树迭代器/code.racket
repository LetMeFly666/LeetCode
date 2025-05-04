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

(define bst-iterator%
  (class object%
    (super-new)

    ; root : (or/c tree-node? #f)
    (init-field
      root)
    
    ; next : -> exact-integer?
    (define/public (next)

      )
    ; has-next : -> boolean?
    (define/public (has-next)

      )))

;; Your bst-iterator% object will be instantiated and called as such:
;; (define obj (new bst-iterator% [root root]))
;; (define param_1 (send obj next))
;; (define param_2 (send obj has-next))