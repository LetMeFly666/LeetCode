/*
 * @Author: LetMeFly
 * @Date: 2023-03-13 12:00:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-13 12:03:27
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int ans = 0;
        for (int i = 0; i < energy.size(); i++) {
            if (initialEnergy <= energy[i]) {
                ans += energy[i] + 1 - initialEnergy;
                initialEnergy = energy[i] + 1;
            }
            if (initialExperience <= experience[i]) {
                ans += experience[i] + 1 - initialExperience;
                initialExperience = experience[i] + 1;
            }
            initialEnergy -= energy[i];
            initialExperience += experience[i];
        }
        return ans;
    }
};