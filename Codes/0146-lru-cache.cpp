/*
 * @Author: LetMeFly
 * @Date: 2023-09-24 13:04:40
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-24 13:43:03
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Node {
public:
    Node* previous, *next;
    int key, value;
    Node(Node* previous, Node* next, int key, int value) {
        this->previous = previous;
        this->next = next;
        this->key = key;
        this->value = value;
    }
};

class LRUCache {
private:
    Node* head, *tail;
    int capacity;
    unordered_map<int, Node*> ma;
public:
    LRUCache(int capacity) {
        head = new Node(nullptr, nullptr, 0, 0);
        tail = new Node(head, nullptr, 0, 0);
        head->next = tail;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (ma.count(key)) {
            return ma[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (ma.count(key)) {
            Node* thisNode = ma[key];
            thisNode->value = value;
            Node* previous = thisNode->previous, *next = thisNode->next;
            previous->next = next, next->previous = previous;
            thisNode->next = head->next;
            head->next = thisNode;
            thisNode->next->previous = thisNode;
        }
        else {
            Node* thisNode = new Node(head, head->next, key, value);
            ma[key] = thisNode;
            head->next = thisNode, thisNode->next->previous = thisNode;
            if (ma.size() > capacity) {
                Node* toRemove = tail->previous;
                ma.erase(toRemove->key);
                toRemove->previous->next = tail;
                tail->previous = toRemove->previous;
                delete toRemove;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */