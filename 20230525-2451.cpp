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

class Solution {
private:
    vector<int> get(string &str)
    {
        vector<int> ans;
        for (int i = 0; i < str.size() - 1; ++i)
            ans.emplace_back(str[i + 1] - str[i]);
        return ans;
    }

public:
    string oddString(vector<string>& words) {
        auto v1 = get(words[0]);
        auto v2 = get(words[1]);
        if (v1 != v2)
            return v1 == get(words[2]) ? words[1] : words[0];
        for (int i = 2; i < words.size(); ++i)
            if (v1 != get(words[i]))
                return words[i];
        return ""; // never happend
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
