#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Node
{
    Node(char ch) : name(ch), left(nullptr), right(nullptr) {}
    char name;
    Node* left;
    Node* right;
};

int findIndex(const string& in, int in0, int in1, char key)
{
    for (int i = in0; i <= in1; i++)
    {
        if (in[i] == key) return i;
    }
    return -1;
}

Node* getTree(const string& po, const string& in, int po0, int po1, int in0, int in1)
{
    if (po0 > po1 || in0 > in1) return nullptr;
    char rootVal = po[po1];
    int rootIndex = findIndex(in, in0, in1, rootVal);
    if (rootIndex == -1) return nullptr;
    int leftSize = rootIndex - in0;
    int rightSize = in1 - rootIndex;
    Node* root = new Node(rootVal);
    root->left = getTree(po, in, po0, po0 + leftSize - 1, in0, rootIndex - 1);
    root->right = getTree(po, in, po0 + leftSize, po1 - 1, rootIndex + 1, in1);
    if ((leftSize > 0 && root->left == nullptr) || (rightSize > 0 && root->right == nullptr))
    {
        return nullptr;
    }
    return root;
}

int getH(Node* root)
{
    if (root == nullptr) return 0;
    return max(getH(root->left), getH(root->right)) + 1;
}

void getPreorder(Node* root, string& pre)
{
    if (root == nullptr) return;
    pre += root->name;
    getPreorder(root->left, pre);
    getPreorder(root->right, pre);
}

int main()
{
    string postorder, inorder;
    while (cin >> postorder >> inorder)
    {
        if (postorder.size() != inorder.size())
        {
            cout << "INVALID" << endl;
            continue;
        }
        Node* root = getTree(postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
        if (root != nullptr)
        {
            int h = getH(root);
            string preorder;
            getPreorder(root, preorder);
            cout << h - 1 << endl;
            cout << preorder << endl;
        }
        else
        {
            cout << "INVALID" << endl;
        }
    }

    return 0;
}
