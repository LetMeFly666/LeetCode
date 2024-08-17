/*
 * @Author: LetMeFly
 * @Date: 2024-08-17 17:11:44
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-17 17:16:56
 */
package main

func minimumOperationsToMakeKPeriodic(word string, k int) int {
    maxTimes := 1
    ma := map[string]int{}
    for i := 0; i < len(word); i += k {
        ma[word[i: i + k]]++
        maxTimes = max(maxTimes, ma[word[i: i + k]])
    }
    return len(word) / k - maxTimes
}