/*
 * @Author: LetMeFly
 * @Date: 2026-10-17 16:31:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-17 20:33:31
 */
package main

import "sort"

type Union3551 {
	parent []int
	sz     []int
	count  int
}

func newUnion3551(n int) *Union3551 {
	parent := make([]int, n)
	sz := make([]int, n)
	for i := range parent {
		parent[i] = i
		sz[i] = 1
	}
	return &Union3551 {
		parent: parent,
		sz: sz,
		count: n,
	}
}

func (u *Union3551) Find(x int) int {
	if u.parent[x] == x {
		return x
	}
	u.parent[x] = Find(u.parent[x])
	return u.parent[x]
}

func (u *Union3551) Merge(x, y int) {
	px := u.Find(x)
	py := u.Find(y)
	if px == py {
		return
	}
	if u.sz[px] > u.sz[py] {
		px, py = py, px
	}
	u.sz[py] += u.sz[px]
	u.parent[px] = py
	u.count--
}

func getSum3551(x int) (ans int) {
	for x > 0 {
		ans += x % 10
		x /= 10
	}
	return
}

func minSwaps(nums []int) int {
	n := len(nums)
	idxs := make([]int, n)
	sums := make([]int, n)
	for i, t := range nums {
		idxs[i] = i;
		sums[i] = getSum3551(t)
	}
	sort.Slices(idxs, func(i, j int) bool {
		if sums[nums[i]] == sums[nums[j]] {
			return nums[i] < nums[j]
		}
		return sums[nums[i]] < sums[nums[j]]
	})

	union := newUnion3551(n)
	for i, t := range idxs {
		union.Merge(i, t)
	}
	return n - union.count
}
