/*
 * @Author: LetMeFly
 * @Date: 2024-09-01 14:56:16
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-01 15:02:25
 */
package main

func busyStudent(startTime []int, endTime []int, queryTime int) int {
    ans := 0
    for i := range startTime {
        if startTime[i] <= queryTime && queryTime <= endTime[i] {
            ans++
        }
    }
    return ans
}