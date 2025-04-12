'''
Author: LetMeFly
Date: 2025-04-12 09:02:55
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-12 09:07:16
'''
from collections import Counter
from math import factorial

class Solution:
    def calc(self, s: str) -> int:
        cnt = Counter(s)
        res = (len(s) - cnt['0']) * self.fac[len(s) - 1]
        for c in cnt.values():
            res //= self.fac[c]
        return res
    
    def countGoodIntegers(self, n: int, k: int) -> int:
        self.fac = [factorial(i) for i in range(n + 1)]
        ans = 0
        vis = set()
        base = 10 ** ((n - 1) // 2)
        for i in range(base, base * 10):  # 枚举回文数左半边
            s = str(i)
            s += s[::-1][n % 2:]
            if int(s) % k:  # 回文数不能被 k 整除
                continue

            sorted_s = ''.join(sorted(s))
            if sorted_s in vis:  # 不能重复统计
                continue
            vis.add(sorted_s)

            res = self.calc(s)
            print(f'ans: {ans}, calc({s}): {res}, ans = ans + calc({s}) = {ans + res}')
            ans += res
        return ans
# Copy And Change From https://leetcode.cn/problems/find-the-count-of-good-integers/solutions/2899725/mei-ju-suo-you-hui-wen-shu-zu-he-shu-xue-3d35/
    
"""
ans: 0, calc(20202): 6, ans = ans + calc(20202) = 6
ans: 6, calc(20502): 18, ans = ans + calc(20502) = 24
ans: 24, calc(20802): 18, ans = ans + calc(20802) = 42
ans: 42, calc(21012): 24, ans = ans + calc(21012) = 66
ans: 66, calc(21312): 30, ans = ans + calc(21312) = 96
ans: 96, calc(21612): 30, ans = ans + calc(21612) = 126
ans: 126, calc(21912): 30, ans = ans + calc(21912) = 156
ans: 156, calc(22122): 5, ans = ans + calc(22122) = 161
ans: 161, calc(22422): 5, ans = ans + calc(22422) = 166
ans: 166, calc(22722): 5, ans = ans + calc(22722) = 171
ans: 171, calc(23232): 10, ans = ans + calc(23232) = 181
ans: 181, calc(23532): 30, ans = ans + calc(23532) = 211
ans: 211, calc(23832): 30, ans = ans + calc(23832) = 241
ans: 241, calc(24042): 24, ans = ans + calc(24042) = 265
ans: 265, calc(24342): 30, ans = ans + calc(24342) = 295
ans: 295, calc(24642): 30, ans = ans + calc(24642) = 325
ans: 325, calc(24942): 30, ans = ans + calc(24942) = 355
ans: 355, calc(25152): 30, ans = ans + calc(25152) = 385
ans: 385, calc(25452): 30, ans = ans + calc(25452) = 415
ans: 415, calc(25752): 30, ans = ans + calc(25752) = 445
ans: 445, calc(26262): 10, ans = ans + calc(26262) = 455
ans: 455, calc(26562): 30, ans = ans + calc(26562) = 485
ans: 485, calc(26862): 30, ans = ans + calc(26862) = 515
ans: 515, calc(27072): 24, ans = ans + calc(27072) = 539
ans: 539, calc(27372): 30, ans = ans + calc(27372) = 569
ans: 569, calc(27672): 30, ans = ans + calc(27672) = 599
ans: 599, calc(27972): 30, ans = ans + calc(27972) = 629
ans: 629, calc(28182): 30, ans = ans + calc(28182) = 659
ans: 659, calc(28482): 30, ans = ans + calc(28482) = 689
ans: 689, calc(28782): 30, ans = ans + calc(28782) = 719
ans: 719, calc(29292): 10, ans = ans + calc(29292) = 729
ans: 729, calc(29592): 30, ans = ans + calc(29592) = 759
ans: 759, calc(29892): 30, ans = ans + calc(29892) = 789
ans: 789, calc(40104): 18, ans = ans + calc(40104) = 807
ans: 807, calc(40404): 6, ans = ans + calc(40404) = 813
ans: 813, calc(40704): 18, ans = ans + calc(40704) = 831
ans: 831, calc(41214): 30, ans = ans + calc(41214) = 861
ans: 861, calc(41514): 30, ans = ans + calc(41514) = 891
ans: 891, calc(41814): 30, ans = ans + calc(41814) = 921
ans: 921, calc(43134): 30, ans = ans + calc(43134) = 951
ans: 951, calc(43434): 10, ans = ans + calc(43434) = 961
ans: 961, calc(43734): 30, ans = ans + calc(43734) = 991
ans: 991, calc(44244): 5, ans = ans + calc(44244) = 996
ans: 996, calc(44544): 5, ans = ans + calc(44544) = 1001
ans: 1001, calc(44844): 5, ans = ans + calc(44844) = 1006
ans: 1006, calc(45054): 24, ans = ans + calc(45054) = 1030
ans: 1030, calc(45354): 30, ans = ans + calc(45354) = 1060
ans: 1060, calc(45654): 30, ans = ans + calc(45654) = 1090
ans: 1090, calc(45954): 30, ans = ans + calc(45954) = 1120
ans: 1120, calc(46164): 30, ans = ans + calc(46164) = 1150
ans: 1150, calc(46464): 10, ans = ans + calc(46464) = 1160
ans: 1160, calc(46764): 30, ans = ans + calc(46764) = 1190
ans: 1190, calc(47274): 30, ans = ans + calc(47274) = 1220
ans: 1220, calc(47574): 30, ans = ans + calc(47574) = 1250
ans: 1250, calc(47874): 30, ans = ans + calc(47874) = 1280
ans: 1280, calc(48084): 24, ans = ans + calc(48084) = 1304
ans: 1304, calc(48384): 30, ans = ans + calc(48384) = 1334
ans: 1334, calc(48684): 30, ans = ans + calc(48684) = 1364
ans: 1364, calc(48984): 30, ans = ans + calc(48984) = 1394
ans: 1394, calc(49194): 30, ans = ans + calc(49194) = 1424
ans: 1424, calc(49494): 10, ans = ans + calc(49494) = 1434
ans: 1434, calc(49794): 30, ans = ans + calc(49794) = 1464
ans: 1464, calc(60006): 4, ans = ans + calc(60006) = 1468
ans: 1468, calc(60306): 18, ans = ans + calc(60306) = 1486
ans: 1486, calc(60606): 6, ans = ans + calc(60606) = 1492
ans: 1492, calc(60906): 18, ans = ans + calc(60906) = 1510
ans: 1510, calc(61116): 10, ans = ans + calc(61116) = 1520
ans: 1520, calc(61416): 30, ans = ans + calc(61416) = 1550
ans: 1550, calc(61716): 30, ans = ans + calc(61716) = 1580
ans: 1580, calc(63036): 24, ans = ans + calc(63036) = 1604
ans: 1604, calc(63336): 10, ans = ans + calc(63336) = 1614
ans: 1614, calc(63636): 10, ans = ans + calc(63636) = 1624
ans: 1624, calc(63936): 30, ans = ans + calc(63936) = 1654
ans: 1654, calc(65256): 30, ans = ans + calc(65256) = 1684
ans: 1684, calc(65556): 10, ans = ans + calc(65556) = 1694
ans: 1694, calc(65856): 30, ans = ans + calc(65856) = 1724
ans: 1724, calc(66066): 4, ans = ans + calc(66066) = 1728
ans: 1728, calc(66366): 5, ans = ans + calc(66366) = 1733
ans: 1733, calc(66666): 1, ans = ans + calc(66666) = 1734
ans: 1734, calc(66966): 5, ans = ans + calc(66966) = 1739
ans: 1739, calc(67176): 30, ans = ans + calc(67176) = 1769
ans: 1769, calc(67476): 30, ans = ans + calc(67476) = 1799
ans: 1799, calc(67776): 10, ans = ans + calc(67776) = 1809
ans: 1809, calc(68286): 30, ans = ans + calc(68286) = 1839
ans: 1839, calc(68586): 30, ans = ans + calc(68586) = 1869
ans: 1869, calc(68886): 10, ans = ans + calc(68886) = 1879
ans: 1879, calc(69096): 24, ans = ans + calc(69096) = 1903
ans: 1903, calc(69396): 30, ans = ans + calc(69396) = 1933
ans: 1933, calc(69696): 10, ans = ans + calc(69696) = 1943
ans: 1943, calc(69996): 10, ans = ans + calc(69996) = 1953
ans: 1953, calc(80208): 18, ans = ans + calc(80208) = 1971
ans: 1971, calc(80508): 18, ans = ans + calc(80508) = 1989
ans: 1989, calc(80808): 6, ans = ans + calc(80808) = 1995
ans: 1995, calc(81018): 24, ans = ans + calc(81018) = 2019
ans: 2019, calc(81318): 30, ans = ans + calc(81318) = 2049
ans: 2049, calc(81618): 30, ans = ans + calc(81618) = 2079
ans: 2079, calc(81918): 30, ans = ans + calc(81918) = 2109
ans: 2109, calc(83238): 30, ans = ans + calc(83238) = 2139
ans: 2139, calc(83538): 30, ans = ans + calc(83538) = 2169
ans: 2169, calc(83838): 10, ans = ans + calc(83838) = 2179
ans: 2179, calc(85158): 30, ans = ans + calc(85158) = 2209
ans: 2209, calc(85458): 30, ans = ans + calc(85458) = 2239
ans: 2239, calc(85758): 30, ans = ans + calc(85758) = 2269
ans: 2269, calc(87078): 24, ans = ans + calc(87078) = 2293
ans: 2293, calc(87378): 30, ans = ans + calc(87378) = 2323
ans: 2323, calc(87678): 30, ans = ans + calc(87678) = 2353
ans: 2353, calc(87978): 30, ans = ans + calc(87978) = 2383
ans: 2383, calc(88188): 5, ans = ans + calc(88188) = 2388
ans: 2388, calc(88488): 5, ans = ans + calc(88488) = 2393
ans: 2393, calc(88788): 5, ans = ans + calc(88788) = 2398
ans: 2398, calc(89298): 30, ans = ans + calc(89298) = 2428
ans: 2428, calc(89598): 30, ans = ans + calc(89598) = 2458
ans: 2458, calc(89898): 10, ans = ans + calc(89898) = 2468
"""