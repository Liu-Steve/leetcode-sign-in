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

class DSet
{
private:
    int *fa;
    int n;
    int findFa(int node)
    {
        while (fa[node] >= 0)
        {
            node = fa[node];
        }
        return node;
    }

public:
    DSet(int n)
    {
        fa = new int[n];
        for (int i = 0; i < n; ++i)
            fa[i] = -1;
    }

    bool find(int n1, int n2)
    {
        return findFa(n1) == findFa(n2);
    }

    void add(int n1, int n2)
    {
        int fa1 = findFa(n1);
        int fa2 = findFa(n2);
        if (fa1 == fa2)
            return;
        if (fa[fa1] > fa[fa2])
        {
            fa[fa2] += fa[fa1];
            fa[fa1] = fa2;
        }
        else
        {
            fa[fa1] += fa[fa2];
            fa[fa2] = fa1;
        }
    }
};

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        DSet s(n);
        for (vector<int> &e : edges)
            s.add(e[0], e[1]);
        return s.find(source, destination);
    }
};

int main()
{
    io;
    Solution s;
    vv v1 = {{0, 1}, {1, 2}, {2, 0}};
    cout << s.validPath(3, v1, 0, 2) << endl;
    vv v2 = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    cout << s.validPath(6, v2, 0, 5) << endl;
    return 0;
}