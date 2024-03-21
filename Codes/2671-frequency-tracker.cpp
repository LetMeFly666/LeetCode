/*
 * @Author: LetMeFly
 * @Date: 2024-03-21 11:32:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-21 22:16:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class FrequencyTracker {
private:
    unordered_map<int, int> val2times, times2times;
public:
    FrequencyTracker() {
        
    }
    
    void add(int number, int diff=1) {
        int originalTimes = val2times[number];
        val2times[number] += diff;
        times2times[originalTimes]--;
        times2times[originalTimes + diff]++;
    }
    
    void deleteOne(int number) {
        if (val2times[number]) {
            add(number, -1);
        }
    }
    
    bool hasFrequency(int frequency) {
        return times2times[frequency];
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */