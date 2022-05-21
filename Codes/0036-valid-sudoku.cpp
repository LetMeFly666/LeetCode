/*
 * @Author: LetMeFly
 * @Date: 2021-09-17 10:35:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-09-17 10:44:22
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
class Solution
{
private:
    bool validRow(vector<vector<char>> &a, int line)
    {
        int bin[10]={0};
        for(int j=0;j<9;j++)
        {
            if (a[line][j]>='1'&&a[line][j]<='9')
            {
                if(++bin[a[line][j]-'1']>1)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool validLine(vector<vector<char>> &a, int row)
    {
        int bin[10]={0};
        for(int i=0;i<9;i++)
        {
            if (a[i][row]>='1'&&a[i][row]<='9')
            {
                if(++bin[a[i][row]-'1']>1)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool validQu(vector<vector<char>> &a, int row, int line)
    {
        int bin[10]={0};
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(a[row+i][line+j]>='1'&&a[row+i][line+j]<='9')
                    if(++bin[a[row+i][line+j]-'1']>1)
                        return false;
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for(int i=0;i<9;i++)
            if(!validLine(board,i)||!validRow(board,i))
                return false;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(!validQu(board, i*3, j*3))
                    return false;
        return true;
    }
};