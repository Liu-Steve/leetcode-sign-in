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
    bool squareIsWhite(const string &c) {
        return (c[0] ^ c[1]) & 1;
    }
};

int main() {
    io;
    Solution s;
    cout << s.squareIsWhite("a1") << endl;
    cout << s.squareIsWhite("h3") << endl;
    cout << s.squareIsWhite("c7") << endl;
    return 0;
}