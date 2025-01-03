/*
 * @Author: LetMeFly
 * @Date: 2025-01-03 13:22:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-03 13:31:46
 */
package main

type pair struct{s, e int}
type MyCalendarTwo struct {booked, overlap []pair}


func Constructor() MyCalendarTwo {
    return MyCalendarTwo{}
}


func (this *MyCalendarTwo) Book(startTime int, endTime int) bool {
    for _, o := range this.overlap {
        if endTime > o.s && o.e > startTime {
            return false
        }
    }
    for _, b := range this.booked {
        if endTime > b.s && b.e > startTime {
            this.overlap = append(this.overlap, pair{max(startTime, b.s), min(endTime, b.e)})
        }
    }
    this.booked = append(this.booked, pair{startTime, endTime})
    return true
}


/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Book(startTime,endTime);
 */