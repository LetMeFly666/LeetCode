/*
 * @Author: LetMeFly
 * @Date: 2026-01-20 22:50:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-20 23:07:14
 */
impl Solution {
    fn get(n: i32) -> i32 {
        for i in 0..n {
            if (i | (i + 1)) == n {
                return i;
            }
        }
        -1
    }

    pub fn min_bitwise_array(nums: Vec<i32>) -> Vec<i32> {
        nums.iter().map(|&num| Self::get(num)).collect()
    }
}