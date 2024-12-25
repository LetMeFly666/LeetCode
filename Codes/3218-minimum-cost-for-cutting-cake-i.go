/*
 * @Author: LetMeFly
 * @Date: 2024-12-25 20:44:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-25 20:56:44
 */
package main

func min_CFCC(a, b int) int {
    if a <= b {
        return a
    }
    return b
}

func minimumCost(m int, n int, horizontalCut []int, verticalCut []int) int {
    cache := make([][][][]int, m)  // [m][m + 1][n][n + 1]
    for i := range cache {
        cache[i] = make([][][]int, m + 1)
        for j := range cache[i] {
            cache[i][j] = make([][]int, n)
            for k := range cache[i][j] {
                cache[i][j][k] = make([]int, n + 1)
            }
        }
    }
    var dfs func(int, int, int, int) int
    dfs = func(ia, ib, ja, jb int) int {
        if cache[ia][ib][ja][jb] > 0 || (ia == ib - 1 && ja == jb - 1) {
            return cache[ia][ib][ja][jb]
        }
        ans := 1000000000
        for ic := ia + 1; ic < ib; ic++ {
            ans = min_CFCC(ans, horizontalCut[ic - 1] + dfs(ia, ic, ja, jb) + dfs(ic, ib, ja, jb))
        }
        for jc := ja + 1; jc < jb; jc++ {
            ans = min_CFCC(ans, verticalCut[jc - 1] + dfs(ia, ib, ja, jc) + dfs(ia, ib, jc, jb))
        }
        cache[ia][ib][ja][jb] = ans
        return ans
    }
    return dfs(0, m, 0, n)
}