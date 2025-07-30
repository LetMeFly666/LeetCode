/*
 * @Author: LetMeFly
 * @Date: 2025-07-29 23:42:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-30 20:44:21
 */
use std::cmp::max;

impl Solution {
    pub fn smallest_subarrays(nums: Vec<i32>) -> Vec<i32> {
        let mut ans: Vec<i32> = vec![0; nums.len()];
        let mut lastPos: Vec<i32> = vec![0; 31];
        for i in (0..ans.len()).rev() {
            let mut last: i32 = i;
            for j in (0..32) {
                if nums[i] >> j & 1 == 1 {
                    lastPos[j] = i;
                } else {
                    last = max(last, lastPos[j])
                }
            }
            ans[i] = max(ans[i], last - i + 1)
        }
        ans
    }
}
