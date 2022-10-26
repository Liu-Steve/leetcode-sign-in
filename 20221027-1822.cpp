#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution {
public:
    int arraySign(const vector<int>& nums) {
        int cnt = 0;
        for(int num : nums)
        {
            if (!num)
                return 0;
            else if (num < 0)
                cnt++;
        }
        return (cnt % 2) ? -1 : 1;
    }
};

int main() {
    io;
    Solution s;
    vector<int> v = {-1,1,-1,1,-1};
    cout << s.arraySign(v) << endl;
    return 0;
}