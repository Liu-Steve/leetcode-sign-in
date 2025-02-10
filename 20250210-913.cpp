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
    const int MOUSE_TURN = 0, CAT_TURN = 1;
    const int DRAW = 0, MOUSE_WIN = 1, CAT_WIN = 2;
    vector<vector<int>> graph;
    vector<vector<vector<int>>> degrees;
    vector<vector<vector<int>>> results;

    int catMouseGame(vector<vector<int>> &graph)
    {
        int n = graph.size();
        this->graph = graph;
        this->degrees = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(2)));
        this->results = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(2)));
        queue<tuple<int, int, int>> qu;
        for (int i = 0; i < n; i++)
            for (int j = 1; j < n; j++)
            {
                degrees[i][j][MOUSE_TURN] = graph[i].size();
                degrees[i][j][CAT_TURN] = graph[j].size();
            }
        for (int node : graph[0])
            for (int i = 0; i < n; i++)
                degrees[i][node][CAT_TURN]--;
        for (int j = 1; j < n; j++)
        {
            results[0][j][MOUSE_TURN] = MOUSE_WIN;
            results[0][j][CAT_TURN] = MOUSE_WIN;
            qu.emplace(0, j, MOUSE_TURN);
            qu.emplace(0, j, CAT_TURN);
        }
        for (int i = 1; i < n; i++)
        {
            results[i][i][MOUSE_TURN] = CAT_WIN;
            results[i][i][CAT_TURN] = CAT_WIN;
            qu.emplace(i, i, MOUSE_TURN);
            qu.emplace(i, i, CAT_TURN);
        }
        while (!qu.empty())
        {
            auto [mouse, cat, turn] = qu.front();
            qu.pop();
            int result = results[mouse][cat][turn];
            vector<tuple<int, int, int>> prevStates = GetPrevStates(mouse, cat, turn);
            for (auto &[prevMouse, prevCat, prevTurn] : prevStates)
            {
                if (results[prevMouse][prevCat][prevTurn] == DRAW)
                {
                    bool canWin = (result == MOUSE_WIN && prevTurn == MOUSE_TURN) || (result == CAT_WIN && prevTurn == CAT_TURN);
                    if (canWin)
                    {
                        results[prevMouse][prevCat][prevTurn] = result;
                        qu.emplace(prevMouse, prevCat, prevTurn);
                    }
                    else if (--degrees[prevMouse][prevCat][prevTurn] == 0)
                    {
                        int loseResult = prevTurn == MOUSE_TURN ? CAT_WIN : MOUSE_WIN;
                        results[prevMouse][prevCat][prevTurn] = loseResult;
                        qu.emplace(prevMouse, prevCat, prevTurn);
                    }
                }
            }
        }
        return results[1][2][MOUSE_TURN];
    }

    vector<tuple<int, int, int>> GetPrevStates(int mouse, int cat, int turn)
    {
        vector<tuple<int, int, int>> prevStates;
        int prevTurn = turn == MOUSE_TURN ? CAT_TURN : MOUSE_TURN;
        if (prevTurn == MOUSE_TURN)
            for (int &prev : graph[mouse])
                prevStates.emplace_back(prev, cat, prevTurn);
        else
            for (int &prev : graph[cat])
                if (prev != 0)
                    prevStates.emplace_back(mouse, prev, prevTurn);
        return prevStates;
    }
};

int main()
{
    io;
    return 0;
}
