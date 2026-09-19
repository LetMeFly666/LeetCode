/*
 * @Author: LetMeFly
 * @Date: 2026-09-19 08:23:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-19 08:46:21
 */
impl Solution {
    fn get_closest(c: i32, a: i32, b: i32) -> i32 {
        if a > c {
            a
        } else if b < c {
            b
        } else {
            c
        }
    }

    fn p(a: i32) -> i32 {
        a * a
    }

    pub fn check_overlap(radius: i32, x_center: i32, y_center: i32, x1: i32, y1: i32, x2: i32, y2: i32) -> bool {
        let x = Self::get_closest(x_center, x1, x2);
        let y = Self::get_closest(y_center, y1, y2);
        Self::p(x - x_center) + Self::p(y - y_center) <= Self::p(radius)
    }
}
