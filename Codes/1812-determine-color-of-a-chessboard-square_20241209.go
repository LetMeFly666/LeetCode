/*
 * @Author: LetMeFly
 * @Date: 2024-12-09 17:12:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-09 17:14:32
 */
package main

func squareIsWhite(coordinates string) bool {
    return coordinates[0] % 2 != coordinates[1] % 2
}