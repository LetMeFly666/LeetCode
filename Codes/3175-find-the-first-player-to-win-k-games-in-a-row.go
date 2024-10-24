/*
 * @Author: LetMeFly
 * @Date: 2024-10-24 12:25:07
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-24 12:26:09
 */
package main

func findWinningPlayer(skills []int, k int) int {
    maxLoc := 0
    for curLoc, cnt := 1, 0; curLoc < len(skills) && cnt < k; curLoc++ {
        if skills[maxLoc] > skills[curLoc] {
            cnt++;
        } else {
            maxLoc = curLoc
            cnt = 1
        }
    }
    return maxLoc
}