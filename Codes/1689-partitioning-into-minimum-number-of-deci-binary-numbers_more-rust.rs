/*
 * @Author: LetMeFly
 * @Date: 2026-03-01 19:50:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-01 20:26:52
 */
impl Solution {
    pub fn min_partitions(n: String) -> i32 {
        (*n.as_bytes().iter().max().unwrap() - b'0') as i32
    }
}