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

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> q;
        double sum = 0;
        for (int num : nums)
        {
            sum += num;
            q.emplace(num);
        }
        sum /= 2;
        int ans = 0;
        while (sum > 0)
        {
            ans++;
            double num = q.top();
            q.pop();
            sum -= num / 2;
            q.emplace(num / 2);
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
