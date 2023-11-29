/*
 * @Author: LetMeFly
 * @Date: 2023-11-29 12:24:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-29 12:24:32
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class SmallestInfiniteSet {
private:
    int continuousSmallest;
    set<int> added;
public:
    SmallestInfiniteSet() {
        continuousSmallest = 1;
    }
    
    int popSmallest() {
        if (added.size()) {
            int ans = *added.begin();
            added.erase(added.begin());
            return ans;
        }
        return continuousSmallest++;
    }
    
    void addBack(int num) {
        if (num >= continuousSmallest) {
            return;
        }
        added.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */