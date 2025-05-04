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

(define find-elements%
  (class object%
    (super-new)
    
    ; root : (or/c tree-node? #f)
    (init-field
      root)
    
    ; find : exact-integer? -> boolean?
    (define/public (find target)
      )))

;; Your find-elements% object will be instantiated and called as such:
;; (define obj (new find-elements% [root root]))
;; (define param_1 (send obj find target))