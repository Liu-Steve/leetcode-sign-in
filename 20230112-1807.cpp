#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vv;
typedef pair<ll, ll> pr;

const ll MOD = 1000000007;

class Solution
{
public:
    string evaluate(string_view s, vector<vector<string>> &knowledge)
    {
        unordered_map<string_view, string *> k;
        for (vector<string> &v : knowledge)
            k.emplace(v[0], &(v[1]));
        ostringstream o;
        int len = s.size();
        for (int i = 0; i < len; ++i)
        {
            if (s[i] != '(')
            {
                o << s[i];
                continue;
            }
            int j = 0;
            for (j = i + 1; s[j] != ')'; ++j)
                ;
            string_view sv = s.substr(i + 1, j - 1 - i);
            if (k.find(sv) == k.end())
                o << '?';
            else
                o << *(k[sv]);
            i = j;
        }
        return o.str();
    }
};

int main()
{
    io;
    Solution s;
    string s1 = "(name)is(age)yearsold";
    vector<vs> v1 = {{"name", "bob"}, {"age", "two"}};
    cout << s.evaluate(s1, v1) << endl;
    string s2 = "hi(name)";
    vector<vs> v2 = {{"a","b"}};
    cout << s.evaluate(s2, v2) << endl;
    string s3 = "(a)(a)(a)aaa";
    vector<vs> v3 = {{"a","yes"}};
    cout << s.evaluate(s3, v3) << endl;
    return 0;
}