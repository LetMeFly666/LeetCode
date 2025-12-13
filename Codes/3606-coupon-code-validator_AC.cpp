/*
 * @Author: LetMeFly
 * @Date: 2025-12-13 22:41:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-13 22:42:29
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline bool is_ok(string& s) {
        for (char c : s) {
            if (c != '_' && !isalnum(c)) {
                return false;
            }
        }
        return !s.empty();
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> electronics, grocery, pharmacy, restaurant;
        for (int i = 0; i < code.size(); i++) {
            if (!isActive[i]) {
                continue;
            }
            if (!is_ok(code[i])) {
                continue;
            }
            if (businessLine[i] == "electronics") {
                electronics.push_back(code[i]);
            } else if (businessLine[i] == "grocery") {
                grocery.push_back(code[i]);
            } else if (businessLine[i] == "pharmacy") {
                pharmacy.push_back(code[i]);
            } else if (businessLine[i] == "restaurant") {
                restaurant.push_back(code[i]);
            }
        }
        sort(electronics.begin(), electronics.end());
        sort(grocery.begin(), grocery.end());
        sort(pharmacy.begin(), pharmacy.end());
        sort(restaurant.begin(), restaurant.end());
        vector<string> ans;
        ans.reserve(electronics.size() + grocery.size() + pharmacy.size() + restaurant.size());
        ans.insert(ans.end(), make_move_iterator(electronics.begin()), make_move_iterator(electronics.end()));
        ans.insert(ans.end(), make_move_iterator(grocery.begin()), make_move_iterator(grocery.end()));
        ans.insert(ans.end(), make_move_iterator(pharmacy.begin()), make_move_iterator(pharmacy.end()));
        ans.insert(ans.end(), make_move_iterator(restaurant.begin()), make_move_iterator(restaurant.end()));
        return ans;
    }
};