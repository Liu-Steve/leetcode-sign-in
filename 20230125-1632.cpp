#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;

const ll MOD = 1000000007;

class DSet
{
private:
    int *fa;
    int n;

public:
    DSet(int n)
    {
        fa = new int[n];
        for (int i = 0; i < n; ++i)
            fa[i] = -1;
    }

    int findFa(int node)
    {
        while (fa[node] >= 0)
        {
            node = fa[node];
        }
        return node;
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

    void reset(int n1, int n2)
    {
        fa[n1] = -1;
        fa[n2] = -1;
    }
};

class Solution
{
public:
    vv matrixRankTransform(vv &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // 统计值相同的点
        map<int, vp> mat;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                mat[matrix[i][j]].emplace_back(i, j);

        // 按值从小到大遍历mat安排rank
        vv ans(m, vi(n)); // 答案
        vi row(m);        // 当前行已有的最大rank
        vi col(n);        // 当前列已有的最大rank
        DSet d(m + n);    // 并查集
        vi r(m + n);      // 统计父节点最高rank
        for (auto &[_, points] : mat)
        {
            // 有相同行或列在并查集中会被连在一起
            for (auto &[i, j] : points)
                d.add(i, j + m);
            // 统计每个行列集的最大rank，rank无需在每轮重置
            for (auto &[i, j] : points)
                r[d.findFa(i)] = max({r[d.findFa(i)], row[i], col[j]});
            // 为集合中每个点赋上本集合的最大行列rank+1
            for (auto &[i, j] : points)
                ans[i][j] = row[i] = col[j] = r[d.findFa(i)] + 1;
            // 重置并查集，可以通过均摊证明本操作时间复杂度对每个点为常数
            for (auto &[i, j] : points)
                d.reset(i, j + m);
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vv m1 = {{1, 2}, {3, 4}};
    vv r1 = s.matrixRankTransform(m1);
    for (auto i : r1)
    {
        for (auto j : i)
            cout << j << ' ';
        cout << endl;
    }
    cout << endl;
    vv m2 = {{7, 7}, {7, 7}};
    vv r2 = s.matrixRankTransform(m2);
    for (auto i : r2)
    {
        for (auto j : i)
            cout << j << ' ';
        cout << endl;
    }
    cout << endl;
    vv m3 = {{20, -21, 14}, {-19, 4, 19}, {22, -47, 24}, {-19, 4, 19}};
    vv r3 = s.matrixRankTransform(m3);
    for (auto i : r3)
    {
        for (auto j : i)
            cout << j << ' ';
        cout << endl;
    }
    cout << endl;
    vv m4 = {{7, 3, 6}, {1, 4, 5}, {9, 8, 2}};
    vv r4 = s.matrixRankTransform(m4);
    for (auto i : r4)
    {
        for (auto j : i)
            cout << j << ' ';
        cout << endl;
    }
    return 0;
}