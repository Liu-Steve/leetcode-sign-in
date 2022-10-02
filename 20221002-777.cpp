#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        int len, p1, p2;
        len = start.length();
        p1 = 0; 
        p2 = 0;
        while (p1 < len || p2 < len)
        {
            char a = 'X', b = 'X';
            while (a == 'X')
            {
                if (p1 >= len)
                {
                    a = 'E';
                    break;
                }
                a = start[p1];
                p1++;
            }
            while (b == 'X')
            {
                if (p2 >= len)
                {
                    b = 'E';
                    break;
                }
                b = end[p2];
                p2++;
            }
            if (a != b)
                return false;
            if (a == 'L' && p1 < p2)
                return false;
            if (a == 'R' && p1 > p2)
                return false;
        }
        return true;
    }
};

int main() {
    io;
    Solution s;
    string a = "X";
    string b = "L";
    cout << s.canTransform(a, b) << endl;
    return 0;
}