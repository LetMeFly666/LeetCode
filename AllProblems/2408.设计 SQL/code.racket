(define sql%
  (class object%
    (super-new)
    
    ; names : (listof string?)
    ; columns : (listof exact-integer?)
    (init-field
      names
      columns)
    
    ; ins : string? (listof string?) -> boolean?
    (define/public (ins name row)
      )
    ; rmv : string? exact-integer? -> void?
    (define/public (rmv name row-id)
      )
    ; sel : string? exact-integer? exact-integer? -> string?
    (define/public (sel name row-id column-id)
      )
    ; exp : string? -> (listof string?)
    (define/public (exp name)
      )))

;; Your sql% object will be instantiated and called as such:
;; (define obj (new sql% [names names] [columns columns]))
;; (define param_1 (send obj ins name row))
;; (send obj rmv name row-id)
;; (define param_3 (send obj sel name row-id column-id))
;; (define param_4 (send obj exp name))