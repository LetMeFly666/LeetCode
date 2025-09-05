/*
 * @Author: LetMeFly
 * @Date: 2025-09-05 09:55:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-05 10:49:59
 */
impl Solution {
    pub fn number_of_pairs(mut points: Vec<Vec<i32>>) -> i32 {  // 想原地sort points的话记得在points前面加上mut
        points.sort_by(|a, b| {
            if a[0] == b[0] {
                b[1].cmp(&a[1])
            } else {
                a[0].cmp(&b[0])
            }
        });
        let mut ans: i32 = 0;
        for i in 0..points.len() {
            let mut mx_y: i32 = -1000000001;
            for j in (i+1)..points.len() {
                if points[j][1] > mx_y && points[j][1] <= points[i][1] {
                    mx_y = points[j][1];
                    ans += 1;
                }
            }
        }
        ans
    }
}