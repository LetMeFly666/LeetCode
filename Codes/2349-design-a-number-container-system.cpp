/*
 * @Author: LetMeFly
 * @Date: 2025-09-17 20:30:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-17 20:58:14
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

// class NumberContainers {
// private:
//     multiset<int> se;
// public:
//     NumberContainers() {
        
//     }
    
//     void change(int index, int number) {
        
//     }
    
//     int find(int number) {
//         auto it = se.find(number);
//         if (it == se.end()) {
//             return -1;
//         }
//         return it - se.begin();
//     }
// };

class NumberContainers {
private:
    unordered_map<int, set<int>> num2idx;
    unordered_map<int, int> idx2num;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        auto it = idx2num.find(index);
        if (it != idx2num.end()) {
            int number = (*it).second;
            num2idx[number].erase(index);
        }
        idx2num[index] = number;
        num2idx[number].insert(index);
    }
    
    int find(int number) {
        auto it = num2idx.find(number);
        if (it == num2idx.end() || (*it).second.size() == 0) {
            return -1;
        }
        return *(*it).second.begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */