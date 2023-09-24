/*
 * @Author: LetMeFly
 * @Date: 2023-09-24 13:04:40
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-24 13:14:23
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Node {
public:
    Node* next, *previous;
    int value;
    Node(Node* next, Node* previous, int value) {
        this->next = next;
        this->previous = previous;
        this->value = value;
    }
};

class LRUCache {
private:
    Node* head;
    Node* tail;
    int capacity;
    unordered_map<int, Node*> ma;
public:
    LRUCache(int capacity) {
        tail = head = new Node(nullptr, nullptr, 0);
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
            Node* next = thisNode->next;
            Node* previous = thisNode->previous;
            previous->next = next;
            if (next) {
                next->previous = previous;
            }
            thisNode->next = head->next;
            thisNode->previous = head;
            head->next = thisNode;
        }
        else {
            Node* thisNode = new Node(head->next, head, value);
            if (head->next) {
                head->next->previous = thisNode;
            }
            head->next = thisNode;
            ma[key] = thisNode;
            if (ma.size() > capacity) {
                
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