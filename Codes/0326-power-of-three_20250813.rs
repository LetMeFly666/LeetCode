/*
 * @Author: LetMeFly
 * @Date: 2025-08-13 13:17:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-13 13:21:37
 */
impl Solution {
    pub fn is_power_of_three(n: i32) -> bool {
        n > 0 && 1162261467 % n == 0
    }
}