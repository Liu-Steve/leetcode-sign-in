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
    typedef struct st
    {
        int idx;
        int data;
    } Elem;
    static bool cmp(Elem e1, Elem e2)
    {
        return e1.data < e2.data;
    }
    vector<int> twoSum(vector<int> &nums, int target)
    {
        Elem arr[nums.size()];
        for (int i = 0; i < nums.size(); ++i)
        {
            arr[i].data = nums[i];
            arr[i].idx = i;
        }
        sort(arr, arr + nums.size(), cmp);
        vector<int> *v = new vector<int>();
        int pl = 0;
        int pr = nums.size() - 1;
        while (pl != pr)
        {
            if (arr[pl].data + arr[pr].data < target)
                ++pl;
            else if (arr[pl].data + arr[pr].data > target)
                --pr;
            else
                break;
        }
        v->push_back(arr[pl].idx);
        v->push_back(arr[pr].idx);
        return *v;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
