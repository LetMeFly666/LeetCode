/*
 * @Author: LetMeFly
 * @Date: 2024-11-21 23:07:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-21 23:08:30
 */
package main

func finalPositionOfSnake(n int, commands []string) (ans int) {
    for _, c := range commands {
        switch c[0] {
        case 'U':
            ans -= n;
        case 'D':
            ans += n;
        case 'L':
            ans--;
        case 'R':
            ans++;
        }
    }
    return
}