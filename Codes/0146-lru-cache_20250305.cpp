/*
 * @Author: LetMeFly
 * @Date: 2025-03-05 23:49:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-06 00:13:41
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
linklist: 使用记录
key->node:
*/
struct Node_20250305 {
    int val;
    Node_20250305* next, *prev;
};

class LRUCache {
private:
    int capacity;
    int n;
    Node_20250305* head, *tail;
    unordered_map<int, Node_20250305*> cache;
    unordered_map<Node_20250305*, int> n2k;
public:
    LRUCache(int capacity): capacity(capacity), n(0), head(new Node_20250305), tail(head) {}
    ~LRUCache() {

    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        Node_20250305* p = cache[key];
        p->prev->next = p->next;
        if (p->next) {
            p->next->prev = p->prev;
        }
        tail->next = p;
        p->prev = tail;
        p->next = nullptr;
        tail = p;
        return p->val;
    }
    
    void put(int key, int value) {
        Node_20250305* p = new Node_20250305;
        p->prev = tail;
        p->next = nullptr;
        tail->next = p;
        tail = p;
        n++;
        if (cache.count(key)) {
            n--;
            Node_20250305* original = cache[key];
            original->prev->next = original->next;
            if (original->next) {
                original->next->prev = original->prev;
            }
            delete original;
        }
        if (n > capacity) {
            n--;
            Node_20250305* temp = head->next;
            cache.erase(n2k[temp]);
            n2k.erase(temp);
            delete temp;
            head = temp;
        }
        cache[key] = p;
        n2k[p] = key;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */