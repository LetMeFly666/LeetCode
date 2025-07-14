/*
 * @Author: LetMeFly
 * @Date: 2025-07-14 23:37:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-14 23:47:42
 */
package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getDecimalValue(head *ListNode) (ans int) {
    for ; head != nil; head = head.Next {
        ans = ans * 2 + head.Val
    }
    return
}