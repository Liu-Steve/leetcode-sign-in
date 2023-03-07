#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<ll, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
public:
    vector<string> braceExpansionII(string_view expression)
    {
        int i = 0;
        int len = expression.size();

        function<set<string>()> d = [&]()
        {
            set<string> ans = {""};
            while (i < len)
            {
                char ch = expression[i];
                i++;
                if (ch == ',')
                {
                    ans.merge(d());
                    break;
                }
                else if (ch == '}')
                    break;
                else if (ch == '{')
                {
                    auto con = d();
                    set<string> newans;
                    for (auto &str1 : ans)
                        for (auto &str2 : con)
                            newans.insert(str1 + str2);
                    ans = newans;
                }
                else
                {
                    set<string> newans;
                    for (auto &str : ans)
                        newans.insert(str + ch);
                    ans = newans;
                }
            }
            return ans;
        };

        auto ans = d();
        return vector(ans.begin(), ans.end());
    }
};

int main()
{
    io;
    Solution s;
    auto v1 = s.braceExpansionII("abc");
    for (auto str : v1)
        cout << str << ' ';
    cout << endl;
    auto v2 = s.braceExpansionII("{{a,b,{ab,ac}}{def,dfe},g,h{i,j}{k,lm}}");
    for (auto str : v2)
        cout << str << ' ';
    cout << endl;
    auto v3 = s.braceExpansionII("{a,b}{c,{d,e}}");
    for (auto str : v3)
        cout << str << ' ';
    cout << endl;
    auto v4 = s.braceExpansionII("{{a,z},a{b,c},{ab,z}}");
    for (auto str : v4)
        cout << str << ' ';
    cout << endl;
    return 0;
}