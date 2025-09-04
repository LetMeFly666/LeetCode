/*
 * @Author: LetMeFly
 * @Date: 2025-09-04 13:33:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-04 13:40:19
 */
impl Solution {
    pub fn find_closest(x: i32, y: i32, z: i32) -> i32 {
        let diff: i32 = (x - z).abs() - (y - z).abs();
        if diff == 0 {
            return 0;  // 这里必须带上return
        } else if diff > 0 {
            return 2;
        }
        1
    }
}