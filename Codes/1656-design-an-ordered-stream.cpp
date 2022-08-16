/*
 * @Author: LetMeFly
 * @Date: 2022-08-16 08:40:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-16 08:42:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class OrderedStream {
private:
    vector<string> v;
    int nowLoc;
public:
    OrderedStream(int n) : nowLoc(1) {
        v = vector<string>(n + 1);
    }
    
    vector<string> insert(int idKey, string value) {
        v[idKey] = value;
        vector<string> ans;
        while (nowLoc < v.size() && v[nowLoc].size()) {
            ans.push_back(v[nowLoc++]);
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */