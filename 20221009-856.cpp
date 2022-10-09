#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int st[50];
        int len = s.size();
        int p = 0;
        st[0] = 0;
        for (int i = 0; i < len; ++i)
        {
            if (s[i] == '(')
            {
                if (s[i + 1] == ')')
                {
                    st[p] += 1;
                    i++;
                }
                else
                {
                    p++;
                    st[p] = 0;
                }
            }
            else
            {
                p--;
                st[p] += st[p + 1] * 2;
            }
        }
        return st[0];
    }
};

int main() {
    io;
    Solution s;
    string str = "((()())((())))()";
    cout << s.scoreOfParentheses(str) << endl;
    return 0;
}