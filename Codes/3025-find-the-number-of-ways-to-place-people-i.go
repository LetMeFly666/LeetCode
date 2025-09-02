/*
 * @Author: LetMeFly
 * @Date: 2025-09-02 13:08:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-02 18:53:07
 */
package main

func check2_3025(points [][]int, i, j int) bool {
    return points[i][0] <= points[j][0] && points[i][1] >= points[j][1]
}

func check3_3025(points [][]int, i, j, k int) bool {
    return !(points[i][0] <= points[k][0] && points[k][0] <= points[j][0] &&
             points[i][1] >= points[k][1] && points[k][1] >= points[j][1])
}

func numberOfPairs(points [][]int) (ans int) {
    for i := range points {
        for j := range points {
            if i == j {
                continue
            }
            if !check2_3025(points, i, j) {
                continue
            }
            can := true
            for k := range points {
                if k == i || k == j {
                    continue
                }
                if !check3_3025(points, i, j, k) {
                    can = false
                    break
                }
            }
            if can {
                ans++
            }
        }
    }
    return
}