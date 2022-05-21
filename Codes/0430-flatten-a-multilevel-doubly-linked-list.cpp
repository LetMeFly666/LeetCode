/*
 * @Author: LetMeFly
 * @Date: 2021-09-24 10:06:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-09-24 10:47:08
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
private:
    /* head is the newList and it will return the end of the list*/
    Node* join(Node* head) {
        Node* p=head;
        while(p)
        {
            head=p;
            if(head->child) {
                head->child->prev=head;
                Node* end=join(head->child);
                end->next=head->next;
                if(end->next) end->next->prev=end;
                head->next=head->child;
                head->child=NULL;
            }
            p=p->next;
        }
        return head;
    }
    void reSortLink(Node*head) {
        while(head->next) {
            if(head->next->prev!=head) {
                printf("Node val(%d)'s head is not right\n",head->next->val);
            }
            // head->next->prev=head;
            // if(head->child) {
            //     printf("Node val(%d)'s child is not Null\n", head->val);
            // }
            // head->child=NULL;
            head=head->next;
        }
    }
public:
    Node* flatten(Node* head) {
        if(!head)return head;
        head->prev=NULL;
        Node* end=join(head);
        end->next=end->child=NULL;
        // reSortLink(head);
        return head;
    }
};