/*
 * @Author: LetMeFly
 * @Date: 2022-08-02 11:00:56
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-02 11:43:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
#define dbg(x) cout << #x << " = " << x << endl
#endif

#ifdef FirstTry  // Error
class MyCircularQueue {
private:
    int head, num;
    int size;
    int* a;
public:
    MyCircularQueue(int k): head(0), num(0), size(k) {
        a = new int[k];
    }

    ~MyCircularQueue() {
        delete[] a;
    }
    
    bool enQueue(int value) {
        if (num == size)
            return false;
        // dbg(size);  //*****************
        // dbg((head + num - 1) % size);  //*****************
        // dbg(head);  //*****************
        // dbg(num);  //*****************
        // assert((head + num - 1) % size < size && (head + num - 1) % size >= 0);  //*****************
        a[(head + num - 1 + size) % size] = value;
        num++;
        return true;
    }
    
    bool deQueue() {
        if (!num)
            return false;
        head = (head + 1) % size;
        num--;
        return true;
    }
    
    int Front() {
        // assert(head >= 0 && head < size);  //***************
        return num ? a[head] : -1;
    }
    
    int Rear() {
        // assert((head + num - 1) % size < size && (head + num - 1) % size >= 0);  //*****************
        return num? a[(head + num - 1 + size) % size] : -1;
    }
    
    bool isEmpty() {
        return !num;
    }
    
    bool isFull() {
        return num == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
#else  // FirstTry
#ifdef SecondTry  // Error
class MyCircularQueue {
private:
    int head, num;
    int size;
    int* a;
public:
    MyCircularQueue(int k): head(0), num(0), size(k), a(new int[k]) {

    }

    ~MyCircularQueue() {
        delete[] a;
    }
    
    bool enQueue(int value) {
        if (num == size)
            return false;
        a[(head + num - 1 + size) % size] = value;
        num++;
        return true;
    }
    
    bool deQueue() {
        if (!num)
            return false;
        head = (head + 1) % size;
        return true;
    }
    
    int Front() {
        return num ? a[head] : -1;
    }
    
    int Rear() {
        return num ? a[(head + num - 1 + size) % size] : -1;
    }
    
    bool isEmpty() {
        return !num;
    }
    
    bool isFull() {
        return num == size;
    }
};
#else  // SecondTry
// ThirdTry  // Copy
class MyCircularQueue {
private:
    int front;
    int rear;
    int capacity;
    vector<int> elements;

public:
    MyCircularQueue(int k) {
        this->capacity = k + 1;
        this->elements = vector<int>(capacity);
        rear = front = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        elements[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return elements[front];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return elements[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return rear == front;
    }

    bool isFull() {
        return ((rear + 1) % capacity) == front;
    }
};
#endif  // SecondTry
#endif  // FirstTry

#ifdef _WIN32
int main() {
    MyCircularQueue q(3);
    dbg(q.enQueue(1));
    dbg(q.enQueue(2));
    dbg(q.enQueue(3));
    dbg(q.enQueue(4));
    dbg(q.Rear());
    dbg(q.isFull());
    dbg(q.deQueue());
    dbg(q.enQueue(4));
    dbg(q.Rear());
    system("pause");
    return 0;
}
#endif