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

class Solution
{
public:
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        auto toLower = [&](string str) -> string
        {
            for (char &ch : str)
                if (ch >= 'A' && ch <= 'Z')
                    ch = ch - 'A' + 'a';
            return str;
        };
        auto toVowelA = [&](string str) -> string
        {
            for (char &ch : str)
                if (ch >= 'A' && ch <= 'Z')
                    ch = ch - 'A' + 'a';
            for (char &ch : str)
                switch (ch)
                {
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    ch = 'a';
                    break;
                default:
                    break;
                }
            return str;
        };
        unordered_map<string, int> full, lowerCase, vowel;
        for (int i = 0; i < wordlist.size(); ++i)
        {
            string &f = wordlist[i];
            string l = toLower(f);
            string v = toVowelA(f);
            if (!full.count(f))
                full[f] = i;
            if (!lowerCase.count(l))
                lowerCase[l] = i;
            if (!vowel.count(v))
                vowel[v] = i;
        }
        vector<string> ans;
        for (auto &q : queries)
        {
            if (full.count(q))
            {
                ans.push_back(wordlist[full[q]]);
                continue;
            }
            string l = toLower(q);
            if (lowerCase.count(l))
            {
                ans.push_back(wordlist[lowerCase[l]]);
                continue;
            }
            string v = toVowelA(q);
            if (vowel.count(v))
            {
                ans.push_back(wordlist[vowel[v]]);
                continue;
            }
            ans.emplace_back();
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
