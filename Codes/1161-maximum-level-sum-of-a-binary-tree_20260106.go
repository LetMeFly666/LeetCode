/*
 * @Author: LetMeFly
 * @Date: 2026-01-06 10:19:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-06 10:37:44
 */
package main

import "container/list"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxLevelSum(root *TreeNode) int {
    ans, maximum := 0, -1000000000
    nowLayer := 0
    q := list.New();
    q.PushBack(root)
    for q.Len() > 0 {
        nowLayer++
        layerSum := 0
        for t := q.Len(); t > 0; t-- {
            nodeElement := q.Front()
            node := nodeElement.Value.(*TreeNode)
            q.Remove(nodeElement)
            layerSum += node.Val
            if node.Left != nil {
                q.PushBack(node.Left)
            }
            if node.Right != nil {
                q.PushBack(node.Right)
            }
        }
        if layerSum > maximum {
            maximum = layerSum
            ans = nowLayer
        }
    }
    return ans
}