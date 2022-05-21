/*
 * @Author: LetMeFly
 * @Date: 2021-07-24 11:23:56
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-07-24 11:34:34
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

// class Solution // 忽然想到不是输出而是返回
// {
// public:
//     string maximumTime(string time)
//     {
//         // 时
//         if(time[0]=='?')
//         {
//             if(time[1]=='?')
//             {
//                 printf("23:");
//             }
//             else
//             {
//                 if(time[1]>'3')
//                 {
//                     printf("1%c:",time[1]);
//                 }
//                 else
//                 {
//                     printf("2%c:",time[1]);
//                 }                
//             }
            
//         }
//         else
//         {
//             if(time[1]=='?')
//             {
//                 if(time[0]=='2')
//                 {
//                     printf("23:");
//                 }
//                 else
//                 {
//                     printf("%c9:",time[0]);
//                 }                
//             }
//             else
//             {
//                 printf("%c%c:",time[0],time[1]);
//             }            
//         }
//         // 分
//         printf("%c%c",time[3]=='?'?'5':time[3], time[4]=='?'?'9':time[4]);
//     }
// };


class Solution
{
public:
    string maximumTime(string time)
    {
        // 时
        if(time[0]=='?')
        {
            if(time[1]=='?')
            {
                // printf("23:");
                time[0]='2';
                time[1]='3';
            }
            else
            {
                if(time[1]>'3')
                {
                    // printf("1%c:",time[1]);
                    time[0]='1';
                }
                else
                {
                    // printf("2%c:",time[1]);
                    time[0]='2';
                }                
            }
        }
        else
        {
            if(time[1]=='?')
            {
                if(time[0]=='2')
                {
                    // printf("23:");
                    time[1]='3';
                }
                else
                {
                    // printf("%c9:",time[0]);
                    time[1]='9';
                }                
            }
            else
            {
                // printf("%c%c:",time[0],time[1]);
            }            
        }
        // 分
        // printf("%c%c",time[3]=='?'?'5':time[3], time[4]=='?'?'9':time[4]);
        if(time[3]=='?')time[3]='5';
        if(time[4]=='?')time[4]='9';
        return time;
    }
};