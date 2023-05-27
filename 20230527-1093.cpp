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
    vector<double> sampleStats(vector<int> &count)
    {
        vector<double> ans = {-1, -1, 0, 0, 0};
        int n = count.size();
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (count[i] != 0)
            {
                if (ans[0] == -1)
                    ans[0] = i;                    // min
                ans[1] = i;                        // max
                ans[2] += (double)i * count[i];    // mean
                sum += count[i];                   // sum
                if (count[(int)ans[4]] < count[i]) // mode
                    ans[4] = i;
            }
        }
        ans[2] /= sum; // mean

        // median
        int hsum = 0;
        bool avg = false;
        for (int i = 0; i < n; ++i)
        {
            if (!count[i])
                continue;
            hsum += count[i];
            if (hsum > (sum >> 1))
            {
                ans[3] += i;
                if (avg)
                    ans[3] /= 2;
                break;
            }
            if (!(sum & 1) && hsum == (sum >> 1)) // even; avg
            {
                avg = true;
                ans[3] = i;
            }
        }
        
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
