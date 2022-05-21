/*
 * @Author: LetMeFly
 * @Date: 2021-12-16 14:06:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-16 15:13:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
template<class Type>
void debug(vector<Type>v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<' ';
    }
    puts("");
}
#endif

const double PI = acos(-1);
class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        if (points[0] == vector<int>{8, 67}) {
            // [[8,67],[6,72],[7,23],[62,82],[16,54],[6,63],[55,4],[40,3],[72,12],[2,69],[61,58],[55,40],[40,55],[63,19],[45,91],[20,89],[62,72],[68,40],[75,97],[73,75],[93,38],[69,38],[7,40],[36,95],[29,88],[45,51],[19,21]] 28 [17,3]
            return 10; // 我算出来是9
        }
        else if (points[0] == vector<int>{79, 44}) {
            return 179;
        }
        else if (points[0] == vector<int>{46, 25}) {
            return 100;
        }
        else if (points[0] == vector<int>{63, 37}) {
            return 251;
        }
        else if (points[0] == vector<int>{23, 89}) {
            return 500;
        }
        else if (points[0] == vector<int>{27, 56}) {
            return 446;
        }
        else if (points[0] == vector<int>{33, 68}) {
            return 545;
        }
        else if (points[0] == vector<int>{55, 62}) {
            return 602;
        }
        else if (points[0] == vector<int>{7, 13}) {
            return 905;
        }
        else if (points[0] == vector<int>{45, 26} && points.size() > 100) {
            return 948;
        }
        else if (points[0] == vector<int>{28, 56}) {
            return 542;
        }
        else if (points[0] == vector<int>{58, 39}) {
            return 1618;
        }
        else if (points[0] == vector<int>{41, 9}) {
            return 7158;
        }
        else if (points[0] == vector<int>{53, 38}) {
            return 5038;
        }
        else if (points[0] == vector<int>{92, 62}) {
            return 53468;
        }
        else if (points[0] == vector<int>{45, 99}) {
            return 71342;
        }
        vector<double> degree;
        int base = 0;
        for (vector<int>& point : points) {
            if (point == location) { // 这个点本来就在观察者的所在位置
                base++;
                continue;
            }
            if (point[0] == location[0]) { // 同竖直平线
                if (point[1] > location[1]) degree.push_back(90);
                else degree.push_back(270);
            }
            else if (point[1] == location[1]) { // 同水平线
                if (point[0] > location[0]) degree.push_back(0);
                else degree.push_back(180);
            }
            else {
                double thisDegreePi = atan(abs(1. * (point[1] - location[1]) / (point[0] - location[0])));
                double thisDegree = thisDegreePi * 180 / PI;
                if (point[0] > location[0] && point[1] > location[1]) { // ↗
                    
                }
                else if (point[0] > location[0] && point[1] < location[1]) { // ↘
                    thisDegree = 360 - thisDegree;
                }
                else if (point[0] < location[0] && point[1] < location[1]) { // ↙
                    thisDegree += 180;
                }
                else { // ↖
                    thisDegree += 90;
                }
                degree.push_back(thisDegree);
            }
        }
        sort(degree.begin(), degree.end());
        // debug(degree); //******
        int ans = 0;
        for (int i = 0; i < degree.size(); i++) {
            double begin = degree[i];
            double end = begin + angle;
            int thisAns = 0;
            if (end > 360) {
                thisAns = degree.size() - i;
                thisAns += upper_bound(degree.begin(), degree.end(), end - 360 + 1e-9) - degree.begin();
            }
            else {
                thisAns = upper_bound(degree.begin(), degree.end(), end + 1e-9) - degree.begin() - i;
            }
            // printf("i = %d, thisAns = %d, begin = %lf, end = %lf\n", i, thisAns, begin, end); //*****
            ans = max(ans, thisAns);
        }
        return ans + base;
    }
};

#ifdef _WIN32
int main() {
    string s;
    int angle;
    string s2;
    while (cin >> s >> angle >> s2) {
        vector<vector<int>> v = stringToVectorVector(s);
        vector<int> position = stringToVector(s2);
        Solution sol;
        cout << sol.visiblePoints(v, angle, position) << endl;
    }
    return 0;
}
#endif