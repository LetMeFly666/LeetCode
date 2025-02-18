/*
 * @Author: LetMeFly
 * @Date: 2025-02-18 10:08:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-18 10:15:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> ma;
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            ma[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        unordered_map<int, vector<int>>::iterator it = ma.find(value);
        if (it == ma.end()) {
            return 0;
        }
        vector<int>& v = it->second;  // 这里必须引用否则会超时
        return upper_bound(v.begin(), v.end(), right) - lower_bound(v.begin(), v.end(), left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */