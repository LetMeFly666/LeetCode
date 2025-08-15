/*
 * @Author: LetMeFly
 * @Date: 2025-08-15 18:29:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-15 23:57:22
 */
impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {
        n > 0 && n & (n - 1) == 0 && n % 3 == 1
    }
}