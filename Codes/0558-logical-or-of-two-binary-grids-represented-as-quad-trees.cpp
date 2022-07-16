/*
 * @Author: LetMeFly
 * @Date: 2022-07-16 11:05:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-16 13:18:59
 */
#ifdef _WIN32
#include <bits/stdc++.h>
using namespace std;
// 这个Node和那个Node不同
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
#endif

#ifdef FirstTry  // Error
class Solution {
private:
    void allSonOr(Node* p1, bool val2) {  // p1的所有子节点全部或上val2
        if (!val2)
            return;
        queue<Node*> q;
        q.push(p1);
        while (q.size()) {
            Node* p = q.front();
            q.pop();
            if (p->isLeaf)
                p->val = true;
            else {
                q.push(p->bottomLeft);
                q.push(p->bottomRight);
                q.push(p->topLeft);
                q.push(p->topLeft);
            }
        }
    }
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        queue<Node*> q;
        q.push(quadTree1), q.push(quadTree2);
        while (q.size()) {
            Node *p2 = q.front(), *p1 = q.front();
            q.pop(), q.pop();
            if (p2->isLeaf) {
                allSonOr(p1, p2->val);
            }
            else if (p1->isLeaf) {
                allSonOr(p2, p1->val);
                *p1 = *p2;
                puts("--------");
            }
            else {
                q.push(p1->bottomLeft), q.push(p2->bottomLeft);
                q.push(p1->bottomRight), q.push(p2->bottomRight);
                q.push(p1->topLeft), q.push(p2->topLeft);
                q.push(p1->topLeft), q.push(p2->topLeft);
            }
        }
        return quadTree1;
    }
};
#else  // FirstTry
// SecondTry  // https://leetcode.cn/problems/logical-or-of-two-binary-grids-represented-as-quad-trees/solution/si-cha-shu-jiao-ji-by-leetcode-solution-wy1u/
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1->isLeaf) {
            if (quadTree1->val) {
                return new Node(true, true);
            }
            return new Node(quadTree2->val, quadTree2->isLeaf, quadTree2->topLeft, quadTree2->topRight, quadTree2->bottomLeft, quadTree2->bottomRight);
        }
        if (quadTree2->isLeaf) {
            return intersect(quadTree2, quadTree1);
        }
        Node* o1 = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node* o2 = intersect(quadTree1->topRight, quadTree2->topRight);
        Node* o3 = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node* o4 = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        if (o1->isLeaf && o2->isLeaf && o3->isLeaf && o4->isLeaf && o1->val == o2->val && o1->val == o3->val && o1->val == o4->val) {
            return new Node(o1->val, true);
        }
        return new Node(false, false, o1, o2, o3, o4);
    }
};
#endif  // FirstTry