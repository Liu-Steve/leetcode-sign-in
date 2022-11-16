#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vv;

class Solution {
public:
    int numMatchingSubseq(const string s, const vector<string>& words) {
        unordered_map<string, int> m;
        int res = 0, slen = s.size();
        for (const string &word : words)
        {
            if (m.find(word) != m.end())
            {
                res += m[word];
                continue;
            }
            int p = 0, len = word.size();
            for (int i = 0; i < slen; ++i)
            {
                if (word[p] == s[i])
                    p++;
                if (p >= len) {
                    res++;
                    m.emplace(word, 1);
                    break;
                }
            }
            m.emplace(word, 0);
        }
        return res;
    }
};

// class Solution
// {
// public:
//     int numMatchingSubseq(const string s, const vector<string> &words)
//     {
//         int res = 0, slen = s.size(), wlen = words.size();
//         int p[wlen], lens[wlen];
//         memset(p, 0, sizeof(p));
//         for (int i = 0; i < wlen; ++i)
//             lens[i] = words[i].size();
//         for (int i = 0; i < slen; ++i)
//         {
//             if (word[p] == s[i])
//                 p++;
//             if (p >= len)
//             {
//                 res++;
//                 break;
//             }
//         }
//         return res;
//     }
// };

int main()
{
    io;
    Solution s;
    cout << s.numMatchingSubseq("abcde", {"a", "bb", "acd", "ace"}) << endl;
    return 0;
}