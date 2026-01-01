/*
 * @Author: LetMeFly
 * @Date: 2026-01-01 15:40:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-01 16:06:45
 */
impl Solution {
    pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {
        let mut cnt: i32 = 1;
        for i in (0..digits.len()).rev() {
            digits[i] += cnt;
            cnt = digits[i] / 10;
            digits[i] %= 10;
        }
        if cnt > 0 {
            digits.insert(0, cnt);
        }
        digits
    }
}