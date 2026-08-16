/*
 * @Author: LetMeFly
 * @Date: 2026-08-16 08:57:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-16 09:32:02
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

/*
1+1->2
2+2->1
x+3->x

先不考虑3：
则必须1 1 2 1 2... 或 2 2 1 2 1 2... (必须序)
+ 如果1特别多(且有2)，Alice拿2，Bob2，之后必须每次Alice1Bob2，2先无，Alice胜利
+ 如果2特别多(且有1)，Alice拿1，同理
是不是有1且有2的话先手必胜
有1有2的话早晚会拿到3的倍数，而Alice先手，选择一个不满足必须序的情况
+ 1比2多或2比1多，Alice先拿少的，Bob也必须拿少的，之后每次Alice都拿多的Bob只能拿少的，Bob先输
+ 1和2一样多不论是 1 1 2 1 2 1 2还是2 2 1 2 1 2 1 2，都相当于(21)...前面加了个11 或 (12)...前面加了个22，相当于先手Alice多消耗了一个后手Bob的棋子，Alice必胜
如果只有1：Alice败；如果只有2：Alice败

现在考虑3：
3相当于跳跃牌，可以跳过一轮游戏（拿3等于没拿）
偶数个跳跃牌相当于没有，必胜者一定不会首先使用跳跃牌，必败者要么(暂时)不使用跳跃牌早晚会败，要么使用跳跃牌(对手立刻紧接着使用一张跳跃牌)延缓死亡时间
奇数个跳跃牌相当于1个(另外的偶数个抵消了)，无3情况下的必败者一定会使用跳跃牌交换两人位置，扭转必败为必胜

*/
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};
        for (int t : stones) {
            cnt[t % 3]++;
        }
        return (cnt[1] && cnt[2]) ^ (cnt[0] % 2);
    }
};
