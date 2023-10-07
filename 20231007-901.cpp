#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int> > st;

    StockSpanner() {
        st.push({INT32_MAX, 0});
    }
    
    int next(int price) {
        int res = 1;
        while (st.top().first <= price)
        {
            res += st.top().second;
            st.pop();
        }
        st.push({price, res});
        return res;
    }
};

int main() {
    io;
    StockSpanner s;
    int num = -1;
    while (num)
    {
        cin >> num;
        cout << s.next(num) << endl;
    }
    return 0;
}