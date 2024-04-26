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
typedef unordered_map<int, int> memory;

class SnapshotArray
{
private:
    vector<vector<pair<int, int>>> data;
    unordered_map<int, int> temp;
    int id;

public:
    SnapshotArray(int length) : data(length, vector<pair<int, int>>{
                                                 pair<int, int>{-1, 0}}),
                                temp(), id(-1)
    {
    }

    void set(int index, int val)
    {
        temp[index] = val;
    }

    int snap()
    {
        id++;
        for (auto [key, val] : temp)
            data[key].emplace_back(id, val);
        temp.clear();
        return id;
    }

    int get(int index, int snap_id)
    {
        auto it = lower_bound(
            data[index].begin(), data[index].end(),
            pair<int, int>{snap_id, INT32_MAX});
        it--;
        return it->second;
    }
};

int main()
{
    io;
    return 0;
}
