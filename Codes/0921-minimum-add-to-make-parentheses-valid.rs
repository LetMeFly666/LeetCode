/*
 * @Author: LetMeFly
 * @Date: 2026-10-06 11:26:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-06 11:34:11
 */
impl Solution {
    pub fn min_add_to_make_valid(s: String) -> i32 {
        let mut ans = 0;
        let mut diff = 0;
        for c in s.bytes() {
            if c == b'(' {
                diff += 1;
            } else if diff > 0 {
                diff -= 1;
            } else {
                ans += 1;
            }
        }
        ans + diff
    }
}
