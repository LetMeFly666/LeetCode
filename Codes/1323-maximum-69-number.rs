/*
 * @Author: LetMeFly
 * @Date: 2025-08-16 10:17:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-16 10:48:36
 */
impl Solution {
    pub fn maximum69_number (num: i32) -> i32 {
        num.to_string().replacen("6", "9", 1).parse().unwrap()
    }
}