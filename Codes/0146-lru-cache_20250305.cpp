/*
 * @Author: LetMeFly
 * @Date: 2025-03-05 23:49:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-06 15:06:07
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

struct Node_LRU {
    Node_LRU* prev;
    Node_LRU* next;
    int val;
};

class LRUCache {
private:
    Node_LRU* head, *tail;
    int capacity;
    int n;
    unordered_map<int, Node_LRU*> cache;

    void remove1node(Node_LRU* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void add1node(Node_LRU* node) {
        tail->prev->next = node;
        node->prev = tail->prev;
        tail->prev = node;
        node->next = tail;
    }
public:
    LRUCache(int capacity): capacity(capacity) {
        head = new Node_LRU;
        head->prev = nullptr;
        tail = new Node_LRU;
        tail->next = nullptr;
        head->next = tail;
        tail->prev = head;
        n = 0;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        Node_LRU* node = cache[key];
        if (node != tail->prev) {
            remove1node(node);
            add1node(node);
        }
        return node->val;
    }
    
    void put(int key, int value) {
        Node_LRU* node;
        if (cache.count(key)) {
            node = cache[key];
        } else {
            node = new Node_LRU;
            n++;
            cache[key] = node;
        }
        node->val = value;
        if (n > capacity) {
            cache.erase(head->next->val);
            remove1node(head->next);
            n--;
        } else if (cache.count(key)) {
            remove1node(cache[key]);
        }
        add1node(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
#ifdef _WIN32
int main() {
    Node_LRU* n = new Node_LRU;
    cout << n << endl;  // 不一定为nullptr
    return 0;
}
#endif