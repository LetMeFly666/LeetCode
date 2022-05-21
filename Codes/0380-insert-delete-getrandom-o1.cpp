/*
 * @Author: LetMeFly
 * @Date: 2022-04-13 00:09:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-13 00:11:47
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class RandomizedSet {
private:
    set<int> se;
public:
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if (se.count(val))
            return false;
        se.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if (se.count(val)) {
            se.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int n = rand() % se.size();
        set<int>::iterator it = se.begin();
        for (int i = 0; i < n; i++)
            it++;
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */