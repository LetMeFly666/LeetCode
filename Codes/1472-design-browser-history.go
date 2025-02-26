/*
 * @Author: LetMeFly
 * @Date: 2025-02-26 13:45:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-26 13:49:00
 */
package main

type BrowserHistory struct {
    history []string
    now,
    right int
}


func Constructor(homepage string) BrowserHistory {
    history := make([]string, 1)
    history[0] = homepage
    return BrowserHistory{
        history: history,
        now: 0,
        right: 0,
    }
}


func (this *BrowserHistory) Visit(url string)  {
    this.now++
    if this.now == len(this.history) {
        this.history = append(this.history, url)
    } else {
        this.history[this.now] = url
    }
    this.right = this.now
}


func (this *BrowserHistory) Back(steps int) string {
    this.now = max(0, this.now - steps)
    return this.history[this.now]
}


func (this *BrowserHistory) Forward(steps int) string {
    this.now = min(this.right, this.now + steps)
    return this.history[this.now]
}


/**
 * Your BrowserHistory object will be instantiated and called as such:
 * obj := Constructor(homepage);
 * obj.Visit(url);
 * param_2 := obj.Back(steps);
 * param_3 := obj.Forward(steps);
 */