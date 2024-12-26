/*
 * @Author: LetMeFly
 * @Date: 2024-12-26 15:45:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-26 15:47:44
 */
package main

func isSubstringPresent(s string) bool {
    var visited [26][26]bool
    for i := 1; i < len(s); i++ {
        visited[s[i - 1] - 'a'][s[i] - 'a'] = true
        if visited[s[i] - 'a'][s[i - 1] - 'a'] {
            return true
        }
    }
    return false
}