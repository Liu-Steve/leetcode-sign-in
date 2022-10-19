#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

// class Solution {
// public:
//     int countStudents(vector<int>& students, vector<int>& sandwiches) {
//         int p = 0, last_p = -1, stu_num = students.size();
//         sandwiches.emplace_back(-1);
//         while (p != last_p)
//         {
//             last_p = p;
//             for(int i = 0; i < stu_num; ++i)
//             {
//                 if (students[i] == sandwiches[p])
//                 {
//                     students[i] = 2;
//                     p++;
//                 }
//             }
//         }
//         return stu_num - p;
//     }
// };

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int num[2] = {0, 0};
        for (int s: students)
            num[s]++;
        for (int s: sandwiches)
        {
            if (num[s])
                num[s]--;
            else
                break;
        }
        return num[0] + num[1];
    }
};

int main() {
    io;
    Solution s;
    vector<int> v1 = {1,1,0,0};
    vector<int> v2 = {0,1,0,1};
    cout << s.countStudents(v1, v2) << endl;
    vector<int> v3 = {1,1,1,0,0,1};
    vector<int> v4 = {1,0,0,0,1,1};
    cout << s.countStudents(v3, v4) << endl;
    return 0;
}