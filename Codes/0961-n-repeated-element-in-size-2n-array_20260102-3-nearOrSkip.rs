/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 18:06:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 18:06:56
 */
use std::collections::HashSet;

impl Solution {
    pub fn repeated_n_times(mut nums: Vec<i32>) -> i32 {
        for i in 2..nums.len() {
            if nums[i] == nums[i - 1] || nums[i] == nums[i - 2] {
                return nums[i]
            }
        }
        nums[0]
    }
}