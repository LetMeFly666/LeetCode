/*
 * @Author: LetMeFly
 * @Date: 2026-02-19 11:16:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-19 11:27:37
 */
impl Solution {
    pub fn count_binary_substrings(s: String) -> i32 {
        let s = s.as_bytes();  // the type `str` cannot be indexed by `usize`
        let mut ans = 0;
        let mut cnt = 1;
        let mut last_cnt = 0;
        for i in 1..(s.len() + 1) {
            if i == s.len() || s[i] != s[i - 1] {
                ans += cnt.min(last_cnt);
                last_cnt = cnt;
                cnt = 0;
            }
            cnt += 1;
        }
        ans
    }
}