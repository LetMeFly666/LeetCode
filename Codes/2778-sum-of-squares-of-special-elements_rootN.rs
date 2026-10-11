/*
 * @Author: LetMeFly
 * @Date: 2026-10-11 09:11:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-11 09:36:12
 */
impl Solution {
    pub fn sum_of_squares(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let n = nums;
        let root = (n as f64).sqrt() as usize;
        for i in 1..=root {
            if n % i == 0 {
                ans += nums[i - 1] * nums[i - 1];
                if i * i != n {
                    ans += nums[n / i - 1] * nums[n / i - 1];
                }
            }
        }
        ans
    }
}
