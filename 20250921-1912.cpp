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

class MovieRentingSystem
{
private:
    set<tuple<int, int, int>> rented;                 // price, shop, movie
    unordered_map<int, set<pair<int, int>>> unrented; // movie, price, shop
    vector<unordered_map<int, int>> prices;           // shop, movie, price

    inline int getPrice(int shop, int movie)
    {
        return prices[shop][movie];
    }

public:
    MovieRentingSystem(int n, vector<vector<int>> &entries) : prices(n)
    {
        for (auto &e : entries)
        {
            unrented[e[1]].emplace(e[2], e[0]);
            prices[e[0]][e[1]] = e[2];
        }
    }

    vector<int> search(int movie)
    {
        auto &entries = unrented[movie];
        vector<int> ans;
        for (auto it = entries.begin(); it != entries.end(); ++it)
        {
            ans.push_back((*it).second);
            if (ans.size() == 5)
                break;
        }
        return ans;
    }

    void rent(int shop, int movie)
    {
        int price = getPrice(shop, movie);
        unrented[movie].erase(pair<int, int>(price, shop));
        rented.emplace(price, shop, movie);
    }

    void drop(int shop, int movie)
    {
        int price = getPrice(shop, movie);
        rented.erase(make_tuple(price, shop, movie));
        unrented[movie].emplace(price, shop);
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> ans;
        for (auto it = rented.begin(); it != rented.end(); ++it)
        {
            ans.push_back({get<1>(*it), get<2>(*it)});
            if (ans.size() == 5)
                break;
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
