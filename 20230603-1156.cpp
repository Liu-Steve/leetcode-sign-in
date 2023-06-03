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
    int maxRepOpt1(string_view text)
    {
        vector<int> cnt(26, 0);
        for (char ch : text)
            cnt[ch - 'a']++;
        int n = text.size();
        int i = 0;
        int j = 0;
        int k = 0;
        int ans = 1;
        while (j < n)
        {
            while (j < n && text[i] == text[j])
                j++;
            if (j == n)
            {
                ans = max(ans, min(j - i + 1, cnt[text[i] - 'a']));
                break;
            }
            k = j + 1;
            while (k < n && text[i] == text[k])
                k++;
            ans = max(ans, min(k - i, cnt[text[i] - 'a']));
            i = j;
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.maxRepOpt1("ababa") << endl;
    cout << s.maxRepOpt1("aaabaaa") << endl;
    cout << s.maxRepOpt1("aaabbaaa") << endl;
    cout << s.maxRepOpt1("aaaaa") << endl;
    cout << s.maxRepOpt1("abcdef") << endl;
    cout << s.maxRepOpt1("a") << endl;
    cout << s.maxRepOpt1("acbaaa") << endl;
    return 0;
}
