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

class KMP
{
private:
    vi getNxt(string &pat)
    {
        int len = pat.size();
        vi nxt(len + 1);
        nxt[0] = -1;
        int i = 0;
        int j = -1;
        while (i < len)
        {
            if (j == -1 || pat[i] == pat[j])
            {
                ++i;
                ++j;
                nxt[i] = j;
            }
            else
                j = nxt[j];
        }
        return nxt;
    }

public:
    /**
     * 找到str中第一次出现模式串pat的下标
     * 下标从0开始
     * 没有则返回-1
     */
    int findFirst(string &str, string &pat)
    {
        int len1 = str.size();
        int len2 = pat.size();
        int i = 0;
        int j = 0;
        vi nxt = getNxt(pat);
        while (i < len1 && j < len2)
        {
            if (j == -1 || str[i] == pat[j])
            {
                i++;
                j++;
            }
            else
                j = nxt[j];
            if (j >= len2)
                return i - j;
        }
        return -1; // 没找到
    }

    /**
     * 找到str中所有出现模式串pat的下标
     * 下标从0开始
     */
    vi findAll(string &str, string &pat)
    {
        vi ans;
        int len1 = str.size();
        int len2 = pat.size();
        int i = 0;
        int j = 0;
        vi nxt = getNxt(pat);
        while (i < len1 && j < len2)
        {
            if (j == -1 || str[i] == pat[j])
            {
                i++;
                j++;
            }
            else
                j = nxt[j];
            if (j >= len2)
            {
                ans.emplace_back(i - j);
                // j = 0;  // 子串不可以重复
                j = nxt[j];  // 子串可以重复
            }
        }
        return ans;
    }
};

int main()
{
    io;
    KMP s;
    string s1 = "12121212123";
    string s2 = "121";
    cout << s.findFirst(s1, s2) << endl;
    for (int n : s.findAll(s1, s2))
        cout << n << ' ';
    cout << endl;
    return 0;
}