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
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<ll, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution {
public:
    int minNumberOfHours(int eni, int expi, vector<int>& en, vector<int>& exp) {
        int end = 0;
        int expd = 0;
        for (int e : en)
        {
            if (eni <= e)
                end = max(end, e - eni + 1);
            eni -= e;
        }
        for (int e : exp)
        {
            if (expi <= e)
                expd = max(expd, e - expi + 1);
            expi += e;
        }
        return end + expd;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}