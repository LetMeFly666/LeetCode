/*
 * @Author: LetMeFly
 * @Date: 2022-06-05 09:15:15
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-05 10:15:41
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
/* 
极坐标：随机角度 + 随机半径
错误！！！！
这样生成的点会更靠近圆心。
*/
const double PI = acos(-1);

inline double rand(double l, double r) {
    return (double)1 * rand() * (r - l) / RAND_MAX + l;
}

inline double rand(double r) {
    return rand(0, r);
}

class Solution {
private:
    double radius;
    double x_center;
    double y_center;
public:
    Solution(double radius, double x_center, double y_center) {
        srand(time(NULL));
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    vector<double> randPoint() {
        vector<double> ans(2);
        double degree = rand(2 * PI);
        double r = rand(radius);
        ans[0] = r * cos(degree) + x_center;
        ans[1] = r * sin(degree) + y_center;
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

#else  // FirstTry
#ifdef SecondTry  // 随机在正方形中放点，不在圆内的话继续
const double PI = acos(-1);

inline double rand(double l, double r) {
    return (double)1 * rand() * (r - l) / RAND_MAX + l;
}

inline double rand(double r) {
    return rand(0, r);
}

class Solution {
private:
    double radius;
    double x_center;
    double y_center;
public:
    Solution(double radius, double x_center, double y_center) {
        srand(time(NULL));
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    vector<double> randPoint() {
        double x, y;
        while (true) {
            x = rand(-radius, radius);
            y = rand(-radius, radius);
            if (sqrt(x * x + y * y) <= radius) {
                break;
            }
        }
        return {x + x_center, y + y_center};
    }
};
#else  // SecondTry
const double PI = acos(-1);

inline double rand(double l, double r) {
    return (double)1 * rand() * (r - l) / RAND_MAX + l;
}

inline double rand(double r) {
    return rand(0, r);
}

class Solution {
private:
    double radius;
    double x_center;
    double y_center;
public:
    Solution(double radius, double x_center, double y_center) {
        srand(time(NULL));
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    vector<double> randPoint() {
        double area = rand(PI * radius * radius);
        double r = sqrt(area / PI);
        double degree = rand(PI * 2);
        return {x_center + r * cos(degree), y_center + r * sin(degree)};
    }
};
#endif  // SecondTry
#endif  // FirstTry

#ifdef _WIN32
int main() {
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis(5, 15);
    for (int i = 0; i < 100; i++) {
        double r = dis(gen);
        cout << r << endl;
    }
    system("pause");
    return 0;
}
#endif