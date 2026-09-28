/*
 * @Author: LetMeFly
 * @Date: 2026-09-28 08:10:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-28 10:09:31
 */
impl Solution {
    pub fn max_depth(s: String) -> i32 {
        let mut ans = 0;
        let mut layer = 0;
        for c in s.chars() {
            if c == '(' {
                layer += 1;
                ans = ans.max(layer);
            } else if c == ')' {
                layer -= 1;
            }
        }
        ans
    }
}
