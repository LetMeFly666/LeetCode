/*
 * @Author: LetMeFly
 * @Date: 2024-04-18 10:48:56
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-18 12:57:54
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error [0] 0的二倍还是0
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        unordered_multiset<int> removed, all(changed.begin(), changed.end());
        vector<int> ans;
        for (int t : changed) {
            if (removed.count(t)) {
                removed.erase(removed.find(t));
                continue;
            }
            int t2 = t * 2;
            if (!all.count(t2)) {
                return {};
            }
            all.erase(all.find(t2));
            removed.insert(t2);
            ans.push_back(t);
        }
        return ans;
    }
};
#else  // FirstTry
#ifdef SecondTry  // Error 被使用过≠cannot
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        unordered_multiset<int> a(changed.begin(), changed.end());
        vector<int> ans;
        for (int t : changed) {
            if (a.count(t) && a.count(t * 2)) {
                a.erase(a.find(t));
                a.erase(a.find(t * 2));
                ans.push_back(t);
            }
            else {
                return {};
            }
        }
        return ans;
    }
};
#else  // SecondTry
// #define ThirdTry
// #define LET_DEBUG
#ifdef ThirdTry  // TLE  // 奇怪，怎么这么慢！（10^5个0耗时几百秒）
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        unordered_multiset<int> a(changed.begin(), changed.end());
        vector<int> ans;
        #ifdef LET_DEBUG
            int cnt = 0;
            time_t lastTime = clock();
        #endif
        for (int t : changed) {
            #ifdef LET_DEBUG
                time_t now = clock();
                cout << cnt << ": " << (double)(now - lastTime) / CLOCKS_PER_SEC << "(s)" << endl;
                lastTime = now;
                cnt++;
            #endif
            if (!a.count(t)) {
                continue;
            }
            a.erase(a.find(t));
            if (!a.count(t * 2)) {
                return {};
            }
            a.erase(a.find(t * 2));
            ans.push_back(t);
        }
        return ans;
    }
};
#else  // ThirdTry
// FourthTry
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        vector<int> a(200000 + 1);  // 手动unordered_map  // 2倍防越界
        for (int t : changed) {
            a[t]++;
        }
        vector<int> ans;
        for (int t : changed) {
            if (!a[t]) {
                continue;
            }
            a[t]--;
            if (!a[t * 2]) {
                return {};
            }
            a[t * 2]--;
            ans.push_back(t);
        }
        return ans;
    }
};
#endif  // ThirdTry
#endif  // SecondTry
#endif  // FirstTry


#ifdef ThirdTry
int main() {
    time_t begin = clock();
    vector<int> changed(1e5, 0);
    Solution sol;
    debug(sol.findOriginalArray(changed));
    time_t end = clock();
    double consume = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << consume << "s" << endl;
    return 0;
}
#endif  // ThirdTry
#ifdef LET_DEBUG
#include <Windows.h>
int main() {
    /*
        init_vector_int_a_1e5: 0.001(s)
        vector_to_unordered_multiset: 0.09(s)
        erase_begin_until_empty: 3.083(s)
        vector_to_unordered_multiset2: 0.604(s)
        erase_by_se_find: 1.445(s)    
    */
    time_t begin = clock();
    vector<int> a(1e5, 0);
    time_t init_vector_int_a_1e5 = clock();
    cout << "init_vector_int_a_1e5: " << (double)(init_vector_int_a_1e5 - begin) / CLOCKS_PER_SEC << "(s)" << endl;
    unordered_multiset<int> se(a.begin(), a.end());
    time_t vector_to_unordered_multiset = clock();
    cout << "vector_to_unordered_multiset: " << (double)(vector_to_unordered_multiset - init_vector_int_a_1e5) / CLOCKS_PER_SEC << "(s)" << endl;
    while (se.size()) {
        se.erase(se.begin());
    }
    time_t erase_begin_until_empty = clock();
    cout << "erase_begin_until_empty: " << (double)(erase_begin_until_empty - vector_to_unordered_multiset) / CLOCKS_PER_SEC << "(s)" << endl;
    se = unordered_multiset<int>(a.begin(), a.end());
    time_t vector_to_unordered_multiset2 = clock();
    cout << "vector_to_unordered_multiset2: " << (double)(vector_to_unordered_multiset2 - erase_begin_until_empty) / CLOCKS_PER_SEC << "(s)" << endl;
    // se.erase(0);  // then will be 0
    // cout << se.size() << endl;
    while (se.size()) {
        se.erase(se.find(0));
    }
    time_t erase_by_se_find = clock();
    cout << "erase_by_se_find: " << (double)(erase_by_se_find - vector_to_unordered_multiset2) / CLOCKS_PER_SEC << "(s)" << endl;
    
    return 0;
}
#endif  // LET_DEBUG