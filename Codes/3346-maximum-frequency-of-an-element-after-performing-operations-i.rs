/*
 * @Author: LetMeFly
 * @Date: 2025-10-30 22:39:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-30 23:16:49
 */
use std::collections::HashMap;
// 这台机器上没有安装过rust，故无IDE语法检查了
impl Solution {
    pub fn max_frequency(nums: mut Vec<i32>, k: i32, num_operations: i32) -> i32 {
        nums.sort();
        let mut frequency = HashMap::new();
        for &t in &nums {
            *frequency.entry(t).or_insert(t) += 1;
        }
        
        let mut ans: i32 = 0;
        let mut l: usize = 0;
        let mut r: usize = 0;
        for target in nums[0]..=nums[nums.len()-1] {
            while target - nums[l] > k {
                l += 1;
            }
            while r < nums.len() && nums[r] - target <= k {
                r += 1;
            }
            ans = ans.max((r - l) as i32.min(num_operations + *frequency.get(&target).unwrap_or(&0)));
        }
        ans
    }
}