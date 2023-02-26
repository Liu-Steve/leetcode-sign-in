#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<double, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size(), res = 0;
        vector<int> count(26);
        for (auto c : letters) {
            count[c - 'a']++;
        }
        for (int s = 1; s < (1 << n); s++) {
            vector<int> wordCount(26); // 统计子集 s 所有单词的字母数目
            for (int k = 0; k < n; k++) {
                if ((s & (1 << k)) == 0) { // words[k] 不在子集 s 中
                    continue;
                }
                for (auto c : words[k]) {
                    wordCount[c - 'a']++;
                }
            }
            bool ok = true; // 判断子集 s 是否合法
            int sum = 0; // 保存子集 s 的得分
            for (int i = 0; i < 26; i++) {
                sum += score[i] * wordCount[i];
                ok = ok && (wordCount[i] <= count[i]);
            }
            if (ok) {
                res = max(res, sum);
            }
        }
        return res;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}