/*
 * @Author: LetMeFly
 * @Date: 2024-06-12 11:07:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-12 11:07:29
 */
class Solution {
    public int accountBalanceAfterPurchase(int purchaseAmount) {
        int rest = purchaseAmount % 10;
        purchaseAmount -= rest;
        if (rest >= 5) {
            purchaseAmount += 10;
        }
        return 100 - purchaseAmount;
    }
}