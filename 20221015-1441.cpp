#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ret;
        int last = 0;
        for (int i : target) {
            for (int j = 0; j < i - last - 1; ++j)
            {
                ret.emplace_back("Push");
                ret.emplace_back("Pop");
            }
            ret.emplace_back("Push");
            last = i;
        }
        return ret;
    }
};

int main() {
    io;
    Solution s;
    vector<int> target = {1, 3};
    vector<int> v = s.buildArray(target, 3);
    return 0;
}