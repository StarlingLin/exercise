#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int max_sum = INT_MIN;
vector<int> final_path;

struct Tree
{
    int val;
    Tree* left;
    Tree* right;
    Tree(int x) : val(x), left(nullptr), right(nullptr) {}
};

Tree* makeTree(vector<int>& data, int& i)
{
    if (i >= data.size() || data[i] == 0)
    {
        ++i;
        return nullptr;
    }
    Tree* root = new Tree(data[i++]);
    root->left = makeTree(data, i);
    root->right = makeTree(data, i);
    return root;
}

vector<int> dfs(Tree* root)
{
    if (root == nullptr)
    {
        return vector<int>();
    }

    vector<int> left = dfs(root->left);
    vector<int> right = dfs(root->right);

    int leftSum = 0, rightSum = 0;
    for (int val : left)
    {
        leftSum += val;
    }
    for (int val : right)
    {
        rightSum += val;
    }

    int sum = root->val + max(0, max(leftSum, rightSum));

    if (sum > max_sum || (sum == max_sum && (leftSum > rightSum ? left.size() : right.size()) < final_path.size()))
    {
        max_sum = sum;
        final_path.clear();
        final_path.push_back(root->val);

        if (leftSum > rightSum && leftSum > 0)
        {
            final_path.insert(final_path.end(), left.begin(), left.end());
        }
        else if (rightSum > 0)
        {
            final_path.insert(final_path.end(), right.begin(), right.end());
        }
    }

    if (leftSum > rightSum || (leftSum == rightSum && left.size() <= right.size()))
    {
        left.insert(left.begin(), root->val);
        return left;
    }
    else
    {
        right.insert(right.begin(), root->val);
        return right;
    }
}

int main()
{
    vector<int> data;
    int val, i = 0;

    while (cin >> val)
    {
        data.push_back(val);
    }

    Tree* root = makeTree(data, i);

    dfs(root);

    cout << max_sum << endl;
    for (int i : final_path)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
