/*
 * @Author: LetMeFly
 * @Date: 2024-12-30 14:08:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-30 14:11:54
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    ListNode* head;

    bool dfs(ListNode* l, TreeNode* t) {
        if (!l) {
            return true;
        }
        if (!t) {
            return false;
        }
        if (l->val == t->val) {
            if (dfs(l->next, t->left) || dfs(l->next, t->right)) {
                return true;
            }
        }
        if (l == head) {
            if (dfs(l, t->left) || dfs(l, t->right)) {
                return true;
            }
        }
        return false;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        this->head = head;
        return dfs(head, root);
    }
};