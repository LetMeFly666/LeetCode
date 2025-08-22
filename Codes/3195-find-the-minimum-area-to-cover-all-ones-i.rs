/*
 * @Author: LetMeFly
 * @Date: 2025-08-22 21:18:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-22 21:28:08
 */
impl Solution {
    pub fn minimum_area(grid: Vec<Vec<i32>>) -> i32 {
        let mut l: usize = 1000;
        let mut r: usize = 0;
        let mut u: usize = 1000;
        let mut d: usize = 0;
        for (i, row) in grid.into_iter().enumerate() {
            for (j, g) in row.into_iter().enumerate() {
                if g == 1 {
                    l = l.min(j);
                    r = r.max(j);
                    u = u.min(i);
                    d = d.max(i);
                }
            }
        }
        ((r - l + 1) * (d - u + 1)) as i32
    }
}