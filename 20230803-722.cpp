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
    vector<string> removeComments(vector<string> &source)
    {
        bool com = false;       // multi comment
        bool dash = false;      // find '/'
        bool star = false;      // find '*'
        bool lastIsCom = false; // last char is comment
        vector<string>
            ans;
        string ss;
        for (string str : source)
        {
            for (int i = 0; i < str.size(); ++i)
            {
                char ch = str[i];
                dash = i > 0 && !lastIsCom ? str[i - 1] == '/' : false;
                star = i > 0 && !lastIsCom ? str[i - 1] == '*' : false;
                lastIsCom = false;
                if (ch == '/')
                {
                    if (!com && dash) // single comment
                    {
                        ss.pop_back();
                        lastIsCom = true;
                        break;
                    }
                    if (com && star) // end m-comment
                    {
                        com = false;
                        lastIsCom = true;
                        continue;
                    }
                }
                if (ch == '*' && !com && dash) // start m-comment
                {
                    ss.pop_back();
                    com = true;
                    lastIsCom = true;
                    continue;
                }
                if (!com)
                    ss += ch;
            }
            if (com)
                continue;
            if (ss != "")
                ans.emplace_back(ss);
            ss = "";
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
