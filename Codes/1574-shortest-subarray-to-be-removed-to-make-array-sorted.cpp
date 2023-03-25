/*
 * @Author: LetMeFly
 * @Date: 2023-03-25 09:22:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-25 09:44:45
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int right = arr.size() - 1;
        while (right - 1 >= 0 && arr[right - 1] <= arr[right]) {
            right--;
        }
        if (!right) {  // 移动到首个元素了
            return 0;
        }
        int ans = right;
        for (int left = 0; left < arr.size(); left++) {  // left和right肯定不会相遇
            while (right < arr.size() && arr[right] < arr[left]) {
                right++;
            }
            ans = min(ans, right - left - 1);
            // printf("left = %d, right = %d, ans = %d\n", left, right, ans);  //*************
            if (left + 1 < arr.size() && arr[left + 1] < arr[left]) {
                break;
            }
        }
        return ans;
    }
};

#ifdef _WIN32
/*
[10,13,17,21,15,15,9,17,22,22,13]

*/
int main() {
    string s;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.findLengthOfShortestSubarray(v) << endl;
    }
    return 0;
}
#endif