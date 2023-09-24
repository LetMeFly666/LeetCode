/*
 * @Author: LetMeFly
 * @Date: 2023-09-24 13:04:40
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-24 14:11:32
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

    void refresh(int key, int value) {
        Node* thisNode = ma[key];
        thisNode->value = value;
        Node* previous = thisNode->previous, *next = thisNode->next;
        previous->next = next, next->previous = previous;
        thisNode->next = head->next;
        head->next = thisNode;
        thisNode->next->previous = thisNode;
    }
public:
    LRUCache(int capacity) {
        head = new Node(nullptr, nullptr, 0, 0);
        tail = new Node(head, nullptr, 0, 0);
        head->next = tail;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (ma.count(key)) {
            refresh(key, ma[key]->value);
            debug();  //*****************
            return ma[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (ma.count(key)) {
            refresh(key, value);
            debug();  //*****************
            return;
        }
        Node* thisNode = new Node(head, head->next, key, value);
        ma[key] = thisNode;
        head->next = thisNode, thisNode->next->previous = thisNode;
        if (ma.size() > capacity) {
            Node* toRemove = tail->previous;
            ma.erase(toRemove->key);
            toRemove->previous->next = tail;
            tail->previous = toRemove->previous;
        }
        debug();  //*****************
    }

    void debug() {
        cout << "Now size: " << ma.size() << endl;
        Node* p = head;
        while (p != tail) {
            if (p == head) {
                cout << "[";
            }
            else {
                cout << ", (" << p->key << "|" << p->value << ")";
            }
            p = p->next;
        }
        cout << "]" << endl;
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

#ifdef _WIN32
void test1() {
    vector<string> op = {"LRUCache", "put", "put", "put", "put", "put", "get", "put", "get", "get", "put", "get", "put", "put", "put", "get", "put", "get", "get", "get", "get", "put", "put", "get", "get", "get", "put", "put", "get", "put", "get", "put", "get", "get", "get", "put", "put", "put", "get", "put", "get", "get", "put", "put", "get", "put", "put", "put", "put", "get", "put", "put", "get", "put", "put", "get", "put", "put", "put", "put", "put", "get", "put", "put", "get", "put", "get", "get", "get", "put", "get", "get", "put", "put", "put", "put", "get", "put", "put", "put", "put", "get", "get", "get", "put", "put", "put", "get", "put", "put", "put", "get", "put", "put", "put", "get", "get", "get", "put", "put", "put", "put", "get", "put", "put", "put", "put", "put", "put", "put"};
    vector<vector<int>> val = {{10},{10,13},{3,17},{6,11},{10,5},{9,10},{13},{2,19},{2},{3},{5,25},{8},{9,22},{5,5},{1,30},{11},{9,12},{7},{5},{8},{9},{4,30},{9,3},{9},{10},{10},{6,14},{3,1},{3},{10,11},{8},{2,14},{1},{5},{4},{11,4},{12,24},{5,18},{13},{7,23},{8},{12},{3,27},{2,12},{5},{2,9},{13,4},{8,18},{1,7},{6},{9,29},{8,21},{5},{6,30},{1,12},{10},{4,15},{7,22},{11,26},{8,17},{9,29},{5},{3,4},{11,30},{12},{4,29},{3},{9},{6},{3,4},{1},{10},{3,29},{10,28},{1,20},{11,13},{3},{3,12},{3,8},{10,9},{3,26},{8},{7},{5},{13,17},{2,27},{11,15},{12},{9,19},{2,15},{3,16},{1},{12,17},{9,1},{6,19},{4},{5},{5},{8,1},{11,7},{5,2},{9,28},{1},{2,2},{7,4},{4,22},{7,24},{9,26},{13,28},{11,26}};
    LRUCache lru(val[0][0]);
    for (int i = 1; i < op.size(); i++) {
        if (op[i] == "get") {
            cout << lru.get(val[i][0]) << endl;
        }
        else {
            lru.put(val[i][0], val[i][1]);
        }
        lru.debug();
    }
}

int main() {
    test1();
    return 0;
}
#endif