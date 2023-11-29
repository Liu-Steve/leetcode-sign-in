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

class SmallestInfiniteSet {
private:
    int p;
    set<int> s;

public:
    SmallestInfiniteSet() {
        p = 1;
    }
    
    int popSmallest() {
        if (s.empty())
            return p++;
        int ret = *s.begin();
        s.erase(s.begin());
        return ret;
    }
    
    void addBack(int num) {
        if (num < p)
            s.insert(num);
    }
};

int main()
{
    io;
    return 0;
}
