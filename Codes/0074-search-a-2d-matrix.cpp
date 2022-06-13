/*
 * @Author: LetMeFly
 * @Date: 2022-06-13 10:16:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-13 10:23:02
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 遍历一遍
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto& v : matrix)
            for (auto& t : v)
                if (t == target)
                    return true;
        return false;
    }
};
#else  // FirstTry
// SecondTry，二分
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int l = 0, r = matrix.size();
//         while (l < r) {
//             int mid = (l + r) >> 1;
//             if (matrix[mid][0] > target)
//                 r = mid;
//             else
//                 l = mid;
//         }
//     }
// };
class Solution {  // LeetCode
public:
    bool searchMatrix(vector<vector<int>> matrix, int target) {
        auto row = upper_bound(matrix.begin(), matrix.end(), target, [](const int b, const vector<int> &a) {
            return b < a[0];
        });
        if (row == matrix.begin()) {
            return false;
        }
        --row;
        return binary_search(row->begin(), row->end(), target);
    }
};
#endif  // FirstTry