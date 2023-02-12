#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution {
public:
    string alphabetBoardPath(string_view target) {
        ostringstream s;
        int x1 = 0;
        int y1 = 0;
        for (char ch : target)
        {
            int x2 = (ch - 'a') / 5;
            int y2 = (ch - 'a') % 5;
            while (x1 > x2)
            {
                s << 'U';
                x1--;
            }
            while (y1 < y2)
            {
                s << 'R';
                y1++;
            }
            while (y1 > y2)
            {
                s << 'L';
                y1--;
            }
            while (x1 < x2)
            {
                s << 'D';
                x1++;
            }
            s << '!';
        }
        return s.str();
    }
};

int main()
{
    io;
    Solution s;
    cout << s.alphabetBoardPath("leet") << endl;
    cout << s.alphabetBoardPath("code") << endl;
    cout << s.alphabetBoardPath("zdz") << endl;
    return 0;
}