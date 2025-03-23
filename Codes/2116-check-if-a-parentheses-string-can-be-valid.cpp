/*
 * @Author: LetMeFly
 * @Date: 2025-03-23 09:37:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-23 10:39:28
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
*)*(**
()(())


(*)*
(())


(**(
xxxx

(*
()



*/
// class Solution {
// public:
//     bool canBeValid(string s, string locked) {
//         int custome = 0, needRight;
//         for (int i = 0; i < locked.size(); i++) {
//             if (locked[i] == '0') {
//                 custome++;
//             } else if (s[i] == ')') {
//                 if (!custome && !needRight) {
//                     return false;
//                 }
//                 if (needRight) {
//                     needRight--;
//                 } else {
//                     custome--;
//                 }
//             } else {  // s[i] is '(' and locked
//                 needRight++;
//             }
//         }
//         return custome
//     }
// };

/*
custome: 当前有多少个没被预约的*
needRight: 还需要多少个)
如果遇到)就直接消耗一个needRight
如果遇到*就先累积起来到reserved，看会不会碰到)
*/
// class Solution {
// public:
//     bool canBeValid(string s, string locked) {
//         int custome = 0, needRight = 0, reserved = 0;
//         for (int i = 0; i < locked.size(); i++) {
//             if (locked[i] == '0') {
//                 if (needRight) {
//                     needRight--;
//                     reserved++;
//                 } else {
//                     custome++;
//                 }
//             } else if (s[i] == ')') {
//                 if (needRight) {
//                     needRight--;
//                 } else if ()
//             } else {
                
//             }
//         }
//     }
// };

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int l = 0, r = 0;
        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0') {
                l--, r++;
                if (l < 0) {
                    l = 1;
                }
            } else {  // ()
                if (s[i] == '(') {
                    l++, r++;
                } else {
                    l--, r--;
                    if (r < 0) {
                        return false;
                    }
                    if (l < 0) {
                        l = 1;
                    }
                }
            }
        }
        return !l;
    }
};