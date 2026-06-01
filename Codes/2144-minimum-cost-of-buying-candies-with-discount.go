/*
 * @Author: LetMeFly
 * @Date: 2026-06-01 22:06:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-01 22:10:30
 */
package main

import "sort"

func minimumCost(cost []int) (ans int) {
	sort.Ints(cost);
	for i, cnt := len(cost) - 1, 0; i >= 0; i-- {
		if cnt == 2 {
			cnt = 0
		} else {
			ans += cost[i];
			cnt++
		}
	}
	return
}
