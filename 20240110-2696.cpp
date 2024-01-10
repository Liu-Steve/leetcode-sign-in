#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    int minLength(string s)
    {
        int ans = 0;
        stack<int> stk;
        for (char ch : s)
        {
            if (!stk.empty() && (stk.top() == 'A' && ch == 'B' || stk.top() == 'C' && ch == 'D'))
            {
                stk.pop();
                ans++;
                continue;
            }
            stk.push(ch);
        }
        return s.size() - ans * 2;
    }
};

int main()
{
    io;
    return 0;
}
