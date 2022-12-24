#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vv;

class Solution {
public:
    string largestMerge(string_view word1, string_view word2) {
        ostringstream s;
        while (word1.size() || word2.size())
        {
            if (!word2.size() || word1 > word2)
            {
                s.put(word1[0]);
                word1.remove_prefix(1);
            }
            else
            {
                s.put(word2[0]);
                word2.remove_prefix(1);
            }
        }
        return s.str();
    }
};

int main() {
    io;
    Solution s;
    cout << s.largestMerge("cabaa", "bcaaa") << endl;
    cout << s.largestMerge("abcabc", "abdcaba") << endl;
    return 0;
}