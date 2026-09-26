/*
 * @Author: LetMeFly
 * @Date: 2026-09-15 17:12:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-15 17:31:44
 */
impl Solution {
    pub fn remove_covered_intervals(mut intervals: Vec<Vec<i32>>) -> i32 {
        intervals.sort_by_key(|x| (x[0], -x[1]));
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
