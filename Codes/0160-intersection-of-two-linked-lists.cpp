/*
 * @Author: LetMeFly
 * @Date: 2021-07-21 16:21:29
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-07-21 16:43:04
 */

#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//----------------------------------------------------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
    typedef ListNode *P;

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;
        P ha = headA, hb = headB;
        // while (true)
        // {
        //     if (headA == headB)
        //         return headA;
        //     if (!headA)
        //         headA = hb;
        //     else
        //         headA = headA->next;
        //     if (!headB)
        //         headB = ha;
        //     else
        //         headB = headB->next;
        // }
        while(headA!=headB)
        {
            headA = headA?headA->next:hb;
            headB = headB?headB->next:ha;
        }
        return headA;
    }
};
//----------------------------------------------------------------------------

int main()
{
    cout << "未写" << endl;
    system("pause");
    return 0;
}