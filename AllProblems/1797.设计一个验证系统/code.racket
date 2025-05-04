(define authentication-manager%
  (class object%
    (super-new)
    
    ; time-to-live : exact-integer?
    (init-field
      time-to-live)
    
    ; generate : string? exact-integer? -> void?
    (define/public (generate token-id current-time)
      )
    ; renew : string? exact-integer? -> void?
    (define/public (renew token-id current-time)
      )
    ; count-unexpired-tokens : exact-integer? -> exact-integer?
    (define/public (count-unexpired-tokens current-time)
      )))

;; Your authentication-manager% object will be instantiated and called as such:
;; (define obj (new authentication-manager% [time-to-live time-to-live]))
;; (send obj generate token-id current-time)
;; (send obj renew token-id current-time)
;; (define param_3 (send obj count-unexpired-tokens current-time))