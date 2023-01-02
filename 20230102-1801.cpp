#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vv;
typedef pair<ll, ll> pr;

const ll MOD = 1000000007;

class Solution
{
private:
    priority_queue<pr, vector<pr>, less<pr>> buys;
    priority_queue<pr, vector<pr>, greater<pr>> sells;
    ll buy_num;
    ll sell_num;

    void buy(ll price, ll amount)
    {
        while (amount && !sells.empty())
        {
            pr t = sells.top();
            if (t.first > price)
                break;
            int d = min(amount, t.second);
            sell_num -= d;
            amount -= d;
            t.second -= d;
            sells.pop();
            if (t.second)
                sells.emplace(t);
        }
        if (!amount)
            return;
        buy_num += amount;
        buys.emplace(price, amount);
    }

    void sell(ll price, ll amount)
    {
        while (amount && !buys.empty())
        {
            pr t = buys.top();
            if (t.first < price)
                break;
            int d = min(amount, t.second);
            buy_num -= d;
            amount -= d;
            t.second -= d;
            buys.pop();
            if (t.second)
                buys.emplace(t);
        }
        if (!amount)
            return;
        sell_num += amount;
        sells.emplace(price, amount);
    }

public:
    int getNumberOfBacklogOrders(vector<vector<int>> &orders)
    {
        buy_num = sell_num = 0;
        for (vi &v : orders)
        {
            switch (v[2])
            {
            case 0: // buy
                buy(v[0], v[1]);
                break;

            case 1: // sell
                sell(v[0], v[1]);
                break;

            default:
                break;
            }
        }
        return (buy_num + sell_num) % MOD;
    }
};

int main()
{
    io;
    Solution s1, s2;
    vv v1 = {{10, 5, 0}, {15, 2, 1}, {25, 1, 1}, {30, 4, 0}};
    cout << s1.getNumberOfBacklogOrders(v1) << endl;
    vv v2 = {{7, 1000000000, 1}, {15, 3, 0}, {5, 999999995, 0}, {5, 1, 1}};
    cout << s2.getNumberOfBacklogOrders(v2) << endl;
    return 0;
}