/*
 * @Author: LetMeFly
 * @Date: 2022-10-24 21:02:12
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-24 21:14:43
 */
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
unordered_map<int, pii> key2hidden;  // <key, <times, lastTime>>
map<int, int, cmp> ma;

struct cmp {
    bool operator()(const int a, const int b) const {
        return key2hidden[a].first == key2hidden[b].first ? key2hidden[a].second < key2hidden[b].second : key2hidden[a].first < key2hidden[b].first;
    }
};

int main() {
    key2hidden[1] = {1, 0};
    ma[1] = 1;
    key2hidden[2] = {1, 0};
    ma[2] = 2;
    ma.count(1);
    key2hidden[1].first++;
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// #define dbg(x) cout << #x << " = " << x << endl

// typedef pair<int, int> pii;
// unordered_map<int, int> key2hidden;  // <key, <times, lastTime>>

// struct cmp {
//     bool operator()(const int a, const int b) const {
//         return key2hidden[a] < key2hidden[b];
//     }
// };

// map<int, int, cmp> ma;
// int main() {
//     key2hidden[1] = 1;
//     ma[1] = 1;
//     key2hidden[1] = 2;
//     ma[1] = 2;
//     dbg(ma.count(1));
//     dbg(ma.size());
//     return 0;
// }