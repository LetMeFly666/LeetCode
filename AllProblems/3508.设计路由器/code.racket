(define router%
  (class object%
    (super-new)
    
    ; memory-limit : exact-integer?
    (init-field
      memory-limit)
    
    ; add-packet : exact-integer? exact-integer? exact-integer? -> boolean?
    (define/public (add-packet source destination timestamp)
      )
    ; forward-packet : -> (listof exact-integer?)
    (define/public (forward-packet)
      )
    ; get-count : exact-integer? exact-integer? exact-integer? -> exact-integer?
    (define/public (get-count destination start-time end-time)
      )))

;; Your router% object will be instantiated and called as such:
;; (define obj (new router% [memory-limit memory-limit]))
;; (define param_1 (send obj add-packet source destination timestamp))
;; (define param_2 (send obj forward-packet))
;; (define param_3 (send obj get-count destination start-time end-time))