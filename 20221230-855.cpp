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
typedef pair<int, int> pr;

int n;

class st
{
public:
    int l;
    int r;
    int d;
    int p;
    st(int newl, int newr)
    {
        l = newl;
        r = newr;
        if (l == -1)
        {
            d = r;
            p = 0;
        }
        else if (r == n)
        {
            d = n - 1 - l;
            p = n - 1;
        }
        else
        {
            d = (r - l) / 2;
            p = l + d;
        }
    }
};

struct cmp
{
    bool operator()(st &st1, st &st2)
    {
        if (st1.d == st2.d)
            return st1.p > st2.p;
        return st1.d < st2.d;
    }
};

class ExamRoom
{
private:
    priority_queue<st, vector<st>, cmp> q;
    set<int> s;

    bool isvalid(st &t)
    {
        auto itl = s.find(t.l);
        auto itr = s.find(t.r);
        if (t.l != -1 && itl == s.end())
            return false;
        if (t.r != n && itr == s.end())
            return false;
        if (t.l == -1 && t.r == n)
            return s.empty();
        if (t.l == -1)
            return *itr == *s.begin();
        if (t.r == n)
            return *itl == *s.rbegin();
        if (*(++itl) != *itr)
            return false;
        return true;
    }

public:
    ExamRoom(int num)
    {
        n = num;
        q.emplace(-1, n);
    }

    int seat()
    {
        st t = q.top();
        q.pop();
        while (!q.empty() && !isvalid(t))
        {
            t = q.top();
            q.pop();
        }
        if (!isvalid(t))
            t = st(-1, n);
        if (t.l + 1 < t.p)
            q.emplace(t.l, t.p);
        if (t.p + 1 < t.r)
            q.emplace(t.p, t.r);
        s.insert(t.p);
        return t.p;
    }

    void leave(int p)
    {
        auto itl = s.find(p);
        auto itr = s.find(p);
        int l = (*itl != *s.begin() ? *(--itl) : -1);
        int r = (*itr != *s.rbegin() ? *(++itr) : n);
        q.emplace(l, r);
        s.erase(p);
    }
};

int main()
{
    io;
    ExamRoom e(10);
    cout << e.seat() << endl;
    cout << e.seat() << endl;
    cout << e.seat() << endl;
    e.leave(0);
    e.leave(4);
    cout << e.seat() << endl;
    cout << e.seat() << endl;
    cout << e.seat() << endl;
    cout << e.seat() << endl;
    cout << e.seat() << endl;
    cout << e.seat() << endl;
    cout << e.seat() << endl;
    cout << e.seat() << endl;
    cout << e.seat() << endl;
    e.leave(0);
    e.leave(4);
    cout << e.seat() << endl;
    cout << e.seat() << endl;
    e.leave(7);
    cout << e.seat() << endl;
    e.leave(3);
    cout << e.seat() << endl;
    e.leave(3);
    cout << e.seat() << endl;
    e.leave(9);
    cout << e.seat() << endl;
    e.leave(0);
    e.leave(8);
    cout << e.seat() << endl;
    cout << e.seat() << endl;
    e.leave(2);
    return 0;
}