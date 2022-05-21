/*
 * @Author: LetMeFly
 * @Date: 2021-12-28 08:53:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-28 09:37:20
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstSolution
class Trie {
public:
    vector<Trie*> childs;
    bool isEnd;
    Trie() : childs(26) {
        isEnd = false;
    }
    ~Trie() {
        delete this;
    }
};

class Solution {
private:
    Trie* root = new Trie();
    bool dfs(string& s, int loc) {
        if (loc == s.size())
            return true;
        Trie* t = root;
        for (; loc < s.size(); loc++) {
            t = t->childs[s[loc] - 'a'];
            if (!t)
                return false;
            if (t->isEnd)
                if (dfs(s, loc + 1))
                    return true;
        }
        // return t->isEnd;
        return false;
    }
    void insert(string& s) {
        Trie* t = root;
        for (char& c : s) {
            if (!(t->childs[c - 'a']))
                t->childs[c - 'a'] = new Trie();
            t = t->childs[c - 'a'];
        }
        t->isEnd = true;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [&](const string& a, const string& b) {return a.size() < b.size();});
        vector<string> ans;
        for (string& word : words) {
            if (word.size()) {
                if (dfs(word, 0)) {
                    ans.push_back(word);
                }
                else {
                    insert(word);
                }
            }
        }
        return ans;
    }
};
#else
struct Trie {
    vector<Trie*> childs;
    bool isEnd;
    Trie() : childs(26), isEnd(false) {}
    #ifdef _WIN32
    ~Trie() {
        delete this;
    }
    #endif
};
class Solution {
private:
    Trie* root;
    bool dfs(string& s, int loc) {
        if (loc == s.size())
            return true;
        Trie* t = root;
        for (; loc < s.size(); loc++) {
            t = t->childs[s[loc] - 'a'];
            if (!t)
                return false;
            if (t->isEnd)
                if (dfs(s, loc + 1))
                    return true;
        }
        return false;
    }
    void insert(string& s) {
        Trie* t = root;
        for (char& c : s) {
            if (!(t->childs[c - 'a']))
                t->childs[c - 'a'] = new Trie();
            t = t->childs[c - 'a'];
        }
        t->isEnd = true;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [&](const string& a, const string& b) {return a.size() < b.size();});
        vector<string> ans;
        root = new Trie();
        for (string& word : words) {
            if (word.empty())
                continue;
            if (dfs(word, 0))
                ans.push_back(word);
            else 
                insert(word);
        }
        return ans;
    }
};
#endif