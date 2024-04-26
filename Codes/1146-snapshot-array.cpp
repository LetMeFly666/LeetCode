/*
 * @Author: LetMeFly
 * @Date: 2024-04-26 10:57:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-26 11:14:08
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class SnapshotArray {
private:
    vector<vector<pair<int, int>>> a;  // a[i]: i的每个历史版本[[快照编号, 值], ...]
    int snapId;

public:
    SnapshotArray(int length) : a(length), snapId(0) {}
    
    void set(int index, int val) {
        a[index].push_back({snapId, val});
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        vector<pair<int, int>>::iterator it = upper_bound(a[index].begin(), a[index].end(), pair<int, int>{snap_id + 1, -1});
        return it == a[index].begin() ? 0 : prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */