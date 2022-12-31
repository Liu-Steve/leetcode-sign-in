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

class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int n = seats.size();
        int ret = 0;
        for (int i = 0; i < n; ++i)
            ret += abs(seats[i] - students[i]);
        return ret;
    }
};

int main()
{
    io;
    Solution s;
    vi v11 = {3, 1, 5};
    vi v12 = {2, 7, 4};
    cout << s.minMovesToSeat(v11, v12) << endl;
    return 0;
}