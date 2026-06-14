/*
 * @Author: LetMeFly
 * @Date: 2026-06-14 23:22:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-14 23:26:22
 * @Description: https://github.com/LetMeFly666/LeetCode/pull/1635#discussion_r3409742977
 */
#include "Codes/_[1,2]toVector.h"

int main() {
    string a = "[1,2,3,4]";
    ListNode* head = stringToLinkedList(a);
    debug(head);
    deleteLinkedList(head);

    a = "[]";
    head = stringToLinkedList(a);
    debug(head);
    deleteLinkedList(head);

    return 0;
}

/*
Don't forget to delete the LinkedList!
1 -> 2 -> 3 -> 4
0
*/
