/*
 * @Author: LetMeFly
 * @Date: 2021-08-23 13:41:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-23 13:46:55
 */

int num[105];
class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        num[0]=0,num[1]=1;
        if(n==0)return 0;
        int from=1;
        while(1)
        {
            num[from*2]=num[from];
            num[from*2+1]=num[from]+num[from+1];
            if(from*2+1>=n)break;
            from++;
        }
        int M=1;
        for(int i=2;i<=n;i++)
            M=max(M,num[i]);
        return M;
    }
};