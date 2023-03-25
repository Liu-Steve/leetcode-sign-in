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

typedef struct node
{
    int nxt[26];
    int fail;
    bool e; // is end of string
    node()
    {
        memset(nxt, 0, sizeof(nxt));
        fail = 0;
        e = false;
    }
    int &operator[](int idx)
    {
        return nxt[idx];
    }
} Node;

class AC
{
private:
    vector<Node> trie;
    int now;

public:
    AC()
    {
        trie.emplace_back();
        now = 0;
    }

    void insert(string &str)
    {
        int u = 0;
        for (char ch : str)
        {
            int c = ch - 'a';
            if (trie[u][c] != 0)
            {
                u = trie[u][c];
                continue;
            }
            trie.emplace_back();
            int nxt_idx = trie.size() - 1;
            trie[u][c] = nxt_idx;
            u = nxt_idx;
        }
        trie[u].e = true;
    }

    void build()
    {
        queue<int> q;
        for (int i = 0; i < 26; ++i)
            if (trie[0][i])
                q.push(trie[0][i]);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; ++i)
                if (trie[u][i])
                {
                    // child's fail is the next of father's fail
                    trie[trie[u][i]].fail = trie[trie[u].fail][i];
                    q.push(trie[u][i]);
                }
                else
                    trie[u][i] = trie[trie[u].fail][i];
            // for string like abab & ba
            // when recognized aba should return true
            if (trie[trie[u].fail].e)
                trie[u].e = true;
        }
    }

    bool query(char ch)
    {
        int c = ch - 'a';
        now = trie[now][c];
        return trie[now].e;
    }
};

class StreamChecker
{
private:
    AC ac;

public:
    StreamChecker(vector<string> &words)
    {
        for (string &str : words)
            ac.insert(str);
        ac.build();
    }

    bool query(char letter)
    {
        return ac.query(letter);
    }
};

int main()
{
    io;
    vs v1 = {"cd", "f", "kl"};
    StreamChecker s1(v1);
    cout << s1.query('a') << ' ';
    cout << s1.query('b') << ' ';
    cout << s1.query('c') << ' ';
    cout << s1.query('d') << ' ';
    cout << s1.query('e') << ' ';
    cout << s1.query('f') << ' ';
    cout << s1.query('g') << ' ';
    cout << s1.query('h') << ' ';
    cout << s1.query('i') << ' ';
    cout << s1.query('j') << ' ';
    cout << s1.query('k') << ' ';
    cout << s1.query('l') << ' ';
    cout << endl;
    vs v2 = {"ab", "ba", "aaab", "abab", "baa"};
    StreamChecker s2(v2);
    cout << s2.query('a') << ' ';
    cout << s2.query('a') << ' ';
    cout << s2.query('a') << ' ';
    cout << s2.query('a') << ' ';
    cout << s2.query('a') << ' ';
    cout << s2.query('b') << ' ';
    cout << s2.query('a') << ' ';
    cout << s2.query('b') << ' ';
    cout << s2.query('a') << ' ';
    cout << s2.query('b') << ' ';
    cout << s2.query('b') << ' ';
    cout << s2.query('b') << ' ';
    cout << s2.query('a') << ' ';
    cout << s2.query('b') << ' ';
    cout << s2.query('a') << ' ';
    cout << s2.query('b') << ' ';
    cout << s2.query('b') << ' ';
    cout << s2.query('b') << ' ';
    cout << s2.query('b') << ' ';
    cout << s2.query('a') << ' ';
    cout << s2.query('b') << ' ';
    cout << s2.query('a') << ' ';
    cout << s2.query('b') << ' ';
    cout << s2.query('a') << ' ';
    cout << s2.query('a') << ' ';
    cout << s2.query('a') << ' ';
    cout << s2.query('b') << ' ';
    cout << s2.query('a') << ' ';
    cout << s2.query('a') << ' ';
    cout << s2.query('a') << ' ';
    cout << endl;
    return 0;
}