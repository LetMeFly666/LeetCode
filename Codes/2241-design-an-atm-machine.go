/*
 * @Author: LetMeFly
 * @Date: 2025-01-05 19:33:50
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-05 19:44:31
 */
package main

type ATM struct { cnt, val []int64 }


func Constructor() (ans ATM) {
    ans.cnt = make([]int64, 5)
    ans.val = []int64{20, 50, 100, 200, 500}
    return
}


func (this *ATM) Deposit(banknotesCount []int)  {
    for i := range banknotesCount {
        this.cnt[i] += (int64)(banknotesCount[i])
    }
}


func (this *ATM) Withdraw(amount int) []int {
    ans := make([]int, 5)
    for i := 4; i >= 0; i-- {
        ans[i] = (int)(min(this.cnt[i], (int64)(amount) / this.val[i]))
        amount -= ans[i] * (int)(this.val[i])
    }
    if amount > 0 {
        return []int{-1}
    }
    for i := range this.cnt {
        this.cnt[i] -= (int64)(ans[i])
    }
    return ans
}


/**
 * Your ATM object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Deposit(banknotesCount);
 * param_2 := obj.Withdraw(amount);
 */