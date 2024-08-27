#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef vector<vl> vvl;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<int, int> pr;
typedef pair<ll, ll> prl;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<ll, int> memory;

class Solution
{
public:
    int medianOfUniquenessArray(vector<int> &nums)
    {
        long long n = nums.size();
        long long lit = ((n + 1) * n / 2 - 1) / 2;
        auto sp = [&](int x) -> bool
        {
            unordered_map<int, int> mp;
            long long cnt = 0;
            int l = 0;
            int r = 1;
            for (; r <= n; ++r)
            {
                mp[nums[r - 1]]++;
                while (mp.size() >= x)
                {
                    mp[nums[l]]--;
                    if (mp[nums[l]] == 0)
                        mp.erase(nums[l]);
                    l++;
                }
                cnt += r - l;
                if (cnt > lit)
                    return false;
            }
            return cnt <= lit;
        };
        int l = 1;
        int r = 100009;
        while (l < r - 1)
        {
            int mid = (l + r) / 2;
            if (sp(mid))
                l = mid;
            else
                r = mid;
        }
        return l;
    }
};

int main()
{
    io;
    return 0;
}
