/*
 * @Author: LetMeFly
 * @Date: 2024-04-15 16:58:15
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-15 16:59:35
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class MyHashMap {
private:
    vector<int> hashMap;
public:
    MyHashMap() {
        hashMap.resize(1e6 + 1, -1);
    }
    
    void put(int key, int value) {
        hashMap[key] = value;
    }
    
    int get(int key) {
        return hashMap[key];
    }
    
    void remove(int key) {
        hashMap[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */