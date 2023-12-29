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

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int a = prices[0], b = prices[1];
        if (a > b)
            swap(a, b);
        for (int i = 2; i < prices.size(); ++i)
        {
            if (prices[i] >= b)
                continue;
            if (prices[i] >= a)
                b = prices[i];
            else
            {
                b = a;
                a = prices[i];
            }
        }
        return (money >= a + b) ? (money - a - b) : money;
    }
};

int main()
{
    io;
    return 0;
}
