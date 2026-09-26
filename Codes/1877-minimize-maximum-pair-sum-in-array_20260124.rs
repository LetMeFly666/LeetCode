/*
 * @Author: LetMeFly
 * @Date: 2026-01-24 09:29:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-24 09:37:33
 */
impl Solution {
    pub fn min_pair_sum(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let mut ans = 0;
        for i in 0..nums.len() / 2 {
            ans = ans.max(nums[i] + nums[nums.len() - i - 1]);
        }
        ans
    }
}