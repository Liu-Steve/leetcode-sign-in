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

class FreqStack
{
private:
    int maxF;
    unordered_map<int, int> cnt;
    vector<stack<int>> st;

public:
    FreqStack()
    {
        maxF = 0;
        st.emplace_back();
    }

    void push(int val)
    {
        if (cnt.find(val) == cnt.end())
        {
            cnt[val] = 1;
        }
        else
        {
            cnt[val]++;
        }
        if (cnt[val] > maxF)
        {
            maxF++;
        }
        if (st.size() - 1 < maxF)
        {
            st.emplace_back();
        }
        st[cnt[val]].emplace(val);
    }

    int pop()
    {
        int ret = st[maxF].top();
        st[maxF].pop();
        if (st[maxF].empty())
        {
            maxF--;
        }
        cnt[ret]--;
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

int main()
{
    io;
    FreqStack &freqStack = *(new FreqStack());
    freqStack.push(5); //堆栈为 [5]
    freqStack.push(7); //堆栈是 [5,7]
    freqStack.push(5); //堆栈是 [5,7,5]
    freqStack.push(7); //堆栈是 [5,7,5,7]
    freqStack.push(4); //堆栈是 [5,7,5,7,4]
    freqStack.push(5); //堆栈是 [5,7,5,7,4,5]
    cout << freqStack.pop() << endl;   //返回 5 ，因为 5 出现频率最高。堆栈变成 [5,7,5,7,4]。
    cout << freqStack.pop() << endl;   //返回 7 ，因为 5 和 7 出现频率最高，但7最接近顶部。堆栈变成 [5,7,5,4]。
    cout << freqStack.pop() << endl;   //返回 5 ，因为 5 出现频率最高。堆栈变成 [5,7,4]。
    cout << freqStack.pop() << endl;   //返回 4 ，因为 4, 5 和 7 出现频率最高，但 4 是最接近顶部的。堆栈变成 [5,7]。
    return 0;
}