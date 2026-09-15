/*
 * @Author: LetMeFly
 * @Date: 2026-09-15 17:12:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-15 17:29:56
 */
impl Solution {
    pub fn remove_covered_intervals(mut intervals: Vec<Vec<i32>>) -> i32 {
        intervals.sort(|i, j| {
            if intervals[i][0] == intervals[j][0] {
                intervals[i][1] > intervals[j][1]
            } else {
                intervals[i][0] < intervals[j][0]
            }
        });
        let mut ans = intervals.len() as i32;
        let mut maxr = -1;
        for p in intervals.iter() {
            if p[1] <= maxr {
                ans -= 1;
            } else {
                maxr = p[1];
            }
        }
        ans
    }
}
