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
    string addStrings(string num1, string num2)
    {
        if (num1.size() < num2.size())
            swap(num1, num2);
        auto it1 = num1.rbegin();
        auto it2 = num2.rbegin();
        stringstream ss;
        int add = 0;
        while (it1 != num1.rend())
        {
            int sum = add + *it1 - '0';
            it1++;
            if (it2 != num2.rend())
            {
                sum += *it2 - '0';
                it2++;
            }
            ss << sum % 10;
            add = sum / 10;
        }
        if (add)
            ss << 1;
        auto ans = ss.str();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
