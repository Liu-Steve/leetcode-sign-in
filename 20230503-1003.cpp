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
typedef unordered_map<ll, int> memory;

class Solution
{
public:
    bool isValid(string &s)
    {
        stack<int> st;
        for (char ch : s)
        {
            if (ch == 'a')
                st.emplace(0);
            if (st.empty())
                return false;
            if (ch - 'a' == st.top())
            {
                st.top()++;
                if (st.top() == 3)
                    st.pop();
            }
            else
                return false;
        }
        return st.empty();
    }
};

int main()
{
    io;
    Solution s;
    string s1 = "aabcbc";
    string s2 = "abcabcababcc";
    string s3 = "abccba";
    string s4 = "abbc";
    cout << s.isValid(s1) << endl;
    cout << s.isValid(s2) << endl;
    cout << s.isValid(s3) << endl;
    cout << s.isValid(s4) << endl;
    return 0;
}
