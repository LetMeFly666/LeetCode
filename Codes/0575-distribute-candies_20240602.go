/*
 * @Author: LetMeFly
 * @Date: 2024-06-02 09:45:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-02 09:57:46
 */
package main

func min(a int, b int) int {
    if a <= b {
        return a
    }
    return b
}

func distributeCandies(candyType []int) int {
    se := make(map[int]int)
    for _, t := range candyType {
        se[t] = 0
    }
    return min(len(se), len(candyType) / 2)
}