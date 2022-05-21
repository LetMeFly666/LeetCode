// /*
//  * @Author: LetMeFly
//  * @Date: 2021-10-05 14:00:40
//  * @LastEditors: LetMeFly
//  * @LastEditTime: 2021-10-05 14:09:48
//  */
// #include <bits/stdc++.h>
// using namespace std;
// #define mem(a) memset(a, 0, sizeof(a))
// #define dbg(x) cout << #x << " = " << x << endl
// #define fi(i, l, r) for (int i = l; i < r; i++)
// #define cd(a) scanf("%d", &a)
// typedef long long ll;
// /*
//  * Below is the interface for Iterator, which is already defined for you.
//  * **DO NOT** modify the interface for Iterator.
//  *
//  *  class Iterator {
//  *		struct Data;
//  * 		Data* data;
//  *  public:
//  *		Iterator(const vector<int>& nums);
//  * 		Iterator(const Iterator& iter);
//  *
//  * 		// Returns the next element in the iteration.
//  *		int next();
//  *
//  *		// Returns true if the iteration has more elements.
//  *		bool hasNext() const;
//  *	};
//  */

// class Iterator {
// 	struct Data;
// 	Data* data;
// public:
// 	Iterator(const vector<int>& nums);
// 	Iterator(const Iterator& iter);
// 	// Returns the next element in the iteration.
// 	int next();
// 	// Returns true if the iteration has more elements.
// 	bool hasNext() const;
// };

// class PeekingIterator : public Iterator {
//     int loc;
//     const vector<int> *num;
// public:
// 	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
// 	    // Initialize any member here.
// 	    // **DO NOT** save a copy of nums and manipulate it directly.
// 	    // You should only use the Iterator interface methods.
// 	    loc = 0;
//         num = &nums;
// 	}
	
//     // Returns the next element in the iteration without advancing the iterator.
// 	int peek() {
//         return (*num)[loc];
// 	}
	
// 	// hasNext() and next() should behave the same as in the Iterator interface.
// 	// Override them if needed.
// 	int next() {
// 	    return (*num)[loc++];
// 	}
	
// 	bool hasNext() const {
// 	    return loc < (*num).size();
// 	}
// };

// 官方题解
class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        flag = Iterator::hasNext();
        if (flag) {
            nextElement = Iterator::next();
        }
    }
    
    int peek() {
        return nextElement;
    }
    
    int next() {
        int ret = nextElement;
        flag = Iterator::hasNext();
        if (flag) {
            nextElement = Iterator::next();
        }
        return ret;
    }
    
    bool hasNext() const {
        return flag;
    }
private:
    int nextElement;
    bool flag;
};