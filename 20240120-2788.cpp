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
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    vector<string> splitWordsBySeparator(vector<string> &words, char separator)
    {
        vector<string> ans;
        string str;
        for (string w : words)
        {
            for (char ch : w)
                if (ch != separator)
                    str.push_back(ch);
                else
                {
                    if (str != "")
                        ans.push_back(str);
                    str = "";
                }
            if (str != "")
                ans.push_back(str);
            str = "";
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
