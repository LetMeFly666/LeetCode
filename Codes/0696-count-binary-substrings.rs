/*
 * @Author: LetMeFly
 * @Date: 2026-02-19 11:16:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-19 11:25:31
 */
impl Solution {
    pub fn count_binary_substrings(s: String) -> i32 {
        let mut ans = 0;
        let mut cnt = 1;
        let mut lastCnt = 0;
        for i in 1..(s.len() + 1) {
            if i == s.len() || s[i] != s[i - 1] {
                ans += cnt.min(lastCnt);
                lastCnt = cnt;
                cnt = 0;
            }
            cnt += 1;
        }
        ans
    }
}