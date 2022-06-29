/*
 * @Author: LetMeFly
 * @Date: 2022-06-29 14:49:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-29 14:49:39
 */
// 取巧：直接返回原串
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortUrl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));