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
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string res = s;
        s = s + s;
        int g = gcd(b, n);
        int add_cnt = a * 10 / gcd(a, 10);
        
        auto add = [&](string& t, int start) {
            int minVal = 10, times = 0;
            for (int i = 0; i < add_cnt; i++) {
                int added = ((t[start] - '0') + i * a) % 10;
                if (added < minVal) {
                    minVal = added;
                    times = i;
                }
            }
            for (int i = start; i < n; i += 2) {
                t[i] = '0' + ((t[i] - '0') + times * a) % 10;
            }
        };

        for (int i = 0; i < n; i += g) {
            string t = s.substr(i, n);
            add(t, 1);
            if (b % 2) {
                add(t, 0);
            }
            res = min(res, t);
        }
        return res;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.findLexSmallestString("5525", 9, 2) << endl;
    cout << s.findLexSmallestString("74", 5, 1) << endl;
    cout << s.findLexSmallestString("0011", 4, 2) << endl;
    cout << s.findLexSmallestString("43987654", 7, 3) << endl;
    return 0;
}