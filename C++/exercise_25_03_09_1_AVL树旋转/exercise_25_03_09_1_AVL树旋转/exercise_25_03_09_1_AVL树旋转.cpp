#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node
{
    int key;
    int height;
    Node* left;
    Node* right;
    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

int getHeight(Node* node)
{
    return node ? node->height : 0;
}

void updateHeight(Node* node)
{
    if (node)
    {
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    }
}

int getBalance(Node* node)
{
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

Node* rightRotate(Node* A)
{
    Node* B = A->left;
    A->left = B->right;
    B->right = A;
    updateHeight(A);
    updateHeight(B);
    return B;
}

Node* leftRotate(Node* A)
{
    Node* B = A->right;
    A->right = B->left;
    B->left = A;
    updateHeight(A);
    updateHeight(B);
    return B;
}

Node* minValueNode(Node* node)
{
    Node* cur = node;
    while (cur && cur->left)
    {
        cur = cur->left;
    }
    return cur;
}

string format_message(int nodeKey, int level, const string& rotation)
{
    ostringstream oss;
    oss << "Rebalance subtree rooted at node " << nodeKey << " on level " << level << " with " << rotation << " rotation. ";
    return oss.str();
}

string format_message_double(int nodeKey, int level, const string& rot1, const string& rot2)
{
    ostringstream oss;
    oss << "Rebalance subtree rooted at node " << nodeKey << " on level " << level << " with " << rot1 << " rotation and " << rot2 << " rotation. ";
    return oss.str();
}

Node* insert(Node* root, int key, int depth, vector<string>& rotations)
{
    if (root == nullptr)
    {
        return new Node(key);
    }
    if (key < root->key)
    {
        root->left = insert(root->left, key, depth + 1, rotations);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key, depth + 1, rotations);
    }
    else
    {
        return root;
    }
    updateHeight(root);
    int balance = getBalance(root);
    if (balance > 1)
    {
        if (getBalance(root->left) >= 0)
        {
            rotations.push_back(format_message(root->key, depth, "right"));
            return rightRotate(root);
        }
        else
        {
            rotations.push_back(format_message_double(root->key, depth, "left", "right"));
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    if (balance < -1)
    {
        if (getBalance(root->right) <= 0)
        {
            rotations.push_back(format_message(root->key, depth, "left"));
            return leftRotate(root);
        }
        else
        {
            rotations.push_back(format_message_double(root->key, depth, "right", "left"));
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    return root;
}

Node* remove(Node* root, int key, int depth, vector<string>& rotations)
{
    if (root == nullptr)
    {
        return root;
    }
    if (key < root->key)
    {
        root->left = remove(root->left, key, depth + 1, rotations);
    }
    else if (key > root->key)
    {
        root->right = remove(root->right, key, depth + 1, rotations);
    }
    else
    {
        if (root->left == nullptr || root->right == nullptr)
        {
            Node* temp = (root->left != nullptr) ? root->left : root->right;
            delete root;
            return temp;
        }
        else
        {
            // 两个子结点均存在，采用中序后继替换
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = remove(root->right, temp->key, depth + 1, rotations);
        }
    }
    if (root == nullptr)
    {
        return root;
    }
    updateHeight(root);
    int balance = getBalance(root);
    if (balance > 1)
    {
        if (getBalance(root->left) >= 0)
        {
            rotations.push_back(format_message(root->key, depth, "right"));
            return rightRotate(root);
        }
        else
        {
            rotations.push_back(format_message_double(root->key, depth, "left", "right"));
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    if (balance < -1)
    {
        if (getBalance(root->right) <= 0)
        {
            rotations.push_back(format_message(root->key, depth, "left"));
            return leftRotate(root);
        }
        else
        {
            rotations.push_back(format_message_double(root->key, depth, "right", "left"));
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    return root;
}

void inorder(Node* root, vector<int>& res)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left, res);
    res.push_back(root->key);
    inorder(root->right, res);
}

void preorder(Node* root, vector<int>& res)
{
    if (root == nullptr)
    {
        return;
    }
    res.push_back(root->key);
    preorder(root->left, res);
    preorder(root->right, res);
}

void freeTree(Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

int main()
{
    int T;
    int caseNo = 1;
    while (cin >> T)
    {
        Node* root = nullptr;
        vector<string> opRotationLines;
        for (int i = 0; i < T; i++)
        {
            string line;
            getline(cin, line);
            if (line.empty())
            {
                i--;
                continue;
            }
            istringstream iss(line);
            string opType;
            int key;
            iss >> opType >> key;
            vector<string> rotations;
            if (opType == "Insert")
            {
                root = insert(root, key, 0, rotations);
            }
            else if (opType == "Remove")
            {
                root = remove(root, key, 0, rotations);
            }
            if (!rotations.empty())
            {
                ostringstream oss;
                oss << opType << " " << key << ": ";
                for (size_t j = 0; j < rotations.size(); j++)
                {
                    oss << rotations[j];
                }
                opRotationLines.push_back(oss.str());
            }
        }

		if (caseNo > 1)
		{
			cout << endl;
		}

        cout << "Case " << caseNo++ << ":\n";
        if (!opRotationLines.empty())
        {
            for (size_t i = 0; i < opRotationLines.size(); i++)
            {
                cout << opRotationLines[i] << "\n";
            }
            cout << "\n";
        }

        vector<int> inRes;
        inorder(root, inRes);
        for (size_t i = 0; i < inRes.size(); i++)
        {
            cout << inRes[i] << " ";
        }
        cout << endl << endl;

        vector<int> preRes;
        preorder(root, preRes);
        for (size_t i = 0; i < preRes.size(); i++)
        {
            cout << preRes[i] << " ";
        }
        cout << endl;

        freeTree(root);
    }
    return 0;
}
