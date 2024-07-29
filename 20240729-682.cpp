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

class Solution
{
private:
    int s2i(string &str)
    {
        stringstream ss;
        int ans;
        ss << str;
        ss >> ans;
        return ans;
    }

public:
    int calPoints(vector<string> &operations)
    {
        vector<int> score;
        for (auto &s : operations)
        {
            if (s[0] == '+')
                score.push_back(score[score.size() - 1] + score[score.size() - 2]);
            else if (s[0] == 'D')
                score.push_back(score[score.size() - 1] * 2);
            else if (s[0] == 'C')
                score.pop_back();
            else
                score.push_back(s2i(s));
        }
        return reduce(score.begin(), score.end());
    }
};

int main()
{
    io;
    return 0;
}
