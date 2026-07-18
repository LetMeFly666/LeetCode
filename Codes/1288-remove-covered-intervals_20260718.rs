/*
 * @Author: LetMeFly
 * @Date: 2026-07-18 07:44:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-18 07:57:42
 */
impl Solution {
    pub fn remove_covered_intervals(mut intervals: Vec<Vec<i32>>) -> i32 {
        intervals.sort_by_key((x) |x[0], -x[1]|);
        let mut ans: i32 = intervals.len();
        let mut maxr = 0;
        for v in intervals.iter() {
            if v[1] <= maxr {
                ans -= 1;
            } else {
                maxr = v[1];
            }
        }
        ans
    }
}
