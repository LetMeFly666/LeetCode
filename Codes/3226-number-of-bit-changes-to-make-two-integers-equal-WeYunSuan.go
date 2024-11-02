/*
 * @Author: LetMeFly
 * @Date: 2024-11-02 11:01:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-02 11:05:41
 */
package main
import "math/bits"

func minChanges(n int, k int) int {
    if n | k == n {
        return bits.OnesCount(uint(n ^ k))
    }
    return -1
}