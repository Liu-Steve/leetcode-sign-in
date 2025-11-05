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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

constexpr long long MOD = 1000000007LL;

class Solution
{
public:
    vector<long long> findXSum(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        unordered_map<int, int> cnt;
        long long sum = 0;
        vector<long long> ans;
        set<pair<long long, long long>> small, large;
        for (int i = 0; i < k; ++i)
            cnt[nums[i]]++;
        for (auto [key, val] : cnt)
            large.emplace(val, key);
        while (large.size() > x)
        {
            small.insert(*large.begin());
            large.erase(large.begin());
        }
        for (auto [key, val] : large)
            sum += key * val;
        ans.push_back(sum);
        for (int i = k; i < n; ++i)
        {
            pair<long long, long long> target1 = {cnt[nums[i]], nums[i]};
            pair<long long, long long> target2 = {cnt[nums[i - k]], nums[i - k]};
            cnt[nums[i]]++;
            cnt[nums[i - k]]--;
            if (!large.empty() && target1 >= *large.begin())
            {
                large.erase(target1);
                sum -= target1.first * target1.second;
            }
            else
                small.erase(target1);
            if (!large.empty() && target2 >= *large.begin())
            {
                large.erase(target2);
                sum -= target2.first * target2.second;
            }
            else
                small.erase(target2);

            target1 = {cnt[nums[i]], nums[i]};
            target2 = {cnt[nums[i - k]], nums[i - k]};
            if (target1.first)
            {
                if (!large.empty() && target1 >= *large.begin())
                {
                    large.insert(target1);
                    sum += target1.first * target1.second;
                }
                else
                    small.insert(target1);
            }
            if (target2.first)
            {
                if (!large.empty() && target2 >= *large.begin())
                {
                    large.insert(target2);
                    sum += target2.first * target2.second;
                }
                else
                    small.insert(target2);
            }

            while (!small.empty() && large.size() < x)
            {
                auto target = *small.rbegin();
                sum += target.first * target.second;
                large.insert(target);
                small.erase(target);
            }
            while (large.size() > x)
            {
                auto target = *large.begin();
                sum -= target.first * target.second;
                small.insert(target);
                large.erase(target);
            }
            ans.push_back(sum);
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
