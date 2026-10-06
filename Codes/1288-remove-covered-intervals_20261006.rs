/*
 * @Author: LetMeFly
 * @Date: 2026-10-06 11:45:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-06 11:57:48
 */
impl Solution {
    pub fn remove_covered_intervals(intervals: Vec<Vec<i32>>) -> i32 {
        intervals.sort_by_key(x |x[0], -x[1]|)
    }
}
