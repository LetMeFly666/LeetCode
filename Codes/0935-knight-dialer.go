/*
 * @Author: LetMeFly
 * @Date: 2024-12-10 15:29:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-10 15:39:22
 */
package main

var canFrom = [][]int{
    {4, 6},  // 0可以来自4，6
    {6, 8},
    {7, 9},
    {4, 8},
    {3, 9, 0},
    {},
    {1, 7, 0},
    {2, 6},
    {1, 3},
    {2, 4},
};
var mod = 1000000007

func knightDialer(n int) (ans int) {
    last := make([]int, 10)
    for i := range last {
        last[i] = 1
    }
    for i := 2; i <= n; i++ {
        now := make([]int, 10)
        for j := 0; j < 10; j++ {
            for _, from := range canFrom[j] {
                now[j] = (now[j] + last[from]) % mod
            }
        }
        last = now
    }
    for i := range last {
        ans = (ans + last[i]) % mod;
    }
    return
}