#include <iostream>
#include <vector>
#include <random>
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;

class Solution
{
private:
    int qs(vector<int> &nums, int l, int r, int k)
    {
        if (r - l == 1 && l == k)
            return nums[k];
        int pat = part(nums, l, r);
        if (pat <= k)
            return qs(nums, pat, r, k);
        else
            return qs(nums, l, pat, k);
    }

    int part(vector<int> &nums, int l, int r)
    {
        int idx = rand() % (r - l) + l;
        int cmp = nums[idx];
        swap(nums[idx], nums[r - 1]);
        int p1 = l;
        for (int i = l; i < r - 1; ++i)
        {
            bool eq = rand() % 2;
            if (nums[i] > cmp || (eq && nums[i] == cmp))
            {
                swap(nums[i], nums[p1]);
                p1++;
            }
        }
        swap(nums[p1], nums[r - 1]);
        return p1;
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return qs(nums, 0, nums.size(), k - 1);
    }
};

int main()
{
    io;
    Solution s;
    vector<int> v1 = {4, 2, 1, 7, 3, 0};
    cout << s.findKthLargest(v1, 2) << endl;
    return 0;
}