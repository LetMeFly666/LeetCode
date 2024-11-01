/*
 * @Author: LetMeFly
 * @Date: 2024-11-01 12:33:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-01 12:35:34
 */
class Solution {
    public long maxEnergyBoost(int[] energyDrinkA, int[] energyDrinkB) {
        long day0a = 0, day0b = 0, day1a = energyDrinkA[0], day1b = energyDrinkB[0];
        for (int i = 1; i < energyDrinkA.length; i++) {
            long day2a = Math.max(day1a, day0b) + energyDrinkA[i], day2b = Math.max(day0a, day1b) + energyDrinkB[i];
            day0a = day1a;
            day0b = day1b;
            day1a = day2a;
            day1b = day2b;
        }
        return Math.max(day1a, day1b);
    }
}