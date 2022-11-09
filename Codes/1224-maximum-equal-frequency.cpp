/*
 * @Author: LetMeFly
 * @Date: 2022-08-18 09:05:24
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-18 09:46:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

void debugMap(unordered_map<int, int> ma) {
    for (auto[a, b] : ma) {
        cout << "[" << a << ", " << b << "], ";
    }
    puts("");
}

#ifdef FirstTry  // Error
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> cnt;
        unordered_map<int, int> freq;
        int ans = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 12) {
                printf("Debug\n");
            }
            int newFreq = ++cnt[nums[i]];
            freq[newFreq]++;
            if (newFreq != 1) {
                freq[newFreq - 1]--;
            }
            if (!freq[newFreq - 1]) {
                freq.erase(freq[newFreq - 1]);
            }
            bool couldThis = false;
            if (freq.size() == 1 && freq.begin()->second == 1) {  // 只有一个频率，并且都只出现了一次
                couldThis = true;
            }
            else if (freq.size() == 2) {  // 只出现了两种频率
                int freq1 = freq.begin()->first;
                int freq2 = next(freq.begin())->first;
                if (freq[freq1] == 1 || freq[freq2] == 1) {  // 有一个出现频率为1
                    couldThis = true;
                }
                else if (abs(freq[freq1] - freq[freq2]) == 1) {  // 两个频率之差为1
                    couldThis = true;
                }
            }
            if (couldThis) {
                ans = max(ans, i + 1);
            }
            printf("i = %d, freq.count(2) = %d\n", i, freq.count(2));  //**********
            if (i == 12) {
                debugMap(cnt);
                debugMap(freq);
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> freq, count;
        int res = 0, maxFreq = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count[nums[i]] > 0) {
                freq[count[nums[i]]]--;
            }
            count[nums[i]]++;
            maxFreq = max(maxFreq, count[nums[i]]);
            freq[count[nums[i]]]++;
            bool ok = maxFreq == 1 ||
                    freq[maxFreq] * maxFreq + freq[maxFreq - 1] * (maxFreq - 1) == i + 1 && freq[maxFreq] == 1 ||
                    freq[maxFreq] * maxFreq + 1 == i + 1 && freq[1] == 1;
            if (ok) {
                res = max(res, i + 1);
            }
        }
        return res;
    }
};
#endif  // FirstTry


/*
[1,1,1,2,2,2,3,3,3,4,4,4,5]

*/

#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        vector<int> v = stringToVector(s);
        cout << sol.maxEqualFreq(v) << endl;
    }
    return 0;
}
#endif