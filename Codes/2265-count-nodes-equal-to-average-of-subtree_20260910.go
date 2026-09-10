/*
 * @Author: LetMeFly
 * @Date: 2026-09-10 14:38:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-10 14:41:32
 */
package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var ans int

func dfs(root *TreeNode) (int, int) {
	if root == nil {
		return 0, 0
	}
	vl, nl := dfs(root.Left)
	vr, nr := dfs(root.Right)
	v := root.Val + vl + vr
	n := 1 + nl + nr
	if v / n == root.Val {
		ans++
	}
	return v, n
}

func averageOfSubtree(root *TreeNode) int {
	ans = 0
	dfs(root)
	return ans
}
