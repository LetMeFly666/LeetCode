/*
 * @Author: LetMeFly
 * @Date: 2021-09-22 15:20:14
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-09-22 15:33:21
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#define dbg(x) cout << #x << " = " << x << endl
class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *>ans;
        int allNum = 0;
        ListNode *p = head;
        while(p) {p=p->next; allNum++;}
        // dbg(allNum); //*******
        int lenSmall = allNum / k;
        int lenBig = lenSmall + 1;
        int numBig = allNum % k;
        int numSmall = k - numBig;
        // dbg(lenSmall); //**********
        // dbg(lenBig); //**********
        // dbg(numBig); //**********
        // dbg(numSmall); //**********
        int alreadyLen = 0, alreadyBigNum = 0;
        while(head)
        {
            p = head->next;
            alreadyLen++;
            if (alreadyLen == 1) {
                ans.push_back(head);
            }
            if (alreadyBigNum < numBig && alreadyLen == lenBig) {
                head->next = NULL;
                alreadyLen = 0;
                alreadyBigNum++;
            }
            else if (alreadyBigNum >= numBig && alreadyLen == lenSmall) {
                head->next = NULL;
                alreadyLen = 0;
            }
            head = p;
        }
        if (lenSmall == 0) {
            while(numSmall--) {
                ans.push_back(NULL);
            }
        }
        return ans;
    }
};