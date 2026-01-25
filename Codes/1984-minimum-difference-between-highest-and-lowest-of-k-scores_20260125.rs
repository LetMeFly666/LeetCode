/*
 * @Author: LetMeFly
 * @Date: 2026-01-25 10:32:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-25 10:43:39
 */
impl Solution {
    pub fn minimum_difference(mut nums: Vec<i32>, k: i32) -> i32 {
        let k = k as usize;
        let mut ans = 100000;
        nums.sort();
        for i in 0..nums.len() - k + 1 {
            ans = ans.min(nums[i + k - 1] - nums[i]);
        }
        ans
    }
}