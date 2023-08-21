#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    bool canChange(string &start, string &target)
    {
        int n = start.size();
        int p1 = 0;
        int p2 = 0;
        while (true)
        {
            while (p1 < n && start[p1] == '_')
                p1++;
            while (p2 < n && target[p2] == '_')
                p2++;
            if (p1 == n && p2 == n)
                return true;
            if (p1 == n || p2 == n || start[p1] != target[p2])
                return false;
            if (start[p1] == 'L' && p1 < p2)
                return false;
            if (start[p1] == 'R' && p1 > p2)
                return false;
            p1++;
            p2++;
        }
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
