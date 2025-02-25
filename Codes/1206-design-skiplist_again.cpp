/*
 * @Author: LetMeFly
 * @Date: 2025-02-25 22:27:23
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-25 23:03:03
 * @Description: AC,5.03%,73.75%,一遍过
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

const int MAX_LEVEL = 15;
const double p = 0.5;

class SkiplistNode {
public:
    int value;
    vector<SkiplistNode*> next;

    SkiplistNode(int val, int level): value(val), next(level) {}  // 一个节点一旦生成，level就是固定的
};

class Skiplist {
private:
    SkiplistNode* head;
    int level;

    int randLevel() {
        int ans = 1;
        while (ans < MAX_LEVEL && rand() < p) {
            ans++;
        }
        return ans;
    }
public:
    Skiplist() {
        head = new SkiplistNode(-1, MAX_LEVEL);  // 每层一旦出现，就一定需要head节点
        level = 0;
    }
    
    bool search(int target) {
        SkiplistNode* p = head;
        for (int i = level - 1; i >= 0; i--) {
            while (p->next[i] && p->next[i]->value < target) {
                p = p->next[i];
            }
        }
        p = p->next[0];
        return p && p->value == target;
    }
    
    void add(int num) {
        int newLevel = randLevel();
        vector<SkiplistNode*> update(newLevel, head);
        SkiplistNode* p = head;
        for (int i = level - 1; i >= 0; i--) {
            while (p->next[i] && p->next[i]->value < num) {
                p = p->next[i];
            }
            if (i < newLevel) {
                update[i] = p;
            }
        }

        level = max(level, newLevel);
        SkiplistNode* newNode = new SkiplistNode(num, newLevel);
        for (int i = 0; i < newLevel; i++) {
            newNode->next[i] = update[i]->next[i];
            update[i]->next[i] = newNode;
        }
    }
    
    bool erase(int num) {
        vector<SkiplistNode*> update(level);
        SkiplistNode* p = head;
        for (int i = level - 1; i >= 0; i--) {
            while (p->next[i] && p->next[i]->value < num) {
                p = p->next[i];
            }
            update[i] = p;
        }
        
        p = p->next[0];
        if (!p || p->value != num) {
            return false;
        }
        
        for (int i = 0; i < level; i++) {
            if (update[i]->next[i] != p) {
                break;
            }
            update[i]->next[i] = p->next[i];
        }
        delete p;

        while (level > 0 && !head->next[level - 1]) {
            level--;
        }
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */