/*
 * @Author: LetMeFly
 * @Date: 2024-11-12 18:14:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-12 18:33:51
 */
package main

func countKConstraintSubstrings(s string, k int) (ans int) {
    cnt := make([]int, 2)
    for l, r := 0, 0; r < len(s); r++ {
        cnt[s[r] - '0']++
        for cnt[0] > k && cnt[1] > k {
            cnt[s[l] - '0']--
            l++
        }
        ans += r - l + 1
    }
    return
}