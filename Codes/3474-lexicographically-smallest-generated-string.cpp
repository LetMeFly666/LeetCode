/*
 * @Author: LetMeFly
 * @Date: 2026-03-31 21:55:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-31 22:36:56
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif
/*
1 3 5 7不一样
idx[7]++

str1: F
str2: bxxx
ans:  aaaa
只要前面有不一样的，后面则能修改的全a就好
当然后面任意都行，如果后面的F需要修改某个a为其他完全ok

str1: F
str2: abxx
ans1: aaaa  第一个字符还a，但后面至少有个不一样的
ans2: baaa  第一个字符就不一样，后面全a就好（当然也能再改）
如果能构造ans1，一定比ans2更优，因为ans1后面字符的不同于str2会导致后面F更容易

str1: F
str2: aabx
ans:  aaaa

str1: F
str2: aaaa
ans:  aaab
*/
class Solution {
private:
    int n, m;
    vector<bool> can_change;

    bool fillT(string& ans, int idx, const string& s) {
        for (int i = 0; i < m; i++) {
            if (ans[i + idx] == '-') {
                ans[i + idx] = s[i];
                can_change[i + idx] = false;
            } else {
                if (ans[i + idx] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool fillF(string& ans, int idx, const string& s) {
        if (all_cannot_change_and_all_same(ans, idx, s)) {
            return false;
        }
        // 以下逻辑一定能设置成功ans.sub(idx)
        int first2a = get_first2a(ans, idx, s);
        if (first2a == -1) {  // 能修改的元素对应的str2全部是a
            
        } else {  // first2a设置为a则后续可任意a
            for (int i = 0; i < first2a; i++) {  // 前面能修改的元素对应str2一定是a，但是ans对应位置也设置为a最小
                if ()
            }
        }
        return true;
    }

    bool all_cannot_change_and_all_same(string& ans, int idx, const string& s) {
        for (int i = 0; i < m; i++) {
            if (can_change[i + idx] || ans[i + idx] != s[i]) {
                return false;
            }
        }
        return true;
    }

    // 找第一个可以设置为a导致ans.sub和str2不同的位置
    int get_first2a(string& ans, int idx, const string& s) {
        for (int i = 0; i < m; i++) {
            if (can_change[i + idx] && s[i] != 'a') {
                return i;
            }
        }
        return -1;
    }
public:
    string generateString(const string& str1, const string& str2) {
        n = str1.size();
        m = str2.size();
        string ans('-', n + m - 1);
        can_change = move(vector<bool>(n + m - 1, true));
        
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] == 'T') {
                if (!fillT(ans, i, str2)) {
                    return "";
                }
            }
        }

        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] == 'F') {
                if (!fillF(ans, i, str2)) {
                    return "";
                }
            }
        }

        return ans;
    }
};