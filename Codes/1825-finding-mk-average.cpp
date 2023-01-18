/*
 * @Author: LetMeFly
 * @Date: 2023-01-18 09:37:52
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-01-18 09:59:31
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error  // 不是删除最后m个数中的前k个和后k个数，而是删除m个数中的前k小数和前k大的数
typedef long long ll;
class MKAverage {
private:
    int m, k;
    ll sum;
    queue<int> middle, back;
    int num;
public:
    MKAverage(int m, int k) {
        this->m = m, this->k = k;
        sum = 0, num = 0;
    }
    
    void addElement(int thisNum) {
        num++;
        if (num <= k) {
            ;
        }
        else if (num > k && num <= m - k) {
            middle.push(thisNum);
            sum += thisNum;
        }
        else if (num > m - k && num <= m) {
            back.push(thisNum);
        }
        else {
            sum -= middle.front();
            middle.pop();
            sum += back.front();
            middle.push(back.front());
            back.pop();
            back.push(thisNum);
        }
    }
    
    int calculateMKAverage() {
        return num >= m ? sum / (m - 2 * k) : -1;
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
#else  // FirstTry
// SecondTry  // Copy From https://leetcode.cn/problems/finding-mk-average/solutions/2065696/qiu-chu-mk-ping-jun-zhi-by-leetcode-solu-sos6/
class MKAverage {
private:
    int m, k;
    queue<int> q;
    multiset<int> s1, s2, s3;
    long long sum2;
public:
    MKAverage(int m, int k) : m(m), k(k) {
        sum2 = 0;
    }

    void addElement(int num) {
        q.push(num);
        if (q.size() <= m) {
            s2.insert(num);
            sum2 += num;
            if (q.size() == m) {
                while (s1.size() < k) {
                    s1.insert(*s2.begin());
                    sum2 -= *s2.begin();
                    s2.erase(s2.begin());
                }
                while (s3.size() < k) {
                    s3.insert(*s2.rbegin());
                    sum2 -= *s2.rbegin();
                    s2.erase(prev(s2.end()));
                }
            }
            return;
        }

        if (num < *s1.rbegin()) {
            s1.insert(num);
            s2.insert(*s1.rbegin());
            sum2 += *s1.rbegin();
            s1.erase(prev(s1.end()));
        } else if (num > *s3.begin()) {
            s3.insert(num);
            s2.insert(*s3.begin());
            sum2 += *s3.begin();
            s3.erase(s3.begin());
        } else {
            s2.insert(num);
            sum2 += num;
        }

        int x = q.front();
        q.pop();
        if (s1.count(x) > 0) {
            s1.erase(s1.find(x));
            s1.insert(*s2.begin());
            sum2 -= *s2.begin();
            s2.erase(s2.begin());
        } else if (s3.count(x) > 0) {
            s3.erase(s3.find(x));
            s3.insert(*s2.rbegin());
            sum2 -= *s2.rbegin();
            s2.erase(prev(s2.end()));
        } else {
            s2.erase(s2.find(x));
            sum2 -= x;
        }
    }

    int calculateMKAverage() {
        if (q.size() < m) {
            return -1;
        }
        return sum2 / (m - 2 * k);
    }
};
#endif  // FirstTry