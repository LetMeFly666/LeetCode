/*
 * @Author: LetMeFly
 * @Date: 2025-08-09 22:23:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-09 22:38:51
 */
impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        n > 0 && n & (n - 1) == 0
    }
}