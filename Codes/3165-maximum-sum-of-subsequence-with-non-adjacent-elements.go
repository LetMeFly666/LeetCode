/*
 * @Author: LetMeFly
 * @Date: 2024-11-02 15:23:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-02 15:48:27
 */
package main

type data struct {
    _00 int
    _01 int
    _10 int
    _11 int
}

type seg []data

func max(a int, b int) int {
    if a >= b {
        return a
    }
    return b
}

func maintain(tree seg, index int) {
    leftNode := tree[index * 2 + 1]
    rightNode := tree[index * 2 + 2]
    tree[index] = data{
        max(leftNode._00 + rightNode._10, leftNode._01 + rightNode._00),
        max(leftNode._00 + rightNode._11, leftNode._01 + rightNode._01),
        max(leftNode._10 + rightNode._10, leftNode._11 + rightNode._00),
        max(leftNode._10 + rightNode._11, leftNode._11 + rightNode._01),
    }
}

func build(tree seg, nums []int, index int, left int, right int) {
    if left == right {
        tree[index]._11 = max(0, nums[left])
        return
    }
    mid := (left + right) >> 1
    build(tree, nums, 2 * index + 1, left, mid)
    build(tree, nums, 2 * index + 2, mid + 1, right)
    maintain(tree, index)
}

func update(tree seg, index int, left int, right int, modified int, val int) {
    if left == right {
        tree[index]._11 = max(0, val)
        return
    }
    mid := (left + right) >> 1
    if modified <= mid {
        update(tree, 2 * index + 1, left, mid, modified, val)
    } else {
        update(tree, 2 * index + 2, mid + 1, right, modified, val)
    }
    maintain(tree, index)
}

func maximumSumSubsequence(nums []int, queries [][]int) int {
    tree := make(seg, len(nums) * 4)
    build(tree, nums, 0, 0, len(nums) - 1)
    ans := 0
    for _, query := range queries {
        update(tree, 0, 0, len(nums) - 1, query[0], query[1])
        ans = (ans + tree[0]._11) % 1_000_000_007
    }
    return ans
}