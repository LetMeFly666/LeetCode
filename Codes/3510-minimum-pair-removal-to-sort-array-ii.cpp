/*
 * @Author: LetMeFly
 * @Date: 2026-01-23 20:28:25
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-23 21:24:26
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif


typedef long long ll;
typedef pair<ll, int> node;  // <nums[idx]+nums[right(idx)], idx>
class Solution {
public:
    int minimumPairRemoval(vector<int>& numsInt) {
        vector<ll> nums(numsInt.begin(), numsInt.end());
        set<node> nodes;
        set<int> idxs;
        int cntRev = 0;
        for (int i = 0; i + 1 < nums.size(); i++) {
            idxs.insert(i);
            nodes.insert({nums[i] + nums[i + 1], i});
            cntRev += nums[i] > nums[i + 1];
        }
        idxs.insert(numsInt.size() - 1);

        int ans = 0;
        while (cntRev) {
            set<node>::iterator nodeIt = nodes.begin();
            ll nodeVal = nodeIt->first;
            int nodeIdx = nodeIt->second;
            nodes.erase(nodeIt);

            set<int>::iterator idxIt = idxs.find(nodeIdx);
            set<int>::iterator secondIdxIt = next(idxIt);  // 一定有next
            cntRev -= nums[*idxIt] > nums[*secondIdxIt];
            
            // 左
            if (idxIt != idxs.begin()) {
                set<int>::iterator lIdxIt = prev(idxIt);
                node lNode = node{nums[*lIdxIt] + nums[*idxIt], *lIdxIt};
                nodes.erase(lNode);
                node lNodeNew = node{lNode.first + nums[*secondIdxIt], *lIdxIt};
                nodes.insert(lNodeNew);
                cntRev -= nums[*lIdxIt] > nums[*idxIt];
                cntRev += nums[*lIdxIt] > nodeVal;
            }

            // 右
            set<int>::iterator rIdxIt = next(secondIdxIt);
            if (rIdxIt != idxs.end()) {
                node rNode = node{nums[*secondIdxIt] + nums[*rIdxIt], *secondIdxIt};
                nodes.erase(rNode);
                node rNodeNew = node{nodeVal + nums[*rIdxIt], *idxIt};
                nodes.insert(rNodeNew);
                cntRev -= nums[*secondIdxIt] > nums[*rIdxIt];
                cntRev += nodeVal > nums[*rIdxIt];
            }

            nums[*idxIt] = nodeVal;
            idxs.erase(secondIdxIt);
            ans++;
        }
        return ans;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
[5,2,3,1]

2
*/
/*
[-2,1,2,-1,-1,-2,-2,-1,-1,1,1]


*/
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        vector<int> v = stringToVector(s);
        cout << sol.minimumPairRemoval(v) << endl;
    }
    return 0;
}
#endif