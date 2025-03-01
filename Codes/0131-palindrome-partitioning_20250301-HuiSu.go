/*
 * @Author: LetMeFly
 * @Date: 2025-03-01 16:28:38
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-01 16:41:12
 */
package main

type Solution_PP struct {
    s string
    ans [][]string
    now []string
    
}

func (this* Solution_PP) ok(s string) bool {
    for i := 0; i < len(s) / 2; i++ {
        if s[i] != s[len(s) - i - 1] {
            return false
        }
    }
    return true
}

func (this* Solution_PP) dfs(l int) {
    if l == len(this.s) {
        this.ans = append(this.ans, append([]string{}, this.now...))
        return
    }
    for r := l; r < len(this.s); r++ {
        temp := this.s[l:r + 1]
        if this.ok(temp) {
            this.now = append(this.now, temp)
            this.dfs(r + 1)
            this.now = this.now[:len(this.now) - 1]
        }
    }
}

func partition(s string) [][]string {
    solution := Solution_PP{s: s}
    solution.dfs(0)
    return solution.ans
}