#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution
{
public:
    string reformatNumber(string number)
    {
        vector<char> num;
        for (char ch : number)
        {
            if (ch != '-' && ch != ' ')
            {
                num.emplace_back(ch);
            }
        }
        int len = num.size();
        char new_str[len * 2];
        int p = 0, i;
        for (i = 0; i < len - 4;)
        {
            for (int j = 0; j < 3; ++j)
            {
                new_str[p++] = num[i++];
            }
            new_str[p++] = '-';
        }
        if (len - i < 4)
        {
            while (i < len)
            {
                new_str[p++] = num[i++];
            }
        }
        else
        {
            new_str[p++] = num[i++];
            new_str[p++] = num[i++];
            new_str[p++] = '-';
            new_str[p++] = num[i++];
            new_str[p++] = num[i++];
        }
        new_str[p] = 0;
        string ret(new_str);
        return ret;
    }
};

int main()
{
    io;
    Solution s;
    string in = "--17-5 ";
    cout << s.reformatNumber(in) << endl;
    return 0;
}