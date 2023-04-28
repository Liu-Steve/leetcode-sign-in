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
    bool equalFrequency(string_view word)
    {
        unordered_map<int, int> m;
        for (char ch : word)
            m[ch - 'a']++;
        int pat = m.size();
        int len = word.size() - 1;
        if (pat == len + 1 || pat == 1)
            return true;

        if (len % pat == 0)
        {
            int cnt = 0;
            int dcnt = len / pat;
            for (auto &[k, v] : m)
                if (v != dcnt)
                    cnt++;
            if (cnt == 1)
                return true;
        }

        if (len % (pat - 1) == 0)
        {
            int cnt = 0;
            int dcnt = len / (pat - 1);
            for (auto &[k, v] : m)
                if (v != dcnt)
                    cnt++;
            if (cnt == 1)
                return true;
        }

        return false;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.equalFrequency("abcdeff") << endl;
    cout << s.equalFrequency("aazz") << endl;
    return 0;
}
