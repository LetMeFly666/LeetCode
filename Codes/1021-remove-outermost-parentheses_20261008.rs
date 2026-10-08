/*
 * @Author: LetMeFly
 * @Date: 2026-10-08 08:52:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-08 09:30:19
 */
impl Solution {
    pub fn remove_outer_parentheses(s: String) -> String {
        let mut ans = String::new();
        let mut layer = 0;
        for c in s.chars() {
            if c == b'(' {
                if layer != 0 {
                    ans.push(c);
                }
                layer += 1;
            } else {
                layer -= 1;
                if layer != 0 {
                    ans.push(c);
                }
            }
        }
        ans
    }
}
