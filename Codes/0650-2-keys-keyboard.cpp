/*
 * @Author: LetMeFly
 * @Date: 2021-09-19 18:31:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-09-19 18:45:24
 */
// /*
//  * @Author: LetMeFly
//  * @Date: 2021-09-19 18:31:33
//  * @LastEditors: LetMeFly
//  * @LastEditTime: 2021-09-19 18:38:53
//  */
// #include <bits/stdc++.h>
// using namespace std;
// #define mem(a) memset(a, 0, sizeof(a))
// #define dbg(x) cout << #x << " = " << x << endl
// #define fi(i, l, r) for (int i = l; i < r; i++)
// #define cd(a) scanf("%d", &a)
// typedef long long ll;
// bool Pow[1025]={false};
// int ok[]={4,8,16,32,64,128,256,512,1024};
// class Solution {
// private:
//     void init()
//     {
//         static bool already=false;
//         if(already)return;
//         already=true;
//         for(int i=0;i<9;i++)Pow[ok[i]]=true;
//     }
// public:
//     int minSteps(int n) {
//         if(n==1)return 0;
//         int ans=1;
//         while(n>1)
//         {
//             ans++;
//             if(Pow[n])
//                 n/=2,ans++;
//             else
//                 n--;
//         }
//         return ans;
//     }
// };

// // int main()
// // {
// //     for(int i=1;i<=10;i++)
// //     {
// //         cout<<(1<<i)<<',';
// //     }
// //     system("pause");
// //     return 0;
// // }

class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        for (int i = 2; i * i <= n; ++i) {
            while (n % i == 0) {
                n /= i;
                ans += i;
            }
        }
        if (n > 1) {
            ans += n;
        }
        return ans;
    }
}; 