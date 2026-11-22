/*
 * @Author: LetMeFly
 * @Date: 2026-11-22 09:57:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-22 10:01:32
 */
impl Solution {
    pub fn check_string(s: String) -> bool {
        let n = s.len();
        for i in 1..n {
            if s[i - 1] == 'b' && s[i] == 'a' {
                return false
            }
        }
        true
    }
}
