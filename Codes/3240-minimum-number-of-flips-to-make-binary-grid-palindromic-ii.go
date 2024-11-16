/*
 * @Author: LetMeFly
 * @Date: 2024-11-16 13:35:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-16 13:46:43
 */
package main

func minFlips(grid [][]int) (ans int) {
    n, m := len(grid), len(grid[0])
    for i := 0; i < n / 2; i++ {
        for j := 0; j < m / 2; j++ {
            cnt1 := grid[i][j] + grid[i][m - j - 1] + grid[n - i - 1][j] + grid[n - i - 1][m - j - 1]
            ans += min(cnt1, 4 - cnt1)
        }
    }
    if n % 2 == 1 && m % 2 == 1 {
        ans += grid[n / 2][m / 2]
    }
    cnt11, cnt1001 := 0, 0
    if n % 2 == 1 {
        for j := 0; j < m / 2; j++ {
            if grid[n / 2][j] == grid[n / 2][m - j - 1] {
                if grid[n / 2][j] == 1 {
                    cnt11++
                }
            } else {
                cnt1001++
            }
        }
    }
    if m % 2 == 1 {
        for i := 0; i < n / 2; i++ {
            if grid[i][m / 2] == grid[n - i - 1][m / 2] {
                if (grid[i][m / 2] == 1) {
                    cnt11++
                }
            } else {
                cnt1001++
            }
        }
    }
    ans += cnt1001
    if cnt11 % 2 == 1 && cnt1001 == 0 {
        ans +=2
    }
    return
}