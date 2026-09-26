/*
 * @Author: LetMeFly
 * @Date: 2026-02-19 17:59:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-19 18:06:07
 */
impl Solution {
    pub fn count_odds(low: i32, high: i32) -> i32 {
        (high + 1) / 2 - low / 2
    }
}