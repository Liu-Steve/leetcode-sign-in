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

class Spreadsheet
{
private:
    vector<vector<int>> data;

    int getNumber(string_view str)
    {
        int num = 0;
        for (auto it = str.begin(); it != str.end(); ++it)
            num = num * 10 + (*it - '0');
        return num;
    }

    int getCell(string_view cell)
    {
        int col = cell[0] - 'A';
        int row = getNumber(cell.substr(1));
        return data[row][col];
    }

public:
    Spreadsheet(int rows) : data(rows + 1, vector<int>(26))
    {
    }

    void setCell(string_view cell, int value)
    {
        int col = cell[0] - 'A';
        int row = getNumber(cell.substr(1));
        data[row][col] = value;
    }

    void resetCell(string_view cell)
    {
        setCell(cell, 0);
    }

    int getValue(string_view formula)
    {
        int plus = find(formula.begin(), formula.end(), '+') - formula.begin();
        int ans = 0;
        if (formula[1] >= 'A' && formula[1] <= 'Z')
            ans += getCell(formula.substr(1, plus - 1));
        else
            ans += getNumber(formula.substr(1, plus - 1));
        if (formula[plus + 1] >= 'A' && formula[plus + 1] <= 'Z')
            ans += getCell(formula.substr(plus + 1));
        else
            ans += getNumber(formula.substr(plus + 1));
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
