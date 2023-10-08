#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

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

class StockPrice
{
private:
    priority_queue<pr, vp, less<pr>> q_max;
    priority_queue<pr, vp, greater<pr>> q_min;
    map<int, int> p;

public:
    StockPrice()
    {
    }

    void update(int timestamp, int price)
    {
        p[timestamp] = price;
        q_max.emplace(price, timestamp);
        q_min.emplace(price, timestamp);
    }

    int current()
    {
        return (*(p.rbegin())).second;
    }

    int maximum()
    {
        while (true)
        {
            auto [pri, t] = q_max.top();
            if (p[t] != pri)
            {
                q_max.pop();
                continue;
            }
            return pri;
        }
        return -1; // error
    }

    int minimum()
    {
        while (true)
        {
            auto [pri, t] = q_min.top();
            if (p[t] != pri)
            {
                q_min.pop();
                continue;
            }
            return pri;
        }
        return -1; // error
    }
};

int main()
{
    io;
    return 0;
}