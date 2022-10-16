#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int type1 = -1, type2 = -1, t1_begin = 0, t2_begin = 0;
        int l = 0, max_f = 0;
        int len = fruits.size();
        bool end1 = true;
        for (int i = 0; i < len; ++i)
        {
            int f = fruits[i];
            if (f == type1)
            {
                if (!end1)
                {
                    end1 = true;
                    t1_begin = i;
                }
            }
            else if (f == type2)
            {
                if (end1)
                {
                    end1 = false;
                    t2_begin = i;
                }
            }
            else
            {
                if (end1)
                {
                    end1 = false;
                    l = t1_begin;
                    type2 = f;
                    t2_begin = i;
                }
                else
                {
                    end1 = true;
                    l = t2_begin;
                    type1 = f;
                    t1_begin = i;
                }
            }
            max_f = max(max_f, i - l + 1);
        }
        return max_f;
    }
};

int main()
{
    io;
    Solution s;
    vector<int> v1 = {1, 2, 1};
    cout << s.totalFruit(v1) << endl;
    vector<int> v2 = {0, 1, 2, 2};
    cout << s.totalFruit(v2) << endl;
    vector<int> v3 = {1, 2, 3, 2, 2};
    cout << s.totalFruit(v3) << endl;
    vector<int> v4 = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << s.totalFruit(v4) << endl;
    vector<int> v5 = {1, 1, 1};
    cout << s.totalFruit(v5) << endl;
    vector<int> v6 = {};
    cout << s.totalFruit(v6) << endl;
    return 0;
}