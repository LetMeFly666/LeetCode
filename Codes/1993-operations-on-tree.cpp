/*
 * @Author: LetMeFly
 * @Date: 2023-09-23 09:26:01
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-23 09:43:17
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class LockingTree {
private:
    vector<int> lockUser;  // 谁锁的这个节点（0表示未锁）
    vector<int> parent;
    vector<vector<int>> child;

    bool hasLockedParent(int num) {
        while (parent[num] != -1) {
            num = parent[num];
            if (lockUser[num]) {
                return true;
            }
        }
        return false;
    }

    bool hasLockedChildAndUnlock(int num) {
        bool hasLockedChild = false;
        if (lockUser[num]) {
            lockUser[num] = 0;
            hasLockedChild = true;
        }
        for (int thisChild : child[num]) {
            hasLockedChild |= hasLockedChildAndUnlock(thisChild);
        }
        return hasLockedChild;
    }
    
public:
    LockingTree(vector<int>& parent): parent(parent) {
        lockUser = vector<int>(parent.size());
        child = vector<vector<int>>(parent.size());
        for (int i = 1; i < parent.size(); i++) {
            child[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if (lockUser[num]) {
            return false;
        }
        lockUser[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if (lockUser[num] == user) {
            lockUser[num] = 0;
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        if (!lockUser[num] && !hasLockedParent(num) && hasLockedChildAndUnlock(num)) {
            lockUser[num] = user;
            return true;
        }
        return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */