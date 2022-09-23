/*
 * @Author: LetMeFly
 * @Date: 2022-09-23 12:25:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-23 13:35:05
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 用C++ list实现
class MyLinkedList {
private:
    list<int> li;

    inline list<int>::iterator getIndexIterator(int index) {
        list<int>::iterator it = li.begin();
        while (index--) {
            it++;
        }
        return it;
    }

    inline void debugList() {
        for (auto t : li) {
            cout << t << ", ";
        }
        puts("");
    }
public:
    MyLinkedList() {

    }
    
    int get(int index) {
        if (index < 0 || index >= li.size())
            return -1;
        return *getIndexIterator(index);
    }
    
    void addAtHead(int val) {
        li.push_front(val);
    }
    
    void addAtTail(int val) {
        li.push_back(val);
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0)
            index = 0;
        if (index > li.size())
            return;
        li.insert(getIndexIterator(index), val);
    }
    
    void deleteAtIndex(int index) {
        if (index >= li.size())
            return;
        li.erase(getIndexIterator(index));
    }
};
#else  // FirstTry
struct __LetMeFly_ListNode {
    int val;
    __LetMeFly_ListNode* next;

    __LetMeFly_ListNode() : next(nullptr) {}
    __LetMeFly_ListNode(int val) : val(val), next(nullptr) {}
};


class MyLinkedList {
private:
    __LetMeFly_ListNode* head;
    size_t size;

    __LetMeFly_ListNode* getIndexIterator(int index) {  // 无脑计算，不验证合法性
        __LetMeFly_ListNode* p = head->next;
        while (index--) {
            p = p->next;
        }
        return p;
    }
public:
    MyLinkedList() {
        head = new __LetMeFly_ListNode;
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        return getIndexIterator(index)->val;
    }
    
    void addAtHead(int val) {
        __LetMeFly_ListNode* secondNode = head->next;
        head->next = new __LetMeFly_ListNode(val);
        head->next->next = secondNode;
        size++;
    }
    
    void addAtTail(int val) {
        if (size == 0) {
            return addAtHead(val);
        }
        getIndexIterator(size - 1)->next = new __LetMeFly_ListNode(val);
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index <= 0) {
            index = 0;
            addAtHead(val);
            return;
        }
        if (index > size)
            return;
        if (index == size) {
            addAtTail(val);
            return;
        }
        __LetMeFly_ListNode* lastNode = getIndexIterator(index - 1);
        __LetMeFly_ListNode* nextNode = lastNode->next;
        lastNode->next = new __LetMeFly_ListNode(val);
        lastNode->next->next = nextNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= 0 && index < size) {
            if (index == 0) {
                __LetMeFly_ListNode* nextNode = head->next->next;
                delete head->next;
                head->next = nextNode;
            }
            else {
                __LetMeFly_ListNode* lastNode = getIndexIterator(index - 1);
                __LetMeFly_ListNode* nextNode = lastNode->next->next;
                delete lastNode->next;
                lastNode->next = nextNode;
            }
            size--;
        }
    }
};
#endif  // FirstTry

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */