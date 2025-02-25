/*
 * @Author: LetMeFly
 * @Date: 2025-02-25 16:19:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-25 16:45:09
 */
package main

type Allocator struct {
    v []int
}


func Constructor(n int) Allocator {
    return Allocator{
        v: make([]int, n),
    }
}


func (this *Allocator) Allocate(size int, mID int) int {
    for r, cnt := 0, 0; r < len(this.v); r++ {
        if this.v[r] != 0 {
            cnt = 0
            continue
        }
        cnt++
        if (cnt == size) {
            for ; size > 0; size, r = size - 1, r - 1 {
                this.v[r] = mID
            }
            return r + 1
        }
    }
    return -1
}


func (this *Allocator) FreeMemory(mID int) (ans int) {
    for i, v := range this.v {
        if v == mID {
            ans++
            this.v[i] = 0
        }
    }
    return
}


/**
 * Your Allocator object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Allocate(size,mID);
 * param_2 := obj.FreeMemory(mID);
 */