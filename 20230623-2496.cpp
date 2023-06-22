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

class Solution {
private:
    int getVal(const string &strs)
    {
        int ret = 0;
        for (char ch : strs)
            if (ch >= 'a' && ch <= 'z')
                return strs.size();
            else
                ret = ret * 10 + ch - '0';
        return ret;
    }

public:
    int maximumValue(vector<string>& strs) {
        int ret = 0;
        for (string &str : strs)
            ret = max(ret, getVal(str));
        return ret;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
