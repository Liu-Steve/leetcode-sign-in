#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(const vector<string>& digits, int n) {
        int cnt = digits.size(), len = 0;
        int bit[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int bitp[10];
        int lim[10];
        long long times[11];
        for (int i = 0; i < cnt; ++i)
        {
            int digit = digits[i][0] - '0';
            bit[digit] = 1;
        }
        bitp[0] = 0;
        for (int i = 1; i < 10; ++i)
            bitp[i] = bitp[i - 1] + bit[i];
        times[0] = 1;
        for (int i = 1; i < 11; ++i)
            times[i] = times[i - 1] * cnt;
        for (int i = 0; i < 10; ++i)
        {
            lim[i] = n % 10;
            if(n)
                len = i + 1;
            n /= 10;
        }

        int sum = (cnt == 1) ? (len - 1) : ((times[len] - cnt) / (cnt - 1));
        int i;
        for (i = len - 1; i >= 0; --i)
        {
            int l = lim[i];
            sum += (bitp[l] - bit[l]) * times[i];
            if (!bit[l])
                break;
        }
        if(i == -1 && bit[lim[0]])
            sum++;
        return sum;
    }
};

int main() {
    io;
    Solution s;
    vector<string> v1 = {"1","3","5","7"};
    int n1 = 100;
    cout << s.atMostNGivenDigitSet(v1, n1) << endl;
    vector<string> v2 = {"1","4","9"};
    int n2 = 1000000000;
    cout << s.atMostNGivenDigitSet(v2, n2) << endl;
    vector<string> v3 = {"7"};
    int n3 = 8;
    cout << s.atMostNGivenDigitSet(v3, n3) << endl;
    vector<string> v4 = {"1","2","3","4","5","6","7","8","9"};
    int n4 = 1000000000;
    cout << s.atMostNGivenDigitSet(v4, n4) << endl;
    vector<string> v5 = {"1","3","5","7"};
    int n5 = 3;
    cout << s.atMostNGivenDigitSet(v5, n5) << endl;
    return 0;
}