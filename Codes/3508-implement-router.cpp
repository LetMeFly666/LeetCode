/*
 * @Author: LetMeFly
 * @Date: 2025-09-20 16:10:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-20 17:38:56
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

/*
FIFO: 一个数组一个指针
是否重复：一个哈希表
Find：哈希表+有序集合

啊，我不想写了
*/
inline void hash_combine(size_t &seed, size_t h) {
    seed ^= h + 0x9e3779b97f4a7c15ULL + (seed << 6) + (seed >> 2);
}

struct TupleHash {
    size_t operator()(const tuple<int, int, int>& t) const noexcept {
        size_t seed = 0;
        hash_combine(seed, hash<int>{}(get<0>(t)));
        hash_combine(seed, hash<int>{}(get<1>(t)));
        hash_combine(seed, hash<int>{}(get<2>(t)));
        return seed;
    }
};

struct TupleEq {
    bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) const noexcept {  // 记得const noexcept（好难记）
        return a == b;
    }
};

class Router {
private:
    vector<tuple<int, int, int>> fifo;
    int fifoLeft, fifoRight, memoryLimit;
    unordered_set<tuple<int, int, int>, TupleHash, TupleEq> already;
    unordered_map<int, pair<vector<int>, int>> finder;  // destination -> <[timestamp], 有效范围>

    void removePacket() {  // remove fifoLeft，不判断是否为空
        tuple<int, int, int> toRemove = fifo[fifoLeft];
        already.erase(toRemove);
        finder[get<1>(toRemove)].second++;
        fifoLeft = (fifoLeft + 1) % (memoryLimit + 1);
    }
public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
        fifo.resize(memoryLimit + 1);  // 多开一个区分空和满
        fifoLeft = fifoRight = 0;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        tuple<int, int, int> package = tuple(source, destination, timestamp);
        if (already.count(package)) {
            return false;
        }
        already.insert(package);
        if ((fifoRight + 1) % (memoryLimit + 1) == fifoLeft) {  // remove fifo[fifoLeft]
            removePacket();
        }
        fifo[fifoRight] = package;
        fifoRight = (fifoRight + 1) % (memoryLimit + 1);
        finder[destination].first.push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (fifoLeft == fifoRight) {
            return {};
        }
        auto [source, destination, timeStamp] = fifo[fifoLeft];
        removePacket();
        return {source, destination, timeStamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto&& [timeStamps, startIdx] = finder[destination];
        return upper_bound(timeStamps.begin() + startIdx, timeStamps.end(), endTime) - lower_bound(timeStamps.begin() + startIdx, timeStamps.end(), startTime);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */