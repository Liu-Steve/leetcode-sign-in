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
    bool checkIfPangram(string sentence) {
        int cnt = 0;
        for (char ch : sentence)
            cnt |= 1 << (ch - 'a');
        return 0x3ffffff == cnt;
    }
};

int main() {
    io;
    Solution s;
    cout << s.checkIfPangram("thequickbrownfoxjumpsoverthelazydog") << endl;
    cout << s.checkIfPangram("leetcode") << endl;
    return 0;
}