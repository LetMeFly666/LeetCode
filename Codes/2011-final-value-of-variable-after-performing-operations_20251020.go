/*
 * @Author: LetMeFly
 * @Date: 2025-10-20 18:44:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-20 18:48:49
 */
package main

func finalValueAfterOperations(operations []string) (ans int) {
    for _, op := range operations {
        if op[1] == '+' {
            ans++;
        } else {
            ans--
        }
    }
    return
}