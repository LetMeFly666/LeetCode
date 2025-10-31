/*
 * @Author: LetMeFly
 * @Date: 2025-10-31 22:33:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-31 22:39:35
 */
use std::collections::HashSet;

impl Solution {
    pub fn get_sneaky_numbers(nums: Vec<i32>) -> Vec<i32> {
        let mut se = HashSet::new();
        let mut ans = Vec::with_capacity(2);
        for t in nums {
            if se.contains(&t) {
                ans.push(t);
            } else {
                se.insert(t);
            }
        }
        ans
    }
}