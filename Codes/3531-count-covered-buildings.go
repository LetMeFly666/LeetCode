/*
 * @Author: LetMeFly
 * @Date: 2025-12-11 13:14:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-11 13:35:38
 */
package main

func countCoveredBuildings(n int, buildings [][]int) (ans int) {
    n++
    xm := make([]int, n)
    xM := make([]int, n)
    ym := make([]int, n)
    yM := make([]int, n)
    for i := range xm {
        xm[i] = n
        ym[i] = n
    }

    for _, building := range buildings {
        x, y := building[0], building[1]
        xm[x] = min(xm[x], y)
        xM[x] = max(xM[x], y)
        ym[y] = min(ym[y], x)
        yM[y] = max(yM[y], x)
    }

    for _, building := range buildings {
        x, y := building[0], building[1]
        if xm[x] < y && y < xM[x] && ym[y] < x && x < yM[y] {
            ans++
        }
    }
    return
}