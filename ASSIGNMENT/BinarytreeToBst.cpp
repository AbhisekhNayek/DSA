#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
private:
    TreeNode* root;

public:
    BinaryTree()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        if (root == nullptr)
        {
            root = new TreeNode(value);
            return;
        }
        insertHelper(root, value);
    }

    void convertToBST()
    {
        if (root == nullptr)
            return;

        vector<int> nodes;
        inOrderTraversal(root, nodes);
        sort(nodes.begin(), nodes.end());
        constructBST(nodes);
    }
    void printTree()
    {
        if (root == nullptr)
        {
            cout << "TREE IS EMPTY" << endl;
            return;
        }

        cout << "BINARY TREE PATTERN:" << endl;
        printTreeHelper(root, 0);
    }
    void printBST()
    {
        if (root == nullptr)
        {
            cout << "TREE IS EMPTY" << endl;
            return;
        }

        cout << "BINARY SEARCH TREE PATTERN:" << endl;
        printTreeHelper(root, 0);
    }

private:
    void insertHelper(TreeNode* node, int value)
    {
        if (node->left == nullptr)
        {
            node->left = new TreeNode(value);
            return;
        }

        if (node->right == nullptr)
        {
            node->right = new TreeNode(value);
            return;
        }

        if (isFull(node->left))
        {
            insertHelper(node->right, value);
        }
        else
        {
            insertHelper(node->left, value);
        }
    }

    bool isFull(TreeNode* node)
    {
        return (node->left != nullptr && node->right != nullptr);
    }

    void inOrderTraversal(TreeNode* node, vector<int>& nodes)
    {
        if (node == nullptr)
            return;

        inOrderTraversal(node->left, nodes);
        nodes.push_back(node->data);
        inOrderTraversal(node->right, nodes);
    }

    TreeNode* constructBST(const vector<int>& nodes)
    {
        root = constructBSTHelper(nodes, 0, nodes.size() - 1);
        return root;
    }

    TreeNode* constructBSTHelper(const vector<int>& nodes, int start, int end)
    {
        if (start > end)
            return nullptr;

        int mid = (start + end) / 2;
        TreeNode* newNode = new TreeNode(nodes[mid]);

        newNode->left = constructBSTHelper(nodes, start, mid - 1);
        newNode->right = constructBSTHelper(nodes, mid + 1, end);

        return newNode;
    }

    void printTreeHelper(TreeNode* node, int indent = 0)
    {
        if (node == nullptr)
            return;

        const int spacing = 4;

        printTreeHelper(node->right, indent + spacing);
        cout << string(indent, ' ') << node->data << endl;
        printTreeHelper(node->left, indent + spacing);
    }
};

int main()
{
    BinaryTree tree;

    cout << "ENTER ELEMENTS TO INSERT INTO THE BINARY TREE (enter -1 to finish):" << endl;

    int input;
    cout << "ENTER THE ELEMENTS OF TREE : ";
    while (true)
    {
        cin >> input;
        if (input == -1)
            break;
        tree.insert(input);
    }

    cout << endl;
    tree.printTree();

    tree.convertToBST();
    cout << endl;
    tree.printBST();

    return 0;
}
