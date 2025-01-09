/*
 * @Author: LetMeFly
 * @Date: 2025-01-09 12:52:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-09 13:10:20
 */
package main

// import "fmt"

func ok(a, b []int) bool {
    for i := range a {
        if a[i] < b[i] {
            return false
        }
    }
    return true
}

func validSubstringCount(word1 string, word2 string) (ans int64) {
    cnt1, cnt2 := make([]int, 26), make([]int, 26)
    for _, c := range word2 {
        cnt2[c - 'a']++
    }
    // fmt.Println(cnt2)
    for l, r := 0, 0; l < len(word1); l++ {
        if l > 0 {
            cnt1[word1[l - 1] - 'a']--
        }
        for !ok(cnt1, cnt2) {
            if r == len(word1) {
                return
            }
            cnt1[word1[r] - 'a']++
            r++
        }
        // fmt.Println(cnt1)
        // fmt.Println(r)
        ans += int64(len(word1) - r + 1)
    }
    return
}