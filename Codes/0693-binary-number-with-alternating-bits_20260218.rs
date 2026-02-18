/*
 * @Author: LetMeFly
 * @Date: 2026-02-18 14:51:23
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-18 14:59:11
 */
impl Solution {
    pub fn has_alternating_bits(n: i32) -> bool {
        let x: usize = ((n >> 1) ^ n )as usize;
        (x & (x + 1)) == 0
    }
}