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

// 欧拉筛
vector<int> euler(int n)
{
    vector<int> pri;
    vector<uint8_t> not_prime(n + 1); // bool
    not_prime[0] = true;
    not_prime[1] = true;
    for (int i = 2; i <= n; ++i)
    {
        if (!not_prime[i])
            pri.push_back(i);
        for (int pri_j : pri)
        {
            if (pri_j * i > n)
                break;
            not_prime[pri_j * i] = true;
            if (i % pri_j == 0)
                break;
        }
    }
    return pri;
}

int main()
{
    io;
    return 0;
}