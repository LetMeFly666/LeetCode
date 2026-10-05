/*
 * @Author: LetMeFly
 * @Date: 2026-10-05 16:38:39
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-05 16:46:40
 */
impl Solution {
    pub fn score_of_parentheses(s: String) -> i32 {
        let mut ans = 0;
        let mut layer = 0;
        for i in 0..s.len() {
            if s[i] == '(' {
                layer += 1;
            } else {
                layer -= 1;
                if s[i - 1] == '(' {
                    ans += 1 << layer;
                }
            }
        }
        ans
    }
}
