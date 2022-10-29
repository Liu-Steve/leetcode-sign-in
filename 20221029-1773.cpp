#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int idx;
        if(ruleKey == "type")
            idx = 0;
        else if(ruleKey == "color")
            idx = 1;
        else
            idx = 2;
        int cnt = 0;
        int len = items.size();
        for (int i = 0; i < len; ++i)
        {
            if (items[i][idx] == ruleValue)
                cnt++;
        }
        return cnt;
    }
};

int main() {
    io;
    Solution s;
    return 0;
}