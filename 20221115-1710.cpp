#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

inline bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[1] > b[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int unitSum = 0;
        for (vector<int> &v : boxTypes) {
            if (v[0] < truckSize) {
                truckSize -= v[0];
                unitSum += v[0] * v[1];
            }
            else {
                unitSum += truckSize * v[1];
                break;
            }
        }
        return unitSum;
    }
};

int main() {
    io;
    Solution s;
    vector<vector<int>> v = {{1,3},{2,2},{3,1}};
    cout << s.maximumUnits(v, 4) << endl;
    return 0;
}