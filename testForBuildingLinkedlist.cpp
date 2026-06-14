/*
 * @Author: LetMeFly
 * @Date: 2026-06-14 23:22:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-14 23:37:52
 * @Description: https://github.com/LetMeFly666/LeetCode/pull/1635#discussion_r3409742977
 */
#include "Codes/_[1,2]toVector.h"

int main() {
    string a = "[1,2,3,4]";
    ListNode* head = stringToLinkedList(a);
    debug(head);
    deleteLinkedList(head);

    a = "[]";
    // // 诶？这咋取消注释下面两行的话，结果就是1，不取消注释的话，结果就是0？
    // vector<int> v = stringToVector(a);
    // debug(v);
    head = stringToLinkedList(a);
    debug(head);
    deleteLinkedList(head);
    
    return 0;
}

/*
Original:
Don't forget to delete the LinkedList!
1 -> 2 -> 3 -> 4
0

After:
Don't forget to delete the LinkedList!
1 -> 2 -> 3 -> 4
null linked list
*/
