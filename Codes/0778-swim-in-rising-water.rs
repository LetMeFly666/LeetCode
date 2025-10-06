/*
 * @Author: LetMeFly
 * @Date: 2025-10-06 12:17:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-06 14:48:19
 */
use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    const DIRECTIONS: [[i32; 2]; 4] = [[0, 1], [0, -1], [-1, 0], [1, 0]];
    pub fn swim_in_water(grid: Vec<Vec<i32>>) -> i32 {
        let n: usize = grid.len();
        let m: usize = grid[0].len();
        if n == 1 && m == 1 {
            return grid[0][0];
        }
        let mut pq = BinaryHeap::new();
        let mut visited: Vec<Vec<bool>> = vec![vec![false; m]; n];
        pq.push(Reverse((grid[0][0], 0, 0)));
        visited[0][0] = true;

        while let Some(Reverse((val, x, y))) = pq.pop() {
            for &[dx, dy] in Self::DIRECTIONS.iter() {
                let nx: usize = x + dx as usize;
                let ny: usize = y + dy as usize;
                if nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] {
                    continue;
                }
                let n_val: i32 = val.max(grid[nx][ny]);
                if nx == n - 1 && ny == m - 1 {
                    return n_val;
                }
                visited[nx][ny] = true;
                pq.push(Reverse((n_val, nx, ny)));
            }
        }

        -1  // Fake Return
    }
}