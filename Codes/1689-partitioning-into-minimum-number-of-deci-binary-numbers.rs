/*
 * @Author: LetMeFly
 * @Date: 2026-03-01 19:50:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-01 20:23:19
 */
impl Solution {
    pub fn min_partitions(n: String) -> i32 {
        let mut m = '0';
        for c in n.chars() {
            if c > m {
                m = c;
            }
        }
        (m as i32) - ('0' as i32)
    }
}