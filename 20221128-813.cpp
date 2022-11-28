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

// class Solution {
// public:
//     double largestSumOfAverages(vector<int>& nums, int k) {
//         double sum = 0;
//         int ksum = 0;
//         priority_queue<int, vector<int>, greater<int>> q;
//         int n = nums.size();
//         k--;
//         for (int i = 0; i < n; ++i)
//         {
//             int num = nums[i];
//             sum += num;
//             if (q.size() < k)
//             {
//                 q.push(num);
//                 ksum += num;
//             }
//             else if (q.top() < num) {
//                 ksum -= q.top();
//                 q.pop();
//                 q.push(num);
//                 ksum += num;
//             }
//         }
//         sum = (sum - ksum) / (n - k) + ksum;
//         return sum;
//     }
// };

class Solution
{
public:
    double largestSumOfAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        double *last = new double[n + 1];
        double *now = new double[n + 1];
        last[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (i < n)
                nums[i] += nums[i - 1];
            last[i] = (double)nums[i - 1] / i;
        }
        while (--k)
        {
            now[0] = 0;
            for (int i = 1; i <= n; ++i)
            {
                now[i] = 0;
                for (int j = 1; j < i; ++j)
                {
                    now[i] = max(
                        now[i], last[j] + (double)(nums[i - 1] - nums[j - 1]) / (i - j));
                }
            }
            swap(now, last);
        }
        return last[n];
    }
};

// class Solution {
// public:
//     double largestSumOfAverages(const vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<double> prefix(n + 1);
//         for (int i = 0; i < n; i++) {
//             prefix[i + 1] = prefix[i] + nums[i];
//         }
//         vector<vector<double>> dp(n + 1, vector<double>(k + 1));
//         for (int i = 1; i <= n; i++) {
//             dp[i][1] = prefix[i] / i;
//         }
//         for (int j = 2; j <= k; j++) {
//             for (int i = j; i <= n; i++) {
//                 for (int x = j - 1; x < i; x++) {
//                     dp[i][j] = max(dp[i][j], dp[x][j - 1] + (prefix[i] - prefix[x]) / (i - x));
//                 }
//             }
//         }
//         return dp[n][k];
//     }
// };

int main()
{
    io;
    Solution s;
    vi v1 = {9, 1, 2, 3, 9};
    cout << s.largestSumOfAverages(v1, 3) << endl;
    vi v2 = {1, 2, 3, 4, 5, 6, 7};
    cout << s.largestSumOfAverages(v2, 4) << endl;
    vi v3 = {4, 1, 7, 5, 6, 2, 3};
    cout << s.largestSumOfAverages(v3, 4) << endl;
    vi v4 = {1};
    cout << s.largestSumOfAverages(v4, 1) << endl;
    return 0;
}