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
typedef pair<int, int> pr;
typedef vector<pair<int, int>> vp;

const ll MOD = 1000000007;

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0;
        int l = 0;
        for (vector<int> &b : brackets)
        {
            tax += (min(b[0], income) - l) * b[1];
            l = b[0];
            if (income <= b[0])
                break;
        }
        return tax / 100.0;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}