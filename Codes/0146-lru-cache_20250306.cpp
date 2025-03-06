/*
 * @Author: LetMeFly
 * @Date: 2025-03-06 15:06:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-06 15:28:56
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

struct NodeLRU {
    int val, key;
    NodeLRU* next, *prev;
    NodeLRU(int key, int val) {
        this->key = key;
        this->val = val;
        next = prev = nullptr;
    };
};

class LRUCache {
private:
    NodeLRU* head, *tail;
    int capacity;
    int n;
    unordered_map<int, NodeLRU*> cache;

    void remove(NodeLRU* node) {  // 没修改node
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void add(NodeLRU* node) {
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
    }

    void debugList() {
        NodeLRU* p = head->next;
        cout << "Debug: ";
        while (p != tail) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
public:
    LRUCache(int capacity): capacity(capacity) {
        n = 0;
        head = new NodeLRU(0, 0);
        tail = new NodeLRU(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        NodeLRU* node = cache[key];
        remove(node);
        add(node);
        // debugList();
        return node->val;
    }
    
    void put(int key, int value) {
        NodeLRU* node;
        if (cache.count(key)) {
            node = cache[key];
            node->val = value;
            remove(node);
        } else {
            n++;
            node = new NodeLRU(key, value);
            cache[key] = node;
            if (n > capacity) {
                n = capacity;
                cache.erase(head->next->key);
                remove(head->next);
            }
        }
        add(node);
        // debugList();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#ifdef _WIN32
/*
["LRUCache","put","put","get","put","get","put","get","get","get"]
[[2],[1,0],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]

[null,null,null,0,null,-1,null,-1,3,4]
*/
int main() {
    string a, b;
    while (cin >> a >> b) {
        vector<string> vs = stringToVectorStringWithQuots(a);
        vector<vector<int>> vvi = stringToVectorVector(b);
        LRUCache lru = LRUCache(vvi[0][0]);
        for (int i = 1; i < vs.size(); i++) {
            if (vs[i] == "put") {
                lru.put(vvi[i][0], vvi[i][1]);
            } else {
                cout << lru.get(vvi[i][0]) << endl;
            }
        }
    }
    return 0;
}
#endif