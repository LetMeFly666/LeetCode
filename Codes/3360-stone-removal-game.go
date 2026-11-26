/*
 * @Author: LetMeFly
 * @Date: 2026-11-26 07:52:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-26 08:01:55
 */
package main

func canAliceWin(n int) (state bool) {
	need := 10
	for n >= need {
		n -= need
		need--
		state = !state
	}
	return
}
