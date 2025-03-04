/*
 * @Author: LetMeFly
 * @Date: 2025-03-04 10:42:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-04 10:46:32
 */
package main

func checkPartitioning(s string) bool {
    n := len(s)
    isok := make([][]bool, n)
    for i, _ := range isok {
        isok[i] = make([]bool, n)
        for j, _ := range isok[i] {
            isok[i][j] = true
        }
    }
    for i := n - 1; i >= 0; i-- {
        for j := i + 1; j < n; j++ {
            isok[i][j] = s[i] == s[j] && isok[i + 1][j - 1]
        }
    }
    
    for i := 0; i < n; i++ {
        for j := i + 1; j < n - 1; j++ {
            if isok[0][i] && isok[i + 1][j] && isok[j + 1][n - 1] {
                return true
            }
        }
    }
    return false
}