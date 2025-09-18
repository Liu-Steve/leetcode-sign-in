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

class TaskManager
{
private:
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> task2user;
    unordered_map<int, int> task2prior;

public:
    TaskManager(vector<vector<int>> &tasks)
    {
        for (auto &t : tasks)
            add(t[0], t[1], t[2]);
    }

    void add(int userId, int taskId, int priority)
    {
        pq.emplace(priority, taskId);
        task2user[taskId] = userId;
        task2prior[taskId] = priority;
    }

    void edit(int taskId, int newPriority)
    {
        task2prior[taskId] = newPriority;
        pq.emplace(newPriority, taskId);
    }

    void rmv(int taskId)
    {
        task2user.erase(taskId);
        task2prior.erase(taskId);
    }

    int execTop()
    {
        while (!pq.empty())
        {
            int priority = pq.top().first;
            int taskId = pq.top().second;
            pq.pop();
            if (!task2prior.count(taskId) || !task2user.count(taskId) || task2prior[taskId] != priority)
                continue;
            int userId = task2user[taskId];
            rmv(taskId);
            return userId;
        }
        return -1;
    }
};

int main()
{
    io;
    return 0;
}
