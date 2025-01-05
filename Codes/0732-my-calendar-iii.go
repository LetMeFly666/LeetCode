/*
 * @Author: LetMeFly
 * @Date: 2025-01-05 21:45:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-05 21:57:58
 */
package main

type pair_myCalendarIII struct {num, lazy int}
type MyCalendarThree map[int]pair_myCalendarIII

func max_MC3(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func Constructor() MyCalendarThree {
    return MyCalendarThree{}
}

func (this MyCalendarThree) update(start, end, index, l, r int) {
    if l > end || start > r {
        return
    }
    if l >= start && r <= end {
        p := this[index]
        p.num++  // 不可直接this[index].num++
        p.lazy++
        this[index] = p
    } else {
        mid := (l + r) >> 1
        this.update(start, end, index * 2 + 1, l, mid)
        this.update(start, end, index * 2 + 2, mid + 1, r)
        p := this[index]
        p.num = this[index].lazy + max_MC3(this[index * 2 + 1].num, this[index * 2 + 2].num)
        this[index] = p
    }
}

func (this MyCalendarThree) Book(startTime int, endTime int) int {
    this.update(startTime, endTime - 1, 0, 0, 1000000000)
    return this[0].num
}


/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Book(startTime,endTime);
 */