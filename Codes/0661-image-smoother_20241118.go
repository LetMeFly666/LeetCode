/*
 * @Author: LetMeFly
 * @Date: 2024-11-18 21:23:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-18 21:35:14
 */
package main

func imageSmoother(img [][]int) (ans [][]int) {
    ans = make([][]int, len(img))
    for i := range ans {
        ans[i] = make([]int, len(img[0]))
        for j := range ans[i] {
            cnt, s := 0, 0
            for _, row := range img[max(0, i - 1):min(len(img), i + 2)] {
                for _, val := range row[max(0, j - 1):min(len(img[0]), j + 2)] {
                    cnt++
                    s += val
                }
            }
            ans[i][j] = s / cnt
        }
    }
    return ans
}