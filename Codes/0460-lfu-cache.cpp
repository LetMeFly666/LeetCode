/*
 * @Author: LetMeFly
 * @Date: 2022-10-24 19:51:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-24 21:17:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
#define dbg(x) cout << #x << " = " << x << endl
#endif

typedef pair<int, int> pii;
unordered_map<int, pii> key2hidden;  // <key, <times, lastTime>>

struct cmp {
    bool operator()(const int a, const int b) const {
        return key2hidden[a].first == key2hidden[b].first ? key2hidden[a].second < key2hidden[b].second : key2hidden[a].first < key2hidden[b].first;
    }
};

class LFUCache {
private:
    int n;
    int th;
    map<int, int, cmp> ma;


public:
    LFUCache(int capacity) {
        n = capacity;
        th = 0;
        key2hidden.clear();
    }
    
    int get(int key) {
        if (!ma.count(key))
            return -1;
        key2hidden[key].first++;
        // printf("key = %d, ma[%d] = %d\n", key, key, ma[key]);  //************
        int ans = ma[key];  // 不能这样竟然，要不然会多一个 #2 ???!
        // int ans = ma.find(key)->second;
        dbg(ma.size());  //*********
        printf("ma.erase(%d)\n", key);  //*******
        ma.erase(ma.find(key));
        dbg(ma.size());  //********
        ma[key] = ans;
        return ans;
    }
    
    void put(int key, int value) {
        int nowNum = ma.size();
        if (nowNum == n) {
            auto toRemove = key2hidden.begin();
            int toRemoveKey = toRemove->first;
            key2hidden.erase(toRemove);
            ma.erase(toRemoveKey);
        }
        key2hidden[key] = {1, th++};
        ma[key] = value;
        // printf("key = %d, ma[%d] = %d\n", key, key, ma[key]);  //************
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#ifdef _WIN32
/*
["LFUCache","put","put","get","put","get","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]

*/
int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        vector<string> op = stringToVectorString(s1);
        vector<vector<int>> v = stringToVectorVector(s2);
        LFUCache cache(v[0][0]);
        for (int i = 1; i < v.size(); i++) {
            if (op[i] == "\"put\"") {
                cache.put(v[i][0], v[i][1]);
            }
            else {
                cout << cache.get(v[i][0]) << endl;
            }
        }
        
    }
    return 0;
}
#endif