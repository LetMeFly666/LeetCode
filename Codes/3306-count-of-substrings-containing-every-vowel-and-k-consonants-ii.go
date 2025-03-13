/*
 * @Author: LetMeFly
 * @Date: 2025-03-13 12:59:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-13 13:04:36
 */
package main

var aeiou3306 []byte = []byte{'a', 'e', 'i', 'o', 'u'}

func aeiouIndex3306(c byte) int {
    for i := 0; i < 5; i++ {
        if (aeiou3306[i] == c) {
            return i
        }
    }
    return -1
}

func countOfSubstrings(word string, k int) (ans int64) {
    bin1 := make([]int, 5)
    cntc1, cntk1, left1 := 0, 0, 0
    bin2 := make([]int, 5)
    cntc2, cntk2, left2 := 0, 0, 0
    for i := range word {
        index := aeiouIndex3306(word[i])
        if index == -1 {
            cntk1++
            cntk2++
        } else {
            bin1[index]++
            if bin1[index] == 1 {
                cntc1++
            }
            bin2[index]++
            if bin2[index] == 1 {
                cntc2++
            }
        }

        for cntc1 == 5 && cntk1 >= k {
            index = aeiouIndex3306(word[left1])
            left1++
            if index == -1 {
                cntk1--
            } else {
                bin1[index]--
                if bin1[index] == 0 {
                    cntc1--
                }
            }
        }
        for cntc2 == 5 && cntk2 > k {
            index = aeiouIndex3306(word[left2])
            left2++
            if index == -1 {
                cntk2--
            } else {
                bin2[index]--
                if bin2[index] == 0 {
                    cntc2--
                }
            }
        }
        ans += int64(left1 - left2)
    }
    return
}