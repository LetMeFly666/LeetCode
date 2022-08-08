/*
 * @Author: LetMeFly
 * @Date: 2022-08-08 08:41:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-08 09:03:25
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    // bool cmp(int& a, int& b) {  // 885  8852  8859
    //     string sa = to_string(a);
    //     string sb = to_string(b);
    //     int to = min(sa.size(), sb.size());
    //     for (int i = 0; i < to; i++) {
    //         if (sa[i] != sb[i])
    //             return sa[i] > sb[i];
    //     }
    //     if (sa.size() > sb.size()) {  // sa:885999  sb:885
    //         int from = sa.size() - sb.size();
    //         int to = min(sa.size(), from + sb.size());
    //         for (int i = from; i < to; i++) {
    //             if (sa[i] != sb[i - from]) {
    //                 return sa[i] > sb[i - from];
    //             }
    //         }
    //     }
    //     // TODO: 还可能更长： a:88889  b:8  -> 888898    |   a:888887  b:8  ->   888887
    // }

    #ifdef FirstTry  // Error: 830 8308 用此算法可能会排序为 8308308，而实际应该为8308830
    static bool cmp(int& a, int& b) {  // 必须加上static，否则相当于有一个隐含的this指针Solution* this
        string sa = to_string(a);
        string sb = to_string(b);
        int locA = 0, locB = 0;
        bool stillA = true, stillB = true;
        while (stillA || stillB) {
            if (sa[locA] != sb[locB]) {
                return sa[locA] > sb[locB];
            }
            locA++, locB++;
            if (locA == sa.size()) {
                locA = 0, stillA = false;
            }
            if (locB == sb.size()) {
                locB = 0, stillB = false;
            }
        }
        return true;  // 循环起来等价，都无所谓了
    }
    #else  //FirstTry
    // SecondTry
    static bool cmp(const int& a, const int& b) {
        string sa = to_string(a);
        string sb = to_string(b);
        return sa + sb > sb + sa;
    }
    #endif  // FirstTry
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        sort(nums.begin(), nums.end(), cmp);
        for (int& t : nums) {
            ans += to_string(t);
        }
        if (ans[0] == '0') {  // 不能是00000
            return "0";
        }
        return ans;
    }
};