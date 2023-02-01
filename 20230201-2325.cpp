#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;

const ll MOD = 1000000007;

class Solution {
public:
    string decodeMessage(string &key, string &message) {
        char m[26];
        memset(m, 0, sizeof(m));
        char ch = 'a';
        for (int i = 0; ch <= 'z'; i++)
        {
            int idx = key[i] - 'a';
            if (idx < 0)
                continue;
            if (!m[idx])
            {
                m[idx] = ch;
                ch++;
            }
        }
        for (char &mess : message)
        {
            int idx = mess - 'a';
            if (idx < 0)
                continue;
            mess = m[idx];
        }
        return message;
    }
};

int main()
{
    io;
    Solution s;
    string k1 = "the quick brown fox jumps over the lazy dog";
    string m1 = "vkbs bs t suepuv";
    cout << s.decodeMessage(k1, m1) << endl;
    string k2 = "eljuxhpwnyrdgtqkviszcfmabo";
    string m2 = "zwx hnfx lqantp mnoeius ycgk vcnjrdb";
    cout << s.decodeMessage(k2, m2) << endl;
    return 0;
}