/*
 * @Author: LetMeFly
 * @Date: 2025-01-07 13:11:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-07 13:13:25
 */
package main
import "strings"

func countKeyChanges(s string) (ans int) {
    for i := 1; i < len(s); i++ {
        if strings.ToLower(string(s[i])) != strings.ToLower(string(s[i - 1])) {
            ans++
        }
    }
    return
}