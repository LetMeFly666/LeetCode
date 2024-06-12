/*
 * @Author: LetMeFly
 * @Date: 2024-06-12 11:08:28
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-12 11:08:29
 */
package main

func accountBalanceAfterPurchase(purchaseAmount int) int {
    rest := purchaseAmount % 10
    purchaseAmount -= rest
    if rest >= 5 {
        purchaseAmount += 10
    }
    return 100 - purchaseAmount
}