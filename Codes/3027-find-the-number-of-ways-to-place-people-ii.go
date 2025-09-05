/*
 * @Author: LetMeFly
 * @Date: 2025-09-05 09:55:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-05 10:40:12
 */
package main

import "sort"

func numberOfPairs(points [][]int) (ans int) {
    sort.Slice(points, func(i int, j int) bool {
        if points[i][0] == points[j][0] {
            return points[i][1] > points[j][1]
        }
        return points[i][0] < points[j][0]
    })
    for i := range points {
        mxY := -1000000001
        for j := i + 1; j < len(points); j++ {
            if points[j][1] > mxY && points[j][1] <= points[i][1] {
                mxY = points[j][1]
                ans++
            }
        }
    }
    return
}