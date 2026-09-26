/*
 * @Author: LetMeFly
 * @Date: 2026-09-24 12:11:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-24 12:27:08
 */
impl Solution {
    pub fn remove_covered_intervals(mut intervals: Vec<Vec<i32>>) -> i32 {
        intervals.sort_by_key(|x| (x[0], -x[1]));
        let mut ans = intervals.len() as i32;
        let mut maxr = -1;
        for p in intervals.iter() {
            if maxr >= p[1] {
                ans -= 1;
            } else {
                maxr = p[1];
            }
        }
        ans
    }
}
