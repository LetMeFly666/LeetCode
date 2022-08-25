/*
 * @Author: LetMeFly
 * @Date: 2022-08-25 08:46:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-25 09:09:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l, r;
        auto it = lower_bound(arr.begin(), arr.end(), x);
        if (it == arr.end()) {
            l = arr.size() - 1, r = arr.size() - 1;
        }
        else {
            l = r = it - arr.begin();
        }
        while (k--) {
            // 有一边超过了边缘
            if (r == arr.size())
                l--;
            else if (l == -1)
                r++;
            // 左右指针都没有超过边缘
            else {
                if (x - arr[l] <= arr[r] - x) {
                    l--;
                }
                else {
                    r++;
                }
            }
        }
        printf("l = %d, r = %d\n", l, r);  //**********
        return vector<int>(arr.begin() + l + 1, arr.begin() + r + 1);
    }
};
#else  // FirstTry
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int r = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = r - 1;
        while (k--) {
            if (l == -1)
                r++;
            else if (r == arr.size())
                l--;
            else {
                if (x - arr[l] <= arr[r] - x) {
                    l--;
                }
                else {
                    r++;
                }
            }
        }
        return vector<int>(arr.begin() + l + 1, arr.begin() + r);
    }
};
/*
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int r = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = r - 1;
        while (k--) {
            if (l == -1) {
                r++;
            } else if (r == arr.size()) {
                l--;
            } else if (x - arr[l] <= arr[r] - x) {
                l--;
            } else {
                r++;
            }
        }
        return vector<int>(arr.begin() + l + 1, arr.begin() + r);
    }
};
*/
#endif  // FirstTry