/*
 * @Author: LetMeFly
 * @Date: 2022-07-13 22:45:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-13 22:55:11
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        list<int> lr;  // From left to right
        for (int &t : asteroids) {
            if (t > 0)
                lr.push_back(t);
            else {
                bool destroyed = false;
                while (lr.size()) {
                    int Mlr = lr.back();
                    if (Mlr < abs(t)) {
                        lr.pop_back();
                    }
                    else if (Mlr == abs(t)) {
                        lr.pop_back();
                        destroyed = true;
                        break;
                    }
                    else {
                        destroyed = true;
                        break;
                    }
                }
                if (!destroyed)
                    ans.push_back(t);
            }
        }
        for (int &t : lr) {
            ans.push_back(t);
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry  // 直接使用vector
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;  // From left to right
        for (int &t : asteroids) {
            if (t > 0) {
                ans.push_back(t);
            }
            else {
                bool alive = true;
                while (alive && ans.size() && ans.back() > 0) {
                    alive = ans.back() < -t;
                    if (ans.back() <= -t)
                        ans.pop_back();
                }
                if (alive)
                    ans.push_back(t);
            }
        }
        return ans;
    }
};
#endif  // FirstTry