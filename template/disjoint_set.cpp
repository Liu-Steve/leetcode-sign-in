#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

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

int main()
{
    io;
    return 0;
}
