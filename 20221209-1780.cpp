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
    bool checkPowersOfThree(int n) {
        while (n)
        {
            if (n % 3 == 2)
                return false;
            n /= 3;
        }
        return true;
    }
};

int main() {
    io;
    Solution s;
    cout << s.checkPowersOfThree(12) << endl;
    cout << s.checkPowersOfThree(91) << endl;
    cout << s.checkPowersOfThree(21) << endl;
    return 0;
}