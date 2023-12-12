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

class Solution
{
public:
    vi secondGreaterElement(vi &nums)
    {
        int n = nums.size();
        vi ans(n, -1);
        vi st1(n);
        vi st2(n);
        int p1 = 0;
        int p2 = 0;
        for (int i = 0; i < n; ++i)
        {
            while (p2 > 0 && nums[st2[p2 - 1]] < nums[i])
            {
                ans[st2[p2 - 1]] = nums[i];
                p2--;
            }
            int tmp = p1;
            while (p1 > 0 && nums[st1[p1 - 1]] < nums[i])
                p1--;
            for (int j = 0; p1 + j < tmp; ++j)
            {
                st2[p2] = st1[p1 + j];
                p2++;
            }
            st1[p1] = i;
            p1++;
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;

    vi v1 = {2, 4, 0, 9, 6};
    vi a1 = s.secondGreaterElement(v1);
    for (int num : a1)
        cout << num << ' ';
    cout << endl;
    vi v2 = {3, 3};
    vi a2 = s.secondGreaterElement(v2);
    for (int num : a2)
        cout << num << ' ';
    cout << endl;

    return 0;
}
