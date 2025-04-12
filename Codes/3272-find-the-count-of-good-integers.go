/*
 * @Author: LetMeFly
 * @Date: 2025-04-12 11:14:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-12 11:40:36
 * @Description: AC,25.00%,75.00%,一遍过
 */
package main

import (
    "math"
    "strconv"
    "sort"
    "strings"
)

type solution3273 struct{
    n, k int
    factor []int
    visited map[string]bool
}

func init3273(n int, k int) *solution3273 {
    ans := &solution3273{
        n: n,
        k: k,
        factor: make([]int, n + 1),
        visited : map[string]bool{},
    }
    ans.factor[0] = 1
    for i := 1; i <= n; i++ {
        ans.factor[i] = ans.factor[i - 1] * i
    }
    return ans
}

func (t* solution3273) isOk(s string) bool {
    val, _ := strconv.Atoi(s)
    return val % t.k == 0
}

func (t* solution3273) ifVisited(s string) bool {
    array := strings.Split(s, "")
    sort.Strings(array)
    s = strings.Join(array, "")
    if t.visited[s] {
        return true
    }
    t.visited[s] = true
    return false
}

func (t* solution3273) calc(s string) (ans int64) {
    times := [10]int{}
    for i, _ := range s {
        times[s[i] - '0']++
    }
    ans = int64(t.n - times[0]) * int64(t.factor[t.n - 1])
    for _, v := range times {
        ans /= int64(t.factor[v])
    }
    return
}

func (t* solution3273) getFullS(prefix string) string {
    suffix := []byte(prefix)
    if t.n % 2 == 1 {
        suffix = suffix[:len(suffix) - 1]
    }
    for i := 0; i < len(suffix) / 2; i++ {
        suffix[i], suffix[len(suffix) - i - 1] = suffix[len(suffix) - i - 1], suffix[i]
    }
    return prefix + string(suffix)
}

func countGoodIntegers(n int, k int) (ans int64) {
    solution := init3273(n, k)
    from := int(math.Pow10((n - 1) / 2))
    to := from * 10
    for i := from; i < to; i++ {
        s := solution.getFullS(strconv.Itoa(i))
        if solution.isOk(s) && !solution.ifVisited(s) {
            ans += solution.calc(s)
        }
    }
    return
}