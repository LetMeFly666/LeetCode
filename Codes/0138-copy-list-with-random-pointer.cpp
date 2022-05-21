/*
 * @Author: LetMeFly
 * @Date: 2021-07-22 10:22:47
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-07-22 10:51:26
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//-------------------

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
private:
    unordered_map<Node *, int> ori;
    unordered_map<int, Node *> New;
    void copyOneNode(Node *p1, Node *p2)
    {
        p1->random = p2->random ? p2->random : NULL;
        // p1->next = p2->next;
        p1->val = p2->val;
    }

public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;
        Node *toReturn = new Node(0);
        Node *p = toReturn;
        int s = 0;
        while (head)
        {
            ori[head] = s;
            New[s] = p;
            s++;
            copyOneNode(p, head);
            head = head->next;
            if (head)
            {
                Node *temp = new Node(0);
                p->next = temp;
                p = temp;
            }
        }
        p = toReturn;
        while (p)
        {
            p->random = p->random ? New[ori[p->random]] : NULL;
            p = p->next;
        }
        return toReturn;
    }
};

//-------------------