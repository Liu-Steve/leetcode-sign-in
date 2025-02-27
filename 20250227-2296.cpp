#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#define MOD 1000000007LL

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

class TextEditor
{
private:
    struct DoublyNode
    {
        char val;
        DoublyNode *front;
        DoublyNode *back;
        DoublyNode() : val(' '), front(nullptr), back(nullptr) {}
        DoublyNode(char x) : val(x), front(nullptr), back(nullptr) {}
    } *ptr;

public:
    TextEditor()
    {
        ptr = new DoublyNode();
    }

    void addText(string text)
    {
        for (char ch : text)
        {
            DoublyNode *temp = new DoublyNode(ch);
            temp->front = ptr;
            temp->back = ptr->back;
            if (ptr->back != nullptr)
                ptr->back->front = temp;
            ptr->back = temp;
            ptr = temp;
        }
    }

    int deleteText(int k)
    {
        int ans = 0;
        for (int i = 0; i < k; ++i)
        {
            if (ptr->val == ' ')
                return ans;
            ptr->front->back = ptr->back;
            if (ptr->back != nullptr)
                ptr->back->front = ptr->front;
            DoublyNode *temp = ptr;
            ptr = ptr->front;
            delete temp;
            ans++;
        }
        return ans;
    }

    string cursorLeft(int k)
    {
        string ans;
        for (int i = 0; i < k; ++i)
        {
            if (ptr->val == ' ')
                return ans;
            ptr = ptr->front;
        }
        DoublyNode *temp = ptr;
        for (int i = 0; i < 10; ++i)
        {
            if (temp->val == ' ')
                break;
            ans.push_back(temp->val);
            temp = temp->front;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string cursorRight(int k)
    {
        string ans;
        for (int i = 0; i < k; ++i)
        {
            if (ptr->back == nullptr)
                break;
            ptr = ptr->back;
        }
        DoublyNode *temp = ptr;
        for (int i = 0; i < 10; ++i)
        {
            if (temp->val == ' ')
                break;
            ans.push_back(temp->val);
            temp = temp->front;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
