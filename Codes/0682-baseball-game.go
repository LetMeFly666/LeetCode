/*
 * @Author: LetMeFly
 * @Date: 2024-07-29 22:50:55
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-29 22:54:41
 */
package main

import "strconv"

func calPoints(operations []string) int {
    score := []int{}
    for _, op := range operations {
        switch op[0] {
        case '+':
            score = append(score, score[len(score) - 1] + score[len(score) - 2])
        case 'D':
            score = append(score, score[len(score) - 1] * 2)
        case 'C':
            score = score[:len(score) - 1]
        default:
            t, _ := strconv.Atoi(op)
            score = append(score, t)
        }
    }
    ans := 0
    for _, t := range score {
        ans += t
    }
    return ans
}