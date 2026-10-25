/*
 * @Author: LetMeFly
 * @Date: 2026-10-25 09:03:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-25 16:19:59
 */
use std::collections::VecDeque;

impl Solution {
    const DIRS: [(isize, isize); 4] = [(-1, 0), (1, 0), (0, 1), (0, -1)];  // 注意防止usize到-1

    fn is_center(i: usize, j: usize, n: usize, m: usize) -> bool {
        0 < i && i < n - 1 && 0 < j && j < m - 1
    }

    fn in_grid(i: isize, j: isize, n: usize, m: usize) -> bool {
        0 <= i && i < n as isize && 0 <= j && j < m as isize
    }

    pub fn closed_island(mut grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let m = grid[0].len();
        let mut ans = 0;
        for i in 0..n {
            for j in 0..m {
                if grid[i][j] == 1 {
                    continue;
                }
                grid[i][j] = 1;
                let mut ok = Self::is_center(i, j, n, m);
                let mut q = VecDeque::new();
                q.push_back((i, j));
                while let Some((x, y)) = q.pop_front() {
                    for &(dx, dy) in &Self::DIRS {
                        let nx = x as isize + dx;
                        let ny = y as isize + dy;
                        if !Self::in_grid(nx, ny, n, m){
                            continue;
                        }
                        let (nx, ny) = (nx as usize, ny as usize);
                        if grid[nx][ny] == 1 {
                            continue;
                        }
                        grid[nx][ny] = 1;
                        ok &= Self::is_center(nx, ny, n, m);
                        q.push_back((nx, ny));
                    }
                }
                ans += if ok {
                    1
                } else {
                    0
                }
            }
        }
        ans
    }
}
