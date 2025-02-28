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

bool cmp(pair<int, string> p1, pair<int, string> p2)
{
    if (p1.first != p2.first)
        return p1.first < p2.first;
    return p1.second > p2.second;
}

typedef priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(&cmp)> Prior;

class FoodRatings
{
private:
    unordered_map<string, unordered_map<string, int>> rate;
    unordered_map<string, Prior> heap;
    unordered_map<string, string> food2cuisine;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        int n = foods.size();
        for (int i = 0; i < n; ++i)
        {
            if (!rate.count(cuisines[i]))
            {
                rate[cuisines[i]] = {};
                heap[cuisines[i]] = Prior(cmp);
            }
            auto &mp = rate[cuisines[i]];
            auto &pq = heap[cuisines[i]];
            mp[foods[i]] = ratings[i];
            pq.emplace(ratings[i], foods[i]);
            food2cuisine[foods[i]] = cuisines[i];
        }
    }

    void changeRating(string food, int newRating)
    {
        string &cuisine = food2cuisine[food];
        auto &mp = rate[cuisine];
        auto &pq = heap[cuisine];
        mp[food] = newRating;
        pq.emplace(newRating, food);
    }

    string highestRated(string cuisine)
    {
        auto &mp = rate[cuisine];
        auto &pq = heap[cuisine];
        while (pq.top().first != mp[pq.top().second])
            pq.pop();
        return pq.top().second;
    }
};

int main()
{
    io;
    return 0;
}
