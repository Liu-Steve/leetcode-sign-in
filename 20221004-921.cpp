#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int i = 0, lowest = 0;
        for (char ch : s) {
            if (ch == '(')
                i++;
            else
                i--;
            if (i < lowest)
                lowest = i;
        }
        return i - 2 * lowest;
    }
};

int main() {
    io;
    Solution s;
    string str = "()))((";
    cout << s.minAddToMakeValid(str) << endl;
    return 0;
}