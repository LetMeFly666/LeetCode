/*
 * @Author: LetMeFly
 * @Date: 2024-09-24 18:49:56
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-24 18:55:39
 */
package main

func maximumSubsequenceCount(text string, pattern string) int64 {
    ans, cnt0, cnt1 := int64(0), int64(0), int64(0)
    for i := range text  {
        if text[i] == pattern[1] {
            ans += cnt0
            cnt1++
        }
        if text[i] == pattern[0] {
            cnt0++
        }
    }
    if cnt0 > cnt1 {
        ans += cnt0
    } else {
        ans += cnt1
    }
    return ans
}