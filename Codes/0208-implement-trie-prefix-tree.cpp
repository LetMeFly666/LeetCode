/*
 * @Author: LetMeFly
 * @Date: 2021-10-19 22:53:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-19 23:08:41
 */
// /*
//  * @Author: LetMeFly
//  * @Date: 2021-10-19 22:53:58
//  * @LastEditors: LetMeFly
//  * @LastEditTime: 2021-10-19 22:53:59
//  */
// #include <bits/stdc++.h>
// using namespace std;
// #define mem(a) memset(a, 0, sizeof(a))
// #define dbg(x) cout << #x << " = " << x << endl
// #define fi(i, l, r) for (int i = l; i < r; i++)
// #define cd(a) scanf("%d", &a)
// typedef long long ll;
// class Trie {
// private:
//     vector<Trie*> children;
//     bool isEnd;

//     Trie* searchPrefix(string prefix) {
//         Trie* node = this;
//         for (char ch : prefix) {
//             ch -= 'a';
//             if (node->children[ch] == nullptr) {
//                 return nullptr;
//             }
//             node = node->children[ch];
//         }
//         return node;
//     }

// public:
//     Trie() : children(26), isEnd(false) {}

//     void insert(string word) {
//         Trie* node = this;
//         for (char ch : word) {
//             ch -= 'a';
//             if (node->children[ch] == nullptr) {
//                 node->children[ch] = new Trie();
//             }
//             node = node->children[ch];
//         }
//         node->isEnd = true;
//     }

//     bool search(string word) {
//         Trie* node = this->searchPrefix(word);
//         return node != nullptr && node->isEnd;
//     }

//     bool startsWith(string prefix) {
//         return this->searchPrefix(prefix) != nullptr;
//     }
// };

#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
class Trie {
private:
    bool isEnd;
    vector<Trie*> childs;
    Trie* Find(string &word) {
        Trie* p = this;
        for (char &c: word) {
            if (!p->childs[c - 'a']) {
                return nullptr;
            }
            p = p->childs[c - 'a'];
        }
        return p;
    }
public:
    Trie() {
        isEnd = false;
        childs.resize(26);
    }
    
    void insert(string word) {
        Trie* p = this;
        for (char &c: word) {
            if (p->childs[c - 'a'] == nullptr) {
                p->childs[c - 'a'] = new Trie();
            }
            p = p->childs[c - 'a'];
        }
        p -> isEnd = true;
    }
    
    bool search(string word) {
        Trie* p = Find(word);
        return p && p->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* p = Find(prefix);
        return p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */