/*
 * @Author: LetMeFly+LeetCode官方题解
 * @Date: 2025-02-25 22:07:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-25 22:26:53
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

constexpr int MAX_LEVEL = 15;
constexpr double P_FACTOR = 0.5;

class SkiplistNode {
public:
    int value;
    vector<SkiplistNode*> next;

    SkiplistNode(int value, int level): value(value), next(level) {}
};

class Skiplist {
private:
    SkiplistNode* head;
    int level;  // 先有几层遍历几层

    int getLevel() {
        int ans = 1;
        while (rand() < P_FACTOR && ans < MAX_LEVEL) {
            ans++;
        }
        return ans;
    }
public:
    Skiplist() {
        head = new SkiplistNode(-1, MAX_LEVEL);
        level = 0;
    }

    bool search(int target) {
        SkiplistNode* p = this->head;
        for (int i = level - 1; i >= 0; i--) {
            while (p->next[i] && p->next[i]->value < target) {  // 严格小于
                p = p->next[i];
            }
        }
        return p->next[0] && p->next[0]->value == target;
    }

    void add(int num) {
        vector<SkiplistNode*> update(MAX_LEVEL, head);  // update[i]：第i层哪个节点需要更新其next
        SkiplistNode* p = this->head;
        for (int i = level - 1; i >= 0; i--) {
            while (p->next[i] && p->next[i]->value < num) {
                p = p->next[i];
            }
            update[i] = p;
        }

        int newLevel = getLevel();
        level = max(level, newLevel);

        SkiplistNode* newNode = new SkiplistNode(num, newLevel);
        for (int i = 0; i < newLevel; i++) {
            newNode->next[i] = update[i]->next[i];
            update[i]->next[i] = newNode;
        }
    }

    bool erase(int num) {  // 主：力扣官解
        vector<SkiplistNode *> update(MAX_LEVEL, nullptr);
        SkiplistNode *p = this->head;
        for (int i = level - 1; i >= 0; i--) {
            /* 找到第 i 层小于且最接近 num 的元素*/
            while (p->next[i] && p->next[i]->value < num) {
                p = p->next[i];
            }
            update[i] = p;
        }
        p = p->next[0];
        /* 如果值不存在则返回 false */
        if (!p || p->value != num) {
            return false;
        }
        for (int i = 0; i < level; i++) {
            if (update[i]->next[i] != p) {
                break;
            }
            /* 对第 i 层的状态进行更新，将 next 指向被删除节点的下一跳 */
            update[i]->next[i] = p->next[i];
        }
        delete p;
        /* 更新当前的 level */
        while (level > 1 && head->next[level - 1] == nullptr) {
            level--;
        }
        return true;
    }
};
