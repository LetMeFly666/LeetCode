/*
 * @Author: LetMeFly
 * @Date: 2025-01-02 16:27:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-02 16:32:36
 */
package main

type pair struct{ start, end int }
type MyCalendar []pair


func Constructor() MyCalendar {
    return MyCalendar{}
}


func (this *MyCalendar) Book(startTime int, endTime int) bool {
    for _, p := range *this {
        if endTime > p.start && p.end > startTime {
            return false
        }
    }
    *this = append(*this, pair{startTime, endTime})
    return true
}


/**
 * Your MyCalendar object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Book(startTime,endTime);
 */