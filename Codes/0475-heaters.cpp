/*
 * @Author: LetMeFly
 * @Date: 2021-12-20 18:57:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-20 20:37:04
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef _WIN32
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        if (houses[0] < heaters[0]) ans = heaters[0] - houses[0];
        if (heaters[heaters.size() - 1] < houses[houses.size() - 1]) ans = max(ans, houses[houses.size() - 1] - heaters[heaters.size() - 1]);
        int locHeater = 0;
        auto f = [&](int house) {
            if (locHeater >= heaters.size()) return 0;
            if (locHeater + 1 < heaters.size() && house > heaters[locHeater + 1]) locHeater++;
            int ans = house - heaters[locHeater];
            if (locHeater + 1 < heaters.size()) ans = min(ans, heaters[locHeater + 1] - house);
            return ans;
        }; 
        for (int& house : houses) {
            ans = max(ans, f(house));
        }
        return ans;
    }
};
#else
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (int i = 0, j = 0; i < houses.size(); i++) {
            int curDistance = abs(houses[i] - heaters[j]);
            while (j < heaters.size() - 1 && abs(houses[i] - heaters[j]) >= abs(houses[i] - heaters[j + 1])) {
                j++;
                curDistance = min(curDistance, abs(houses[i] - heaters[j]));
            }
            ans = max(ans, curDistance);
        }
        return ans;
    }
};
#endif

#ifdef _WIN32
int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        Solution sol;
        vector<int> v1 = stringToVector(s1), v2 = stringToVector(s2);
        cout << sol.findRadius(v1, v2) << endl;
    }
    return 0;
}
#endif