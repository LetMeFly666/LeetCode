/*
 * @Author: LetMeFly
 * @Date: 2025-10-14 20:14:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-14 20:37:25
 */
impl Solution {
    fn is_ok(nums: &[i32], i: i32, k: i32) -> bool {
        for i in i..i+k-1 {
            if nums[i as usize] >= nums[(i + 1) as usize] {
                return false
            }
        }
        true
    }

    pub fn has_increasing_subarrays(nums: Vec<i32>, k: i32) -> bool {
        for i in 0..nums.len()+1-(2*k) as usize {
            if Self::is_ok(&nums, i as i32, k) && Self::is_ok(&nums, i as i32 + k, k) {
                return true
            }
        }
        false
    }
}