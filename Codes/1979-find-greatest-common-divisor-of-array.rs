/*
 * @Author: LetMeFly
 * @Date: 2026-07-18 07:00:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-18 07:14:49
 */
// THIS CANNOT BE ACCPETED
impl Solution {
    pub fn find_gcd(nums: Vec<i32>) -> i32 {
        let mut m: i32 = nums[0];
        let mut M: i32 = m;
        for t in nums.iter() {
            m = m.min(t);
            M = M.max(t);
        }
        Self::gcd(M, m)
    }

    fn gcd(a: i32, b: i32) -> i32 {
        if b == 0 {
            a
        } else {
            Self::gcd(b, a % b)
        }
    }
}
