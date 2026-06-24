#include <bits/stdc++.h>

#include <vector>
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef vector<vl> vvl;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<int, int> pr;
typedef pair<ll, ll> prl;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<ll, int> memory;

constexpr long long MOD = 1000000007LL;

class Solution {
private:
    long long merge(vector<int>& arr, vector<int>& temp, int l, int m, int r) {
        int i = l;
        int j = m + 1;
        int k = l;
        long long cnt = 0;
        while (i <= m && j <= r) {
            if (arr[i] <= arr[j]) {
                temp[k] = arr[i];
                i++;
            } else {
                temp[k] = arr[j];
                cnt += m - i + 1;
                j++;
            }
            k++;
        }
        while (i <= m) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        while (j <= r) {
            temp[k] = arr[j];
            j++;
            k++;
        }
        for (int t = l; t <= r; ++t) {
            arr[t] = temp[t];
        }
        return cnt;
    }

    long long merge_sort(vector<int>& arr, vector<int>& temp, int l, int r) {
        if (l >= r) {
            return 0;
        }
        int m = (l + r) / 2;
        long long cnt = 0;
        cnt += merge_sort(arr, temp, l, m);
        cnt += merge_sort(arr, temp, m + 1, r);
        cnt += merge(arr, temp, l, m, r);
        return cnt;
    }

public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> arr(n + 1), temp(n + 1);
        for (int i = 0; i < n; ++i) {
            arr[i + 1] = arr[i] + (nums[i] == target ? -1 : 1);
        }
        return merge_sort(arr, temp, 0, n);
    }
};

int main() {
    io;
    return 0;
}