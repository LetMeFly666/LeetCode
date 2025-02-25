/*
 * @Author: LetMeFly
 * @Date: 2025-02-24 09:03:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-24 09:09:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class OrderedStream {
private:
    int ptr, n;
    vector<string> v;
public:
    OrderedStream(int n) {
        ptr = 1;
        this->n = n;
        v.resize(n + 1);
    }
    
    vector<string> insert(int idKey, string value) {
        v[idKey] = move(value);
        if (idKey != ptr) {
            return {};
        }
        vector<string> ans;
        while (ptr <= n && v[ptr].size()) {
            ans.push_back(v[ptr++]);
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */