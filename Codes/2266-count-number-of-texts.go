/*
 * @Author: LetMeFly
 * @Date: 2025-01-19 14:21:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-19 14:55:32
 */
package main

const mod int = 1000000007
var dp3 = [100001]int{1, 1, 2, 4}
var dp4 = dp3

func init() {
    for i := 4; i <= 100000; i++ {
        dp3[i] = ((dp3[i- 1] + dp3[i - 2]) % mod + dp3[i - 3]) % mod;
        dp4[i] = (((dp4[i - 1] + dp4[i - 2]) % mod + dp4[i - 3]) % mod + dp4[i - 4]) % mod;
    }
}

func countTexts(pressedKeys string) int {
    ans := int64(1)
    cnt := 0
    for i, c := range pressedKeys {
        cnt++
        if i == len(pressedKeys) - 1 || byte(c) != pressedKeys[i + 1] {
            if c == '7' || c == '9' {
                ans = ans * int64(dp4[cnt]) % int64(mod)
            } else {
                ans = ans * int64(dp3[cnt]) % int64(mod)
            }
            cnt = 0
        }
    }
    return int(ans)
}