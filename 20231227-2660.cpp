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
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        bool lst1 = false, lst2 = false;
        int ans1 = 0, ans2 = 0;
        for (int p : player1)
        {
            if (lst1 || lst2)
                ans1 += p;
            ans1 += p;
            lst1 = lst2;
            lst2 = (p == 10);
        }
        lst1 = false, lst2 = false;
        for (int p : player2)
        {
            if (lst1 || lst2)
                ans2 += p;
            ans2 += p;
            lst1 = lst2;
            lst2 = (p == 10);
        }
        if (ans1 > ans2)
            return 1;
        else if (ans1 < ans2)
            return 2;
        return 0;
    }
};

int main()
{
    io;
    return 0;
}
