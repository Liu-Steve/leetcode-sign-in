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
    void qs(vector<int> &nums, int l, int r)
    {
        if (r - l <= 1)
            return;
        int cmp_idx = rand() % (r - l) + l;
        int pat = part(nums, l, r, cmp_idx);
        qs(nums, l, pat);
        qs(nums, pat + 1, r);
    }

    int part(vector<int> &nums, int l, int r, int p)
    {
        int cmp = nums[p];
        swap(nums[r - 1], nums[p]);
        int p1 = l;
        for (int i = l; i < r - 1; ++i)
        {
            bool eq = rand() % 2;
            if (nums[i] < cmp || (eq && nums[i] == cmp))
            {
                swap(nums[i], nums[p1]);
                p1++;
            }
        }
        swap(nums[p1], nums[r - 1]);
        return p1;
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        qs(nums, 0, nums.size());
        return nums;
    }
};

int main()
{
    io;
    Solution s;
    vector<int> v1 = {5, 2, 1, 4, 1, 3, 7};
    vector<int> v2 = s.sortArray(v1);
    for (int n : v2)
        cout << n << ' ';
    cout << endl;
    return 0;
}