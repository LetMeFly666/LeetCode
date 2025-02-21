/*
 * @Author: LetMeFly
 * @Date: 2025-02-21 13:06:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-21 14:21:55
 */
package main

func dfs_MWTACWC(n, startIndex int, floor string, perLen int, cache map[int]int) (ans int) {
    code := n * 1000 + startIndex
    ans, ok := cache[code]
    if ok {
        return
    }
    if n * perLen >= len(floor) - startIndex {
        cache[code] = 0
        return 0
    }
    ans = dfs_MWTACWC(n, startIndex + 1, floor, perLen, cache)
    if floor[startIndex] == '1' {
        ans++
    }
    if n > 0 {
        ans = min(ans, dfs_MWTACWC(n - 1, startIndex + perLen, floor, perLen, cache))
    }
    cache[code] = ans
    return
}

func minimumWhiteTiles(floor string, numCarpets int, carpetLen int) int {
    return dfs_MWTACWC(numCarpets, 0, floor, carpetLen, map[int]int{})
}