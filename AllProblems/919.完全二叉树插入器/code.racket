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

(define cbt-inserter%
  (class object%
    (super-new)
    
    ; root : (or/c tree-node? #f)
    (init-field
      root)
    
    ; insert : exact-integer? -> exact-integer?
    (define/public (insert val)
      )
    ; get_root : -> (or/c tree-node? #f)
    (define/public (get_root)
      )))

;; Your cbt-inserter% object will be instantiated and called as such:
;; (define obj (new cbt-inserter% [root root]))
;; (define param_1 (send obj insert val))
;; (define param_2 (send obj get_root))