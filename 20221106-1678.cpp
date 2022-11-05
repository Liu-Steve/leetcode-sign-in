#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution {
public:
    string interpret(string command) {
        char strs[101];
        int slen = 0;
        int i = 0;
        int len = command.size();
        while (i < len)
        {
            switch (command[i])
            {
            case 'G':
                strs[slen] = 'G';
                slen++;
                i++;
                break;
            case ')':
                strs[slen] = 'o';
                slen++;
                i++;
                break;
            case 'a':
                strs[slen] = 'a';
                strs[slen + 1] = 'l';
                slen += 2;
                i += 3;
                break;
            default:
                i++;
                break;
            }
        }
        strs[slen] = 0;
        string ret(strs);
        return ret;
    }
};

int main() {
    io;
    Solution s;
    cout << s.interpret("G()(al)") << endl;
    cout << s.interpret("G()()()()(al)") << endl;
    cout << s.interpret("(al)G(al)()()G") << endl;
    return 0;
}