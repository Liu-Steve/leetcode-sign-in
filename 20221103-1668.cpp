#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution {
public:
    int maxRepeating(const string &sequence, const string &word) {
        int ans = 0;
        string t = word;
        int x = sequence.size() / word.size();
        for (int k = 1; k <= x; ++k) {
            if (sequence.find(t) != string::npos) {
                ans = k;
            }
            t += word;
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.maxRepeating("aaabaaaabaaabaaaabaaaabaaaabaaaaba", "aaaba") << endl;
    return 0;
}