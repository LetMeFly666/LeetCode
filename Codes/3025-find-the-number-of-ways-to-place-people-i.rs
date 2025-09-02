/*
 * @Author: LetMeFly
 * @Date: 2025-09-02 20:09:04
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-02 20:26:39
 */
impl Solution {
    fn check2(points: &Vec<Vec<i32>>, i: usize, j: usize) -> bool {
        points[i][0] <= points[j][0] && points[i][1] >= points[j][1]
    }

    fn check3(points: &Vec<Vec<i32>>, i: usize, j: usize, k: usize) -> bool {
        !(points[i][0] <= points[k][0] && points[k][0] <= points[j][0] && points[i][1] >= points[k][1] && points[k][1] >= points[j][1])
    }
    pub fn number_of_pairs(points: Vec<Vec<i32>>) -> i32 {
        let mut ans: i32 = 0;
        let n = points.len();
        for i in 0..n {
            for j in 0..n {
                if i == j {
                    continue;
                }
                if !Self::check2(&points, i, j) {
                    continue;
                }
                let mut can: bool = true;
                for k in 0..n {
                    if k == i || k == j {
                        continue;
                    }
                    if !Self::check3(&points, i, j, k) {
                        can = false;
                        break;
                    }
                }
                if can {
                    ans += 1;
                }
            }
        }
        ans
    }
}