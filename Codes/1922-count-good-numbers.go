/*
 * @Author: LetMeFly
 * @Date: 2025-04-13 17:54:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-14 00:05:17
 * @Description: continue on subway，太晃了还是先算了
 * @Description: AC,100.00%,63.16%
 */
package main

var MOD1922 = int64(1000000007)

func pow1922(a int64, b int64) int64 {
	ans := int64(1)
	for ; b > 0; b >>= 1 {
		if b & 1 == 1 {
			ans = ans * a % MOD1922
		}
		a = a * a % MOD1922
	}
	return ans
}

func countGoodNumbers(n int64) int {
    return int(pow1922(5, (n + 1) / 2) * pow1922(4, n / 2) % MOD1922)
}