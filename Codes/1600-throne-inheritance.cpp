/*
 * @Author: LetMeFly
 * @Date: 2024-04-07 16:39:01
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-07 16:47:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

struct KingNode {
    string name;
    vector<KingNode*> childs;
    bool isAlive;

    KingNode(string name) : name(name) {
        isAlive = true;
    }
};

class ThroneInheritance {
private:
    unordered_map<string, KingNode*> ma;
    KingNode* root;
    vector<string> tempForInheritanceOrder;

    void dfs(KingNode* root) {
        if (root->isAlive) {
            tempForInheritanceOrder.push_back(root->name);
        }
        for (KingNode* child : root->childs) {
            dfs(child);
        }
    }
public:
    ThroneInheritance(string kingName) {
        root = new KingNode(kingName);
        ma[kingName] = root;
    }
    
    void birth(string parentName, string childName) {
        KingNode* child = new KingNode(childName);
        ma[childName] = child;
        ma[parentName]->childs.push_back(child);
    }
    
    void death(string name) {
        ma[name]->isAlive = false;
    }
    
    vector<string> getInheritanceOrder() {
        tempForInheritanceOrder.clear();
        dfs(root);
        return tempForInheritanceOrder;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */