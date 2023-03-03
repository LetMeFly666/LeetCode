/*
 * @Author: LetMeFly
 * @Date: 2023-03-03 10:11:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-03 11:02:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> ma;
        vector<string> ans;
        for (auto& name : names) {
            string thisName = name;
            if (ma.count(name)) {
                thisName += "(" + to_string(ma[name]) + ")";
            }
            ans.push_back(thisName);
            ma[name]++;
        }
        return ans;
    }
};
#else  // FirstTry
#ifdef SecondTry  // TLE  // 如果文件名全是a，那么复杂度就变成n^2了
class Solution {
private:
    string nameAndSuffix(string& name, int suffix) {
        if (suffix) {
            return name + "(" + to_string(suffix) + ")";
        }
        else {
            return name;
        }
    }
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_set<string> se;
        vector<string> ans;
        for (string& name : names) {
            int nowSuffix = 0;
            string fullName = name;
            while (se.count(fullName)) {
                fullName = nameAndSuffix(name, ++nowSuffix);
            }
            se.insert(fullName);
            ans.push_back(fullName);
        }
        return ans;
    }
};
#else  // SecondTry
// ThirdTry  // 哈希表，有点像第一次尝试和第二次尝试的结合
/*
第一次尝试错在天真地以为“记录xxx到了(2)”就可以了，因此可能会有命名重复的现象（可以用户直接创建一个名为“aa(1)”的文件，再创建两个名为“aa”的文件，这样天真地把第二次“aa”命名为“aa(1)”的话就命名重复了
第二次尝试错在完全没有记录xxx到了(2)，因此假设用户创建了100000个名为“aa”的文件，那么时间复杂度就变成了n^2
正确的做法是，“记录xxx到了(2)”的同时，在确定新的文件名之前，判断新的文件名是否存在（弥补了方案1的不足）。这样即使用户创建10000个名为“aa”的文件，也不会每次都从“aa(1)”开始尝试重命名（弥补了方案2的不足）
*/
class Solution {
private:
    string nameAndSuffix(string& name, int suffix) {
        if (suffix) {
            return name + "(" + to_string(suffix) + ")";
        }
        else {
            return name;
        }
    }
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> ma;
        vector<string> ans;
        for (string& name : names) {
            if (!ma.count(name)) {
                ans.push_back(name);
                ma[name] = 1;
            }
            else {
                int times = ma[name];
                string newName = nameAndSuffix(name, times);
                while (ma.count(newName)) {
                    newName = nameAndSuffix(name, ++times);
                }
                ans.push_back(newName);
                ma[name] = times + 1;
                ma[newName] = 1;
            }
        }
        return ans;
    }
};
#endif  // SecondTry
#endif  // FirstTry