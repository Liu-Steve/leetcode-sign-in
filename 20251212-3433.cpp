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
    vector<int> countMentions(int numberOfUsers, vector<vector<string>> &events)
    {
        vector<tuple<int, int, vector<int>>> timeline;
        for (auto &e : events)
        {
            int timestamp = atoi(e[1].c_str());
            if (e[0] == "MESSAGE")
            {
                vector<int> ids;
                int type = 2;
                if (e[2] == "ALL")
                    type = 3;
                else if (e[2] == "HERE")
                    type = 4;
                else
                {
                    int id = 0;
                    for (char ch : e[2])
                    {
                        if (ch == ' ')
                        {
                            ids.push_back(id);
                            id = 0;
                        }
                        if (ch == 'i' || ch == 'd' || ch == ' ')
                            continue;
                        id = id * 10 + ch - '0';
                    }
                    ids.push_back(id);
                }
                timeline.emplace_back(timestamp, type, ids);
                continue;
            }
            int id = atoi(e[2].c_str());
            timeline.emplace_back(timestamp, 1, vector<int>{id});
            timeline.emplace_back(timestamp + 60, 0, vector<int>{id});
        }
        sort(timeline.begin(), timeline.end());
        vector<int> ans(numberOfUsers);
        vector<int> online(numberOfUsers, 1);
        for (auto &[t, type, ids] : timeline)
        {
            switch (type)
            {
            case 0:
                online[ids[0]] = 1;
                break;
            case 1:
                online[ids[0]] = 0;
                break;
            case 2:
                for (int id : ids)
                    ans[id]++;
                break;
            case 3:
                for (int &cnt : ans)
                    cnt++;
                break;
            case 4:
                for (int i = 0; i < numberOfUsers; ++i)
                    ans[i] += online[i];
                break;
            default:
                break;
            }
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
