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
typedef pair<ll, ll> pr;

const ll MOD = 1000000007;

class Solution
{
public:
    bool areSentencesSimilar(string_view sentence1, string_view sentence2)
    {
        if (sentence1.size() > sentence2.size())
            swap(sentence1, sentence2);
        int bias = sentence2.size() - sentence1.size();
        int l = -1;
        int s1 = sentence1.size();
        int s2 = sentence2.size();
        bool fin = true;
        for (int i = 0; i < s1; ++i)
        {
            if (sentence1[i] != sentence2[i])
            {
                fin = false;
                break;
            }
            if (sentence1[i] == ' ')
                l = i;
        }
        if (bias == 0)
            return fin;
        if (fin && sentence2[s1] == ' ')
            return true;
        for (int i = s1 - 1; i > l; --i)
            if (sentence1[i] != sentence2[i + bias])
                return false;
        if (sentence2[l + bias] != ' ')
            return false;
        return true;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.areSentencesSimilar("My name is Haley", "My Haley") << endl;
    cout << s.areSentencesSimilar("My Haley", "My name is Haley") << endl;
    cout << s.areSentencesSimilar("of", "A lot of words") << endl;
    cout << s.areSentencesSimilar("Eating right now", "Eating") << endl;
    cout << s.areSentencesSimilar("Luky", "Lucccky") << endl;
    cout << s.areSentencesSimilar("My name is Haley", "My name issss a Haley") << endl;
    return 0;
}