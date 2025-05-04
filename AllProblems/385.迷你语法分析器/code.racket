;; This is the interface that allows for creating nested lists.
;; You should not implement it, or speculate about its implementation

#|

(define nested-integer%
  (class object%
    ...

    ; Return true if this nested-integer% holds a single integer, rather than a nested list.
    ; -> boolean?
    (define/public (is-integer)
      ...)

    ; Return the single integer that this nested-integer% holds, if it holds a single integer,
    ; or #f if this nested-integer% holds a nested list.
    ; -> integer?
    (define/public (get-integer)
      ...)

    ; Set this nested-integer% to hold a single integer equal to value.
    ; -> integer? void?
    (define/public (set-integer i)
      ...)

    ; Set this nested-integer% to hold a nested list and adds a nested integer elem to it.
    ; -> (is-a?/c nested-integer%) void?
    (define/public (add ni)
      ...)

    ; Return the nested list that this nested-integer% holds,
    ; or an empty list if this nested-integer% holds a single integer.
    ; -> gvector?
    (define/public (get-list)
      ...)))

|#

(define/contract (deserialize s)
  (-> string? (is-a?/c nested-integer%))
  )