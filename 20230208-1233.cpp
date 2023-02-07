#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

typedef struct st1
{
    unordered_map<string_view, st1 *> sub;
} Node;

class Solution
{
private:
    pair<Node *, bool> extend(Node *now, string_view name)
    {
        Node *nxt = nullptr;
        bool del = false;
        const auto &it = now->sub.find(name);
        // new node
        if (it == now->sub.end())
        {
            nxt = new Node();
            now->sub.insert({name, nxt});
        }
        // existed node
        else
        {
            nxt = (*it).second;
            // is sub dir
            if (nxt->sub.size() == 0)
                del = true;
        }
        return {nxt, del};
    }

    void dfs(Node *root, vs &ans, string fa)
    {
        if (root->sub.size() == 0)
            ans.emplace_back(fa);
        else
            for (auto &[name, nxt] : root->sub)
                dfs(nxt, ans, (fa + "/").append(name));
    }

public:
    vs removeSubfolders(vs &folder)
    {
        Node *root = new Node();
        for (string_view f : folder)
        {
            Node *now = root;
            int len = f.size();
            int start = 1;
            bool del = false;
            // build trie
            for (int i = 1; i < len; ++i)
            {
                if (f[i] != '/')
                    continue;
                auto name = f.substr(start, i - start);
                start = i + 1;
                auto [nxt, stop] = extend(now, name);
                now = nxt;
                if (stop)
                {
                    del = true;
                    break;
                }
            }
            if (del)
                continue;
            auto name = f.substr(start);
            auto [nxt, _] = extend(now, name);
            // clean sub dir
            nxt->sub.clear();
        }
        vs ans;
        ans.reserve(folder.size());
        dfs(root, ans, "");
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}