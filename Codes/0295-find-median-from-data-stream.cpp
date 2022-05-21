/*
 * @Author: LetMeFly
 * @Date: 2021-08-27 10:29:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-27 10:29:18
 */
// copy from web
class MedianFinder {
    multiset<int> nums;
    multiset<int>::iterator left, right;

public:
    MedianFinder() : left(nums.end()), right(nums.end()) {}

    void addNum(int num) {
        const size_t n = nums.size();

        nums.insert(num);
        if (!n) {
            left = right = nums.begin();
        } else if (n & 1) {
            if (num < *left) {
                left--;
            } else {
                right++;
            }
        } else {
            if (num > *left && num < *right) {
                left++;
                right--;
            } else if (num >= *right) {
                left++;
            } else {
                right--;
                left = right;
            }
        }
    }

    double findMedian() {
        return (*left + *right) / 2.0;
    }
};
