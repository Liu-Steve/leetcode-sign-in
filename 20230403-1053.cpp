#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    vector<int> prevPermOpt1(vector<int> &arr)
    {
        int n = arr.size();
        int p = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] > arr[i + 1])
            {
                p = i;
                break;
            }
        }
        if (p == -1)
            return arr;
        int l = p + 1;
        int r = n;
        while (r - l > 1)
        {
            int m = (l + r) / 2;
            if (arr[m] < arr[p])
                l = m;
            else
                r = m;
        }
        while (l - 1 > p)
        {
            if (arr[l] != arr[l - 1])
                break;
            l--;
        }
        swap(arr[p], arr[l]);
        return arr;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {3, 2, 1};
    for (int i : s.prevPermOpt1(v1))
        cout << i << ' ';
    cout << endl;
    vi v2 = {1, 1, 5};
    for (int i : s.prevPermOpt1(v2))
        cout << i << ' ';
    cout << endl;
    vi v3 = {1, 9, 4, 6, 7};
    for (int i : s.prevPermOpt1(v3))
        cout << i << ' ';
    cout << endl;
    vi v4 = {3, 1, 1, 3};
    for (int i : s.prevPermOpt1(v4))
        cout << i << ' ';
    cout << endl;
    return 0;
}