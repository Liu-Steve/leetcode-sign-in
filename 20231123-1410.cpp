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

class Solution
{
public:
    string entityParser(string text)
    {
        vector<pair<string, char>> entity = {
            {"&quot;", '"'},
            {"&apos;", '\''},
            {"&amp;", '&'},
            {"&gt;", '>'},
            {"&lt;", '<'},
            {"&frasl;", '/'}};
        string ans = "";
        int n = text.size();
        for (int i = 0; i < n;)
        {
            if (text[i] != '&')
            {
                ans.push_back(text[i++]);
                continue;
            }
            bool fd = false;
            for (auto &[e, c] : entity)
                if (e == text.substr(i, e.size()))
                {
                    ans.push_back(c);
                    i += e.size();
                    fd = true;
                    break;
                }
            if (!fd)
                ans.push_back(text[i++]);
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;

    cout << s.entityParser("&amp; is an HTML entity but &ambassador; is not.") << endl;

    return 0;
}
