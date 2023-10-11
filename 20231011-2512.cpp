#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

inline bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first > p2.first;
}

class Solution
{
public:
    vector<int> topStudents(
        vector<string> &positive_feedback,
        vector<string> &negative_feedback,
        vector<string> &report,
        vector<int> &student_id,
        int k)
    {
        unordered_set<string> po;
        unordered_set<string> ne;
        for (string &str : positive_feedback)
            po.insert(str);
        for (string &str : negative_feedback)
            ne.insert(str);
        int n = report.size();
        vector<pair<int, int>> vp(n);
        for (int i = 0; i < n; ++i)
        {
            string &rep = report[i];
            int score = 0;
            ostringstream s;
            for (char ch : rep)
            {
                if (ch != ' ')
                {
                    s.put(ch);
                    continue;
                }
                string word = s.str();
                bool isPo = (po.find(word) != po.end());
                bool isNe = (ne.find(word) != ne.end());
                if (isPo)
                    score += 3;
                if (isNe)
                    score--;
                s.str("");
            }
            string word = s.str();
            bool isPo = (po.find(word) != po.end());
            bool isNe = (ne.find(word) != ne.end());
            if (isPo)
                score += 3;
            if (isNe)
                score--;
            s.str("");
            vp[i] = {score, student_id[i]};
        }
        sort(vp.begin(), vp.end(), cmp);
        vector<int> res(k);
        for (int i = 0; i < k; ++i)
        {
            res[i] = vp[i].second;
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
