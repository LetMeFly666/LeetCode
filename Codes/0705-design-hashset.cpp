/*
 * @Author: LetMeFly
 * @Date: 2024-04-14 09:39:24
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-14 09:44:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class MyHashSet {  // 1k天偷个懒
private:
    vector<bool> hashset;
public:
    MyHashSet() {
        hashset.resize(1e6 + 1);
    }
    
    void add(int key) {
        hashset[key] = true;
    }
    
    void remove(int key) {
        hashset[key] = false;
    }
    
    bool contains(int key) {
        return hashset[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */