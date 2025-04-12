/*
 * @Author: LetMeFly
 * @Date: 2025-04-12 07:51:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-12 09:20:21
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

/*
1 -> 1-9
2 -> 1-9
3 -> 10->99
4 -> 10->99
5 -> 100->999
6 -> 100->999

n -> [10^((n-1)/2-1), 10^((n-1)/2)-1)
*/
typedef long long ll;

class Solution {
private:
    int k;
    unordered_set<string> visited;
    vector<int> factor;
    int times[10];

    void initFactor(int n) {
        factor.resize(n + 1);
        factor[0] = 1;
        for (int i = 1; i <= n; i++) {
            factor[i] = factor[i - 1] * i;
        }
    }

    bool ifVisited(string s) {
        bool debug = false;
        if (s == "21012") {
            cout << "debug: ifVisited(21012)" << endl;
            debug = true;
        }
        sort(s.begin(), s.end());
        if (debug) {
            cout << "sorted(s): " << s << endl;
            cout << "visited(s): " << visited.count(s) << endl;
            for (string s : visited) {
                cout << s << ", ";
            }
            puts("");
        }
        if (visited.count(s)) {
            return true;
        }
        visited.insert(s);
        return false;
    }
    
    bool isOk(string& s) {
        ll val = stoll(s);
        // printf("%s: %d\n", s.c_str(), val % k == 0);  // *****
        return val % k == 0;
    };

    ll calc(string& s) {
        memset(times, 0, sizeof(times));
        for (char c : s) {
            times[c - '0']++;
        }
        ll ans = (s.size() - times[0]) * factor[s.size() - 1];
        for (int i = 0; i < 10; i++) {
            ans /= factor[times[i]];
        }
        return ans;
    }
public:
    ll countGoodIntegers(int n, int k) {
        initFactor(n);
        this->k = k;
        ll ans = 0;
        for (int start = pow(10, (n - 1) / 2), end = start * 10; start < end; start++) {
            string prefix = to_string(start), suffix = prefix.substr(0, prefix.size() - n % 2);
            reverse(suffix.begin(), suffix.end());
            string thisNum = prefix + suffix;
            if (start == 210) {
                cout << thisNum << ": " << isOk(thisNum) << endl;
            }
            if (!ifVisited(thisNum) && isOk(thisNum)) {
                printf("ans: %lld, calc(%s): %lld, ans = ans + calc(%s) = %lld\n", ans, thisNum.c_str(), calc(thisNum), thisNum.c_str(), ans + calc(thisNum));  // ****
                ans += calc(thisNum);
            }
        }
        return ans;
    }
};

/*
ans: 0, calc(20202): 6, ans = ans + calc(20202) = 6
ans: 6, calc(20502): 18, ans = ans + calc(20502) = 24
ans: 24, calc(20802): 18, ans = ans + calc(20802) = 42
ans: 42, calc(22122): 5, ans = ans + calc(22122) = 47
ans: 47, calc(22422): 5, ans = ans + calc(22422) = 52
ans: 52, calc(22722): 5, ans = ans + calc(22722) = 57
ans: 57, calc(23232): 10, ans = ans + calc(23232) = 67
ans: 67, calc(23532): 30, ans = ans + calc(23532) = 97
ans: 97, calc(23832): 30, ans = ans + calc(23832) = 127
ans: 127, calc(24042): 24, ans = ans + calc(24042) = 151
ans: 151, calc(24342): 30, ans = ans + calc(24342) = 181
ans: 181, calc(24642): 30, ans = ans + calc(24642) = 211
ans: 211, calc(24942): 30, ans = ans + calc(24942) = 241
ans: 241, calc(25152): 30, ans = ans + calc(25152) = 271
ans: 271, calc(25452): 30, ans = ans + calc(25452) = 301
ans: 301, calc(25752): 30, ans = ans + calc(25752) = 331
ans: 331, calc(26262): 10, ans = ans + calc(26262) = 341
ans: 341, calc(26562): 30, ans = ans + calc(26562) = 371
ans: 371, calc(26862): 30, ans = ans + calc(26862) = 401
ans: 401, calc(27072): 24, ans = ans + calc(27072) = 425
ans: 425, calc(27372): 30, ans = ans + calc(27372) = 455
ans: 455, calc(27672): 30, ans = ans + calc(27672) = 485
ans: 485, calc(27972): 30, ans = ans + calc(27972) = 515
ans: 515, calc(28182): 30, ans = ans + calc(28182) = 545
ans: 545, calc(28482): 30, ans = ans + calc(28482) = 575
ans: 575, calc(28782): 30, ans = ans + calc(28782) = 605
ans: 605, calc(29292): 10, ans = ans + calc(29292) = 615
ans: 615, calc(29592): 30, ans = ans + calc(29592) = 645
ans: 645, calc(29892): 30, ans = ans + calc(29892) = 675
ans: 675, calc(40104): 18, ans = ans + calc(40104) = 693
ans: 693, calc(40404): 6, ans = ans + calc(40404) = 699
ans: 699, calc(40704): 18, ans = ans + calc(40704) = 717
ans: 717, calc(44244): 5, ans = ans + calc(44244) = 722
ans: 722, calc(44544): 5, ans = ans + calc(44544) = 727
ans: 727, calc(44844): 5, ans = ans + calc(44844) = 732
ans: 732, calc(45054): 24, ans = ans + calc(45054) = 756
ans: 756, calc(45354): 30, ans = ans + calc(45354) = 786
ans: 786, calc(45654): 30, ans = ans + calc(45654) = 816
ans: 816, calc(45954): 30, ans = ans + calc(45954) = 846
ans: 846, calc(46164): 30, ans = ans + calc(46164) = 876
ans: 876, calc(46464): 10, ans = ans + calc(46464) = 886
ans: 886, calc(46764): 30, ans = ans + calc(46764) = 916
ans: 916, calc(47274): 30, ans = ans + calc(47274) = 946
ans: 946, calc(47574): 30, ans = ans + calc(47574) = 976
ans: 976, calc(47874): 30, ans = ans + calc(47874) = 1006
ans: 1006, calc(48084): 24, ans = ans + calc(48084) = 1030
ans: 1030, calc(48384): 30, ans = ans + calc(48384) = 1060
ans: 1060, calc(48684): 30, ans = ans + calc(48684) = 1090
ans: 1090, calc(48984): 30, ans = ans + calc(48984) = 1120
ans: 1120, calc(49194): 30, ans = ans + calc(49194) = 1150
ans: 1150, calc(49494): 10, ans = ans + calc(49494) = 1160
ans: 1160, calc(49794): 30, ans = ans + calc(49794) = 1190
ans: 1190, calc(60006): 4, ans = ans + calc(60006) = 1194
ans: 1194, calc(60306): 18, ans = ans + calc(60306) = 1212
ans: 1212, calc(60606): 6, ans = ans + calc(60606) = 1218
ans: 1218, calc(60906): 18, ans = ans + calc(60906) = 1236
ans: 1236, calc(66066): 4, ans = ans + calc(66066) = 1240
ans: 1240, calc(66366): 5, ans = ans + calc(66366) = 1245
ans: 1245, calc(66666): 1, ans = ans + calc(66666) = 1246
ans: 1246, calc(66966): 5, ans = ans + calc(66966) = 1251
ans: 1251, calc(67176): 30, ans = ans + calc(67176) = 1281
ans: 1281, calc(67476): 30, ans = ans + calc(67476) = 1311
ans: 1311, calc(67776): 10, ans = ans + calc(67776) = 1321
ans: 1321, calc(68286): 30, ans = ans + calc(68286) = 1351
ans: 1351, calc(68586): 30, ans = ans + calc(68586) = 1381
ans: 1381, calc(68886): 10, ans = ans + calc(68886) = 1391
ans: 1391, calc(69096): 24, ans = ans + calc(69096) = 1415
ans: 1415, calc(69396): 30, ans = ans + calc(69396) = 1445
ans: 1445, calc(69696): 10, ans = ans + calc(69696) = 1455
ans: 1455, calc(69996): 10, ans = ans + calc(69996) = 1465
ans: 1465, calc(80208): 18, ans = ans + calc(80208) = 1483
ans: 1483, calc(80508): 18, ans = ans + calc(80508) = 1501
ans: 1501, calc(80808): 6, ans = ans + calc(80808) = 1507
ans: 1507, calc(88188): 5, ans = ans + calc(88188) = 1512
ans: 1512, calc(88488): 5, ans = ans + calc(88488) = 1517
ans: 1517, calc(88788): 5, ans = ans + calc(88788) = 1522
ans: 1522, calc(89298): 30, ans = ans + calc(89298) = 1552
ans: 1552, calc(89598): 30, ans = ans + calc(89598) = 1582
ans: 1582, calc(89898): 10, ans = ans + calc(89898) = 1592
*/