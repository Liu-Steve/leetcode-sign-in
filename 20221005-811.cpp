#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;
using ll = long long;

typedef struct node
{
    string name;
    unordered_map<string, node *> sub;
    ll cnt;
    node(string n, ll c = 0)
    {
        name = n;
        cnt = c;
    }
} Node;

class Solution
{
public:
    Node *tree = new Node("");

    vector<string> *res = new vector<string>();

    void addRes(Node *node, string base)
    {
        stringstream ss;
        base = node->name + base;
        ss << node->cnt << ' ' << base;
        string s = ss.str();
        res->emplace_back(s);
        base = "." + base;
        for (auto p : node->sub)
        {
            addRes(p.second, base);
        }
    }

    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        for (string visit : cpdomains)
        {
            Node *now = tree;
            ll cnt = parseNum(visit);
            ll len = visit.length();
            ll domainLen = 0;
            for (ll i = len - 1; i >= 0; --i)
            {
                if (visit[i] == ' ' || visit[i] == '.')
                {
                    string domain = visit.substr(i + 1, domainLen);
                    auto it = now->sub.find(domain);
                    if (it == now->sub.end())
                    {
                        Node *newNode = new Node(domain, cnt);
                        now->sub.insert({domain, newNode});
                        now = newNode;
                    }
                    else
                    {
                        Node *domainNode = it->second;
                        domainNode->cnt += cnt;
                        now = domainNode;
                    }
                    domainLen = 0;
                    if (visit[i] == ' ')
                        break;
                }
                else
                {
                    domainLen++;
                }
            }
        }

        for (auto p : tree->sub)
        {
            addRes(p.second, "");
        }

        return *res;
    }

    ll parseNum(const string &str)
    {
        ll res = 0;
        for (ll i = 0; i < 5; ++i)
        {
            if (str[i] == ' ')
                break;
            res *= 10;
            res += str[i] - '0';
        }
        return res;
    }
};

int main()
{
    io;
    Solution s;
    vector<string> cpdomains = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    vector<string> res = s.subdomainVisits(cpdomains);
    for (string str : res)
    {
        cout << str << endl;
    }
    return 0;
}