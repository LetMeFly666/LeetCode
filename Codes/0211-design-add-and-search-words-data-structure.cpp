/*
 * @Author: LetMeFly
 * @Date: 2021-10-19 23:13:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-19 23:27:26
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
class WordDictionary {
private:
    vector<WordDictionary*> childs;
    bool isEnd;
    WordDictionary* dfs(WordDictionary* p, string & words, int to) {
        if (to == words.size()) {
            return p;
        }
        if (!p) {
            return nullptr;
        }
        char thisChar = words[to];
        if (thisChar != '.') {
            if (!p->childs[thisChar - 'a']) {
                return nullptr;
            }
            return dfs(p->childs[thisChar - 'a'], words, to + 1);
        } else {
            for (int i = 0; i < 26; i++) {
                WordDictionary* nextP = dfs(p->childs[i], words, to + 1);
                if (nextP && nextP->isEnd) {
                    return nextP;
                }
            }
            return nullptr;
        }
    }
public:
    WordDictionary() {
        childs.resize(26, nullptr);
        isEnd = false;
    }
    
    void addWord(string word) {
        WordDictionary* p = this;
        for (char &c: word) {
            if (!p->childs[c - 'a']) {
                p->childs[c - 'a'] = new WordDictionary();
            }
            p = p->childs[c - 'a'];
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        WordDictionary* p = dfs(this, word, 0);
        return p && p->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */