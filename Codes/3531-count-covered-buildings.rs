/*
 * @Author: LetMeFly
 * @Date: 2025-12-11 13:14:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-11 13:48:09
 */
impl Solution {
    pub fn count_covered_buildings(mut n: i32, buildings: Vec<Vec<i32>>) -> i32 {
        n += 1;
        let mut xm: Vec<i32> = vec![n; n as usize];
        let mut xM: Vec<i32> = vec![0; n as usize];
        let mut ym: Vec<i32> = vec![n; n as usize];
        let mut yM: Vec<i32> = vec![0; n as usize];

        for building in buildings.iter() {
            let x: i32 = building[0];
            let y: i32 = building[1];
            xm[x as usize] = xm[x as usize].min(y);
            xM[x as usize] = xM[x as usize].max(y);
            ym[y as usize] = ym[y as usize].min(x);
            yM[y as usize] = yM[y as usize].max(x);
        }

        let mut ans: i32 = 0;
        for building in buildings.iter() {
            let x: i32 = building[0];
            let y: i32 = building[1];
            if xm[x as usize] < y && y < xM[x as usize] && ym[y as usize] < x && x < yM[y as usize] {
                ans += 1;
            }
        }
        ans
    }
}