/*
 * @Author: LetMeFly
 * @Date: 2025-09-26 22:40:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-26 22:56:15
 */
impl Solution {
    pub fn triangle_number(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let mut ans: usize = 0;
        for i in nums.len()-1..=0 {
            let mut l: usize = 0;
            let mut r: usize = i - 1;
            while l < r {
                if nums[l] + nums[r] > nums[i] {
                    ans += r - l;
                    r -= 1;
                } else {
                    l += 1;
                }
            }
        }
        ans as i32
    }
}