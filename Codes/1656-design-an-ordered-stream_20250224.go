/*
 * @Author: LetMeFly
 * @Date: 2025-02-24 09:09:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-24 09:35:40
 */
package main

type OrderedStream struct {
    n,
    ptr int
    v []string
}


func Constructor(n int) OrderedStream {
    return OrderedStream{
        n: n,
        ptr: 1,
        v: make([]string, n + 1),
    }
}


func (this *OrderedStream) Insert(idKey int, value string) []string {
    this.v[idKey] = value
    start := this.ptr
    for this.ptr <= this.n && len(this.v[this.ptr]) > 0 {
        this.ptr++
    }
    return this.v[start:this.ptr]
}


/**
 * Your OrderedStream object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Insert(idKey,value);
 */