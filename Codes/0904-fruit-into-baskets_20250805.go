/*
 * @Author: LetMeFly
 * @Date: 2025-08-05 10:28:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-06 18:33:14
 */
package main

func totalFruit(fruits []int) (ans int) {
    window := map[int]int{}
    for l, r := 0, 0; r < len(fruits); r++ {
        window[fruits[r]]++
        for len(window) > 2 {
            window[fruits[l]]--
            if window[fruits[l]] == 0 {
                delete(window, fruits[l])
            }
            l++
        }
        ans = max(ans, r - l + 1)
    }
    return
}