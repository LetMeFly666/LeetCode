/*
 * @Author: LetMeFly
 * @Date: 2025-02-25 21:03:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-25 22:15:33
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
    
    bool erase(int num) {
        vector<SkiplistNode*> update(level);
        SkiplistNode* p = this->head;
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
        while (level > 0 && !head->next[level - 1]) {  // 下标是从0开始的
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
#ifdef _WIN32
/*
["Skiplist","add","add","add","search","add","search","erase","erase","search"]
[[],[1],[2],[3],[0],[4],[1],[0],[1],[1]]

[null,null,null,null,false,null,true,false,true,false]
*/
int main() {
    string a, b;
    while (cin >> a >> b) {
        vector<string> op = stringToVectorStringWithQuots(a);
        vector<vector<int>> val = stringToVectorVector(b);
        debug(op);
        debug(val);
        Skiplist *obj = new Skiplist();
        for (int i = 1; i < op.size(); i++) {
            if (op[i] == "add") {
                obj->add(val[i][0]);
            } else if (op[i] == "erase") {
                cout << obj->erase(val[i][0]) << endl;
            } else {
                cout << obj->search(val[i][0]) << endl;
            }
        }
        delete obj;
    }
    return 0;
}
#endif