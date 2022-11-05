#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution {
public:
    void execute(stack<pair<char, bool>> &st, bool newVal)
    {
        char sig = st.top().first;
        bool oldVal = st.top().second;
        st.pop();
        switch (sig)
        {
        case '&':
            newVal = newVal && oldVal;
            break;

        case '|':
            newVal = newVal || oldVal;
            break;

        case '!':
            newVal = !newVal;
            break;
        
        default:
            break;
        }
        st.emplace(sig, newVal);
    }

    bool parseBoolExpr(string expression)
    {
        stack<pair<char, bool>> st;
        bool res;
        st.emplace('&', true);
        for (char exe : expression) {
            switch (exe) {
            case '&':
                st.emplace('&', true);
                break;

            case '|':
                st.emplace('|', false);
                break;

            case '!':
                st.emplace('!', true);
                break;

            case ')':
                res = st.top().second;
                st.pop();
                execute(st, res);
                break;

            case 't':
                execute(st, true);
                break;

            case 'f':
                execute(st, false);
                break;

            default:
                break;
            }
        }
        return st.top().second;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.parseBoolExpr("t") << endl;
    cout << s.parseBoolExpr("f") << endl;
    cout << s.parseBoolExpr("!(f)") << endl;
    cout << s.parseBoolExpr("|(f,t)") << endl;
    cout << s.parseBoolExpr("|(&(t,f,t),!(t))") << endl;
    return 0;
}