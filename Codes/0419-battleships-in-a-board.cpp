/*
 * @Author: LetMeFly
 * @Date: 2021-12-18 20:03:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-18 20:22:52
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
vector<char> stringToVectorC(string s)  // [1,2,5]
{
    vector<char>v;
    s=s.substr(1, s.size()).substr(0, s.size()-1);
    vector<string>vs=split(s, ',');
    for(int i=0;i<vs.size();i++)
    {
        string temp=vs[i];
        v.push_back(temp[1]);
    }
    return v;
}

vector<vector<char>> stringToVectorVectorC(string s) //[[1,2,5],[2,5,6],[5,6]]
{
    vector<vector<char>>ans;
    s.erase(s.begin());
    s.erase(s.begin());
    s.erase(--s.end());
    s.erase(--s.end());
    vector<string> temp = split(s,"],[");
    for(string&s:temp)
    {
        s='['+s+']';
        ans.push_back(stringToVectorC(s));
    }
    return ans;
}
#endif

#ifdef _WIN32
class Solution {
private:
    int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int tx = x + direction[i][0];
            int ty = y + direction[i][1];
            if (tx >= 0 && tx < board.size() && ty >= 0 && ty < board[0].size() && !visited[tx][ty] && board[tx][ty] == 'X') {
                visited[tx][ty] = true;
                dfs(board, visited, tx, ty);
            }
        }
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        vector<vector<bool>>visited(board.size());
        for (int i = 0; i < board.size(); i++)
            visited[i].resize(board[0].size());
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (!visited[i][j]) {
                    visited[i][j] = true;
                    if (board[i][j] == 'X') {
                        ans++;
                        dfs(board, visited, i, j);
                    }
                }
            }
        }
        return ans;
    }
};
#else
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        int ans = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) { 
                if (board[i][j] == 'X') {
                    if (i > 0 && board[i - 1][j] == 'X') {
                        continue;
                    }
                    if (j > 0 && board[i][j - 1] == 'X') {
                        continue;
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};
#endif

#ifdef _WIN32
int main() {
    string s;
    Solution sol;
    while (cin >> s) {
        vector<vector<char>> v = stringToVectorVectorC(s);
        debug(v);
        cout << sol.countBattleships(v) << endl;
    }
    return 0;
}
#endif