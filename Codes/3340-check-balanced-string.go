/*
 * @Author: LetMeFly
 * @Date: 2025-03-14 09:36:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-14 09:38:01
 */
package main

func isBalanced(num string) bool {
    cnt := 0
    for i, c := range num {
        if i % 2 == 0 {
            cnt += int(c) - 48
        } else {
            cnt -= int(c) - 48
        }
    }
    return cnt == 0
}