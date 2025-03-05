/*
 * @Author: LetMeFly
 * @Date: 2025-03-05 22:36:39
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-05 22:42:05
 */
package main

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

type pair_MWOBT struct {
    node *TreeNode
    num int
}

func widthOfBinaryTree(root *TreeNode) (ans int) {
    q := []pair_MWOBT{{root, 0}}
    for len(q) > 0 {
        nextQ := []pair_MWOBT{}
        ans = max(ans, q[len(q) - 1].num - q[0].num + 1)
        for _, pair := range q {
            if pair.node.Left != nil {
                nextQ = append(nextQ, pair_MWOBT{pair.node.Left, pair.num * 2 + 1})
            }
            if pair.node.Right != nil {
                nextQ = append(nextQ, pair_MWOBT{pair.node.Right, pair.num * 2 + 2})
            }
        }
        q = nextQ
    }
    return ans
}