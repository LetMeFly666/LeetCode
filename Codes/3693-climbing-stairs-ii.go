/*
 * @Author: LetMeFly
 * @Date: 2026-11-12 19:11:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-12 19:20:21
 */
package main

type ABC3693 struct {
	a    [3]int
	diff int
}

func (abc *ABC3693)push(v int) {
	abc.a[abc.diff] = v
	abc.diff = (abc.diff + 1) % 3
}

func (abc* ABC3693)get(i int) int {
	return abc.a[(i + abc.diff) % 3]
}

func min3693(a, b, c int) int {
	if a > b {
		a = b
	}
	if a > c {
		a = c
	}
	return a
}

func climbStairs(n int, costs []int) int {
	abc := ABC3693{}
	for _, cost := range costs {
		abc.push(cost + min3693(
			abc.get(0) + 9,
			abc.get(1) + 4,
			abc.get(2) + 1,
		))
	}
	return abc.get(2)
}
