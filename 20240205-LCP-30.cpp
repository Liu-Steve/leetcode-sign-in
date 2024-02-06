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
    int magicTower(vector<int> &nums)
    {
        priority_queue<int> pq;
        long long sum = 1;
        long long lst = 0;
        int ans = 0;
        for (int num : nums)
        {
            sum += num;
            if (num < 0)
                pq.push(-num);
            if (sum > 0)
                continue;
            if (pq.empty())
                return -1;
            sum += pq.top();
            lst += pq.top();
            pq.pop();
            ans++;
        }
        if (sum - lst <= 0)
            return -1;
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
