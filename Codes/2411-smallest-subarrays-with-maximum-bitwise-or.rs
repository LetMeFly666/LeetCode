/*
 * @Author: LetMeFly
 * @Date: 2025-07-29 23:42:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-30 21:00:40
 */
use std::cmp::max;

impl Solution {
    pub fn smallest_subarrays(nums: Vec<i32>) -> Vec<i32> {
        let mut ans: Vec<i32> = vec![0; nums.len()];
        let mut lastPos: Vec<i32> = vec![0; 31];
        for i in (0..ans.len()).rev() {
            let ii32: i32 = i.try_into().unwrap();
            let mut last: i32 = ii32;
            for j in (0..31) {
                if nums[i] >> j & 1 == 1 {
                    lastPos[j] = ii32;
                } else {
                    last = max(last, lastPos[j])
                }
            }
            ans[i] = max(ans[i], last - ii32 + 1)
        }
        ans
    }
}