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
    int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity)
    {
        int n = buses.size();
        int m = passengers.size();
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        vector<int> up;
        int p = 0;
        bool full = false;
        for (int bus : buses)
        {
            int cnt = 0;
            while (cnt < capacity && p < m && passengers[p] <= bus)
            {
                up.push_back(passengers[p]);
                cnt++;
                p++;
            }
            full = (capacity == cnt);
        }
        if (up.empty() || (!full && buses.back() != up.back()))
            return buses.back();
        int ans = up.back();
        while (!up.empty() && up.back() == ans)
        {
            ans--;
            up.pop_back();
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
