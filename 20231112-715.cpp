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

typedef struct node
{
    int left;
    int right;
    mutable bool val;
    node(int l, int r, bool v) : left(l), right(r), val(v) {}
    bool operator<(const node &n1) const { return left < n1.left; }
} Node;

class RangeModule
{
private:
    set<Node> odt;

    auto split(int pos)
    {
        auto it = odt.lower_bound(node(pos, 0, 0));
        if (it != odt.end() && it->left == pos)
            return it;
        it--;
        int l = it->left;
        int r = it->right;
        bool v = it->val;
        odt.erase(it);
        odt.emplace(l, pos, v);
        return odt.emplace(pos, r, v).first;
    }

public:
    RangeModule()
    {
        odt.emplace(0, 1000000001, false);
    }

    void addRange(int left, int right)
    {
        auto end = split(right);
        auto begin = split(left);
        odt.erase(begin, end);
        odt.emplace(left, right, true);
    }

    bool queryRange(int left, int right)
    {
        auto end = split(right);
        for (auto it = split(left); it != end; it++)
            if (it->val == false)
                return false;
        return true;
    }

    void removeRange(int left, int right)
    {
        auto end = split(right);
        auto begin = split(left);
        odt.erase(begin, end);
        odt.emplace(left, right, false);
    }
};

int main()
{
    io;
    return 0;
}
