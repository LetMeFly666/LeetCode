/*
 * @Author: LetMeFly
 * @Date: 2026-10-23 20:28:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-23 20:39:42
 */
impl Solution {
    pub fn sort_permutation(nums: Vec<i32>) -> i32 {
        if nums[0] != 0 {
            return 0;
        }
        let mut ans = -1;
        for (i, &t) in nums.iter().enumerate() {
            if t != i as i32 {
                ans &= i as i32;
            }
        }
        ans.max(0)
    }
}
