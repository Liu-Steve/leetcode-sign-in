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

class NumArray
{
private:
    vector<int> &nums;
    vector<int> tree;

    int lowBit(int x)
    {
        return x & -x;
    }

    void add(int pos, int val)
    {
        while (pos < tree.size())
        {
            tree[pos] += val;
            pos += lowBit(pos);
        }
    }

    int preFix(int pos)
    {
        int sum = 0;
        while (pos != 0)
        {
            sum += tree[pos];
            pos -= lowBit(pos);
        }
        return sum;
    }

public:
    NumArray(vector<int> &nums) : nums(nums), tree(nums.size() + 1)
    {
        for (int i = 0; i < nums.size(); ++i)
            add(i + 1, nums[i]);
    }

    void update(int index, int val)
    {
        add(index + 1, val - nums[index]);
        nums[index] = val;
    }

    int sumRange(int left, int right)
    {
        return preFix(right + 1) - preFix(left);
    }
};

int main()
{
    io;
    return 0;
}
