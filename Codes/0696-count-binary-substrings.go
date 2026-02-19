/*
 * @Author: LetMeFly
 * @Date: 2026-02-19 11:16:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-19 11:31:44
 */
package main

func countBinarySubstrings(s string) (ans int) {
    lastCnt, cnt := 0, 1
    for i := 1; i <= len(s); i++ {
        if i == len(s) || s[i] != s[i - 1] {
            ans += min(lastCnt, cnt);
            lastCnt = cnt;
            cnt = 0;
        }
        cnt++;
    }
    return;
}