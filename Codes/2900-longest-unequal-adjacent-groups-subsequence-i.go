/*
 * @Author: LetMeFly
 * @Date: 2025-05-15 10:32:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-15 13:23:52
 */
package main

func getLongestSubsequence(words []string, groups []int) (ans []string) {
    for i, g := range groups {
		if i == 0 || g != groups[i - 1] {
			ans = append(ans, words[i])
		}
	}
	return 
}