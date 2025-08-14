/*
 * @Author: LetMeFly
 * @Date: 2025-08-14 10:28:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-14 18:45:31
 */
impl Solution {
    pub fn check_powers_of_three(mut n: i32) -> bool {
        while n > 0 {
            if n % 3 == 2 {
                return false;
            }
            n /= 3;
        }
        return true;
    }
}