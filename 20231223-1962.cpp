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
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum = 0;
        priority_queue<int> pq;
        for (int p : piles)
        {
            sum += p;
            pq.push(p);
        }
        int sub = 0;
        while (k--)
        {
            int tp = pq.top();
            pq.pop();
            sub += tp / 2;
            pq.push(tp - tp / 2);
        }
        return sum - sub;
    }
};

int main()
{
    io;
    return 0;
}
