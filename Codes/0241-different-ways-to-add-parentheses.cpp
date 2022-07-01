/*
 * @Author: LetMeFly
 * @Date: 2022-07-01 10:32:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-01 10:50:45
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
#define dbg(x) cout << #x << " = " << x << endl
#endif

#ifdef FirstTry  // 以为要去重
class Solution {
private:
    /*
        如果用unordered_map<pair<int, int>, unordered_set<int>>则会出现如下报错：
        Line 60: Char 25: error: call to implicitly-deleted default constructor of 'Solution' vector<int> ret = Solution().diffWaysToCompute(param_1); return ret; ^ Line 13: Char 55: note: default constructor of 'Solution' is implicitly deleted because field 'ma' has a deleted default constructor unordered_map<pair<int, int>, unordered_set<int>> ma; ^ /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/unordered_map.h:141:7: note: explicitly defaulted function was implicitly deleted here unordered_map() = default; ^ /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/unordered_map.h:105:18: note: default constructor of 'unordered_map<std::pair<int, int>, std::unordered_set<int, std::hash<int>, std::equal_to<int>, std::allocator<int>>, std::hash<std::pair<int, int>>, std::equal_to<std::pair<int, int>>, std::allocator<std::pair<const std::pair<int, int>, std::unordered_set<int, std::hash<int>, std::equal_to<int>, std::allocator<int>>>>>' is implicitly deleted because field '_M_h' has a deleted default constructor _Hashtable _M_h; ^ /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/hashtable.h:438:7: note: explicitly defaulted function was implicitly deleted here _Hashtable() = default; ^ /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/hashtable.h:174:7: note: default constructor of '_Hashtable<std::pair<int, int>, std::pair<const std::pair<int, int>, std::unordered_set<int, std::hash<int>, std::equal_to<int>, std::allocator<int>>>, std::all
    */
    map<pair<int, int>, unordered_set<int>> ma;

    unordered_set<int> dfs(string& s, int l, int r) {  // [l, r)
        if (ma.count({l ,r}))
            return ma[{l, r}];
        unordered_set<int> ans;
        bool hasOp = false;
        for (int i = l; i < r; i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                hasOp = true;
                unordered_set<int> left = dfs(s, l, i);
                unordered_set<int> right = dfs(s, i + 1, r);
                if (s[i] == '+')
                    for (auto& a : left)
                        for (auto& b : right)
                            ans.insert(a + b);
                else if (s[i] == '-')
                    for (auto& a : left)
                        for (auto& b : right)
                            ans.insert(a - b);
                else if (s[i] == '*')
                    for (auto& a : left)
                        for (auto& b : right)
                            ans.insert(a * b);
            }
        }
        if (!hasOp) {
            ans.insert(atoi(s.substr(l, r - l).c_str()));
        }
        return ma[{l, r}] = ans;
    }
public:
    vector<int> diffWaysToCompute(string& expression) {
        unordered_set<int> se = dfs(expression, 0, expression.size());
        printf("se.size() = %lld\n", se.size());
        for (auto& t : se) {
            cout << t << " ";
        }
        puts("");
        vector<int> ans;
        dbg(ans.size());
        for (auto& t : se) {
            ans.push_back(t);
            dbg(ans.size());
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
private:
    map<pair<int, int>, vector<int>> ma;

    vector<int> dfs(string& s, int l, int r) {  // [l, r)
        if (ma.count({l ,r}))
            return ma[{l, r}];
        vector<int> ans;
        bool hasOp = false;
        for (int i = l; i < r; i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                hasOp = true;
                vector<int> left = dfs(s, l, i);
                vector<int> right = dfs(s, i + 1, r);
                if (s[i] == '+')
                    for (auto& a : left)
                        for (auto& b : right)
                            ans.push_back(a + b);
                else if (s[i] == '-')
                    for (auto& a : left)
                        for (auto& b : right)
                            ans.push_back(a - b);
                else if (s[i] == '*')
                    for (auto& a : left)
                        for (auto& b : right)
                            ans.push_back(a * b);
            }
        }
        if (!hasOp) {
            ans.push_back(atoi(s.substr(l, r - l).c_str()));
        }
        return ma[{l, r}] = ans;
    }
public:
    vector<int> diffWaysToCompute(string& expression) {
        return dfs(expression, 0, expression.size());
    }
};
#endif  // FirstTry