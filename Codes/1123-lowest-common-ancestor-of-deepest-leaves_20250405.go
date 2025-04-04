/*
 * @Author: LetMeFly
 * @Date: 2025-04-05 01:05:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-05 01:11:09
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
type pair struct{
    node *TreeNode
    depth int
}

func dfs(root* TreeNode) pair {
    if root == nil {
        return pair{root, 0}
    }
    left := dfs(root.Left)
    right := dfs(root.Right)
    if left.depth > right.depth {
        return pair{left.node, left.depth + 1}
    } else if left.depth < right.depth {
        return pair{right.node, right.depth + 1}
    }
    return pair{root, left.depth + 1}
}

func lcaDeepestLeaves(root *TreeNode) *TreeNode {
    return dfs(root).node
}