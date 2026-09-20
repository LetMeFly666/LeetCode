/*
 * @Author: LetMeFly
 * @Date: 2026-09-20 10:25:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-20 10:44:41
 */
impl Solution {
    pub fn reverse_degree(s: String) -> i32 {
        let mut ans = 0;
        for (i, c) in s.chars().enumerate() {
            ans += (i as i32 + 1) * (26 - c as i32 + 'a' as i32);
        }
        ans
    }
}
