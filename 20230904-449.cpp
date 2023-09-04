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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
private:
    void dfs(TreeNode *root, vector<int> &val)
    {
        if (root == nullptr)
            return;
        dfs(root->left, val);
        dfs(root->right, val);
        val.emplace_back(root->val);
    }

    TreeNode *build(vector<int> &val, int l, int r)
    {
        if (l == r)
            return nullptr;
        int p1 = l;
        int p2 = r - 1;
        int cmp = val[r - 1];
        TreeNode *root = new TreeNode(cmp);
        if (l + 1 == r)
            return root;
        while (p1 + 1 < p2)
        {
            int pm = (p1 + p2) / 2;
            int mid = val[pm];
            if (mid < cmp)
                p1 = pm;
            else
                p2 = pm;
        }
        if (val[p1] > cmp)
            p1--;
        root->left = build(val, l, p1 + 1);
        root->right = build(val, p1 + 1, r - 1);
        return root;
    }

public:
    string serialize(TreeNode *root)
    {
        vector<int> val;
        dfs(root, val);
        stringstream ss;
        for (int i = 0; i < val.size(); ++i)
        {
            if (i != 0)
                ss << ' ';
            ss << val[i];
        }
        return ss.str();
    }

    TreeNode *deserialize(string &data)
    {
        vector<int> val;
        stringstream ss;
        ss << data;
        int num;
        while (ss >> num)
            val.emplace_back(num);
        return build(val, 0, val.size());
    }
};

int main()
{
    io;
    return 0;
}
