/*
 * @Author: LetMeFly
 * @Date: 2025-02-25 16:18:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-25 16:30:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Allocator {
private:
    vector<int> v;
    int n;
public:
    Allocator(int n): n(n), v(n) {}
    
    int allocate(int size, int mID) {
        for (int l = -1, r = 0, cnt = 0; r < n; r++) {
            if (v[r]) {
                cnt = 0;
                l = r;
                continue;
            }
            cnt++;
            if (cnt == size) {
                while (++l <= r) {
                    v[l] = mID;
                }
                return r - size + 1;
            }
        }
        return -1;
    }
    
    int freeMemory(int mID) {
        int ans = 0;
        for (int &t : v) {
            if (t == mID) {
                ans++;
                t = 0;
            }
        }
        return ans;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */