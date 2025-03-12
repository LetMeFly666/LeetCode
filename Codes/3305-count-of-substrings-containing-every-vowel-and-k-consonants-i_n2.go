/*
 * @Author: LetMeFly
 * @Date: 2025-03-12 09:54:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-12 10:03:41
 */
package main

var aeiou map[byte]bool = map[byte]bool{'a': true, 'e': true, 'i': true, 'o': true, 'u': true}

func countOfSubstrings(word string, k int) (ans int) {
    for i, _ := range word {
        cnt5 := map[byte]bool{}
        cntk := 0
        for _, c := range word[i:] {
            if aeiou[byte(c)] {
                cnt5[byte(c)] = true
            } else {
                cntk++
            }
            if len(cnt5) == 5 && cntk == k {
                ans++
            }
        }
    }
    return
}