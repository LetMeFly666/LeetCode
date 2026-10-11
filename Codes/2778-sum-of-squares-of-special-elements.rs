/*
 * @Author: LetMeFly
 * @Date: 2026-10-11 09:02:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-11 09:08:39
 */
impl Solution {
    pub fn sum_of_squares(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let n = nums.len();
        for i in 0..n {
            if n % (i + 1) == 0 {
                ans += nums[i] * nums[i];
            }
        }
        ans
    }
}
