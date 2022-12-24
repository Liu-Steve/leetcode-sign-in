#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vv;

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
    vs po1 = {"smart", "brilliant", "studious"};
    vs ne1 = {"not"};
    vs rp1 = {"this student is studious", "the student is smart"};
    vi id1 = {1, 2};
    vi res1 = s.topStudents(po1, ne1, rp1, id1, 2);
    for (int num : res1)
        cout << num << ' ';
    cout << endl;
    vs po2 = {"smart", "brilliant", "studious"};
    vs ne2 = {"not"};
    vs rp2 = {"this student is not studious", "the student is smart"};
    vi id2 = {1, 2};
    vi res2 = s.topStudents(po2, ne2, rp2, id2, 2);
    for (int num : res2)
        cout << num << ' ';
    cout << endl;
    return 0;
}