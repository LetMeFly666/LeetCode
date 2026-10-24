/*
 * @Author: LetMeFly
 * @Date: 2026-10-24 12:01:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-24 12:12:35
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    static constexpr int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    inline pair<int, int> parse(const string& s) {
        return {(s[0] - '0') * 10 + s[1] - '0', (s[3] - '0') * 10 + s[4] - '0'};
    }

    inline bool earlier(int am, int ad, int bm, int bd) {
        return am == bm ? ad < bd : am < bm;
    }
public:
    int countDaysTogether(const string& arriveAlice, const string& leaveAlice, const string& arriveBob, const string& leaveBob) {
        auto [aam, aad] = parse(arriveAlice);  // AliceArriveMonth, AliceArriveDay
        auto [bam, bad] = parse(arriveBob);
        auto [alm, ald] = parse(leaveAlice);
        auto [blm, bld] = parse(leaveBob);
        if (earlier(bam, bad, aam, aad)) {  // Bob来的比Alice早
            swap(aam, bam);
            swap(aad, bad);
            swap(alm, blm);
            swap(ald, bld);
        }

        // (bam, bad) -> (alm, ald)
        int ans = 0;
        if (alm > bam) {
            ans = days[bam - 1] - bad + 1;
        }
        for (int m = bam + 1; m < alm; m++) {
            ans += days[m - 1];
        }
        ans += ald;
        if (bam == alm) {
            ans +
        }
        return ans;
    }
};
