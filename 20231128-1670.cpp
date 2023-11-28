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

class FrontMiddleBackQueue
{
private:
    deque<int> q1, q2;

public:
    FrontMiddleBackQueue()
    {
    }

    void pushFront(int val)
    {
        q1.push_front(val);
        if (q1.size() - q2.size() >= 2)
        {
            q2.push_front(q1.back());
            q1.pop_back();
        }
    }

    void pushMiddle(int val)
    {
        if (q1.size() > q2.size())
        {
            q2.push_front(q1.back());
            q1.pop_back();
        }
        q1.push_back(val);
    }

    void pushBack(int val)
    {
        q2.push_back(val);
        if (q2.size() > q1.size())
        {
            q1.push_back(q2.front());
            q2.pop_front();
        }
    }

    int popFront()
    {
        if (q1.empty())
            return -1;
        int ret = q1.front();
        q1.pop_front();
        if (q2.size() > q1.size())
        {
            q1.push_back(q2.front());
            q2.pop_front();
        }
        return ret;
    }

    int popMiddle()
    {
        if (q1.empty())
            return -1;
        int ret = q1.back();
        q1.pop_back();
        if (q2.size() > q1.size())
        {
            q1.push_back(q2.front());
            q2.pop_front();
        }
        return ret;
    }

    int popBack()
    {
        if (q1.empty())
            return -1;
        if (q2.empty())
        {
            int ret = q1.back();
            q1.pop_back();
            return ret;
        }
        int ret = q2.back();
        q2.pop_back();
        if (q1.size() - q2.size() >= 2)
        {
            q2.push_front(q1.back());
            q1.pop_back();
        }
        return ret;
    }
};

int main()
{
    io;
    FrontMiddleBackQueue q;
    q.pushFront(1);
    q.pushBack(2);
    q.pushMiddle(3);
    q.pushMiddle(4);
    cout << q.popFront() << endl;
    cout << q.popMiddle() << endl;
    cout << q.popMiddle() << endl;
    cout << q.popBack() << endl;
    cout << q.popFront() << endl;
    return 0;
}
