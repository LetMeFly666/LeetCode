/*
 * @Author: LetMeFly
 * @Date: 2025-03-31 14:45:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-31 15:18:02
 */
package main

func addSpaces(s string, spaces []int) string {
    ans := make([]byte, 0, len(s) + len(spaces))
    j := 0
    for i, c := range s {
        if j < len(spaces) && spaces[j] == i {
            ans = append(ans, ' ')
            j++
        }
        ans = append(ans, byte(c))
    }
    return string(ans)
}