/*
 * @Author: LetMeFly
 * @Date: 2025-09-08 23:05:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-08 23:22:39
 */
impl Solution {
    fn ok(mut n: i32) -> bool {
        while n > 0 {
            if n % 10 == 0 {
                return false;
            }
            n /= 10
        }
        true
    }
    
    pub fn get_no_zero_integers(n: i32) -> Vec<i32> {
        for i in 1..n {
            if Solution::ok(i) && Solution::ok(n - i) {
                return vec![i, n - i];
            }
        }
        vec![]
    }
}