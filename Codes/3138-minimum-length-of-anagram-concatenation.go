/*
 * @Author: LetMeFly
 * @Date: 2024-12-20 21:16:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-20 21:20:42
 */
package main

func count(s string, l, r int) []int {
    ans := make([]int, 26)
    for i := l; i < r; i++ {
        ans[s[i] - 'a']++
    }
    return ans
}

func same26(a, b []int) bool {
    for i := range a {
        if a[i] != b[i] {
            return false;
        }
    }
    return true;
}

func minAnagramLength(s string) int {
    for ans := 1; ans < len(s); ans++ {
        if len(s) % ans != 0 {
            continue
        }
        should := count(s, 0, ans)
        ok := true
        for i := ans; i < len(s); i += ans {
            if !same26(should, count(s, i, i + ans)) {
                ok = false
                break
            }
        }
        if ok {
            return ans
        }
    }
    return len(s)
}