/*
 * @Author: LetMeFly
 * @Date: 2026-11-22 09:57:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-22 10:04:09
 */
impl Solution {
    pub fn check_string(s: String) -> bool {
        let n = s.len();
        let s = s.as_bytes();
        for i in 1..n {
            if s[i - 1] == b'b' && s[i] == b'a' {
                return false
            }
        }
        true
    }
}
