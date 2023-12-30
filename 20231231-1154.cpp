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
private:
    bool add(int year)
    {
        if (year % 400 == 0)
            return true;
        if (year % 100 == 0)
            return false;
        if (year % 4 == 0)
            return true;
        return false;
    }

public:
    int dayOfYear(string date)
    {
        vector<int> mday = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year = 1000 * (date[0] - '0') +
                   100 * (date[1] - '0') +
                   10 * (date[2] - '0') +
                   (date[3] - '0');
        int month = 10 * (date[5] - '0') +
                    (date[6] - '0');
        int day = 10 * (date[8] - '0') +
                    (date[9] - '0');
        int sum = add(year) && month > 2;
        for (int i = 1; i < month; ++i)
            sum += mday[i];
        sum += day;
        return sum;
    }
};

int main()
{
    io;
    return 0;
}
