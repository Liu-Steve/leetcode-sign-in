#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string s)
    {
        vector<string> ret;
        int letter = 0;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            char ch = s[i];
            if (ch >= '0' && ch <= '9')
                continue;
            letter++;
            if (ch >= 'a' && ch <= 'z')
                s[i] -= 'a';
            else
                s[i] -= 'A';
        }
        for (int i = (1 << letter) - 1; i >= 0; --i) {
            string add(s);
            int bias = 0;
            for (int j = 0; j < len; ++j) {
                char ch = s[j];
                if (ch >= '0' && ch <= '9')
                    continue;
                if (i & (1 << bias))
                    add[j] += 'A';
                else
                    add[j] += 'a';
                bias++;
            }
            ret.emplace_back(add);
        }
        return ret;
    }
};

int main()
{
    io;
    Solution s;
    string str = "3z4Q";
    for (string st : s.letterCasePermutation(str))
    {
        cout << st << endl;
    }
    return 0;
}