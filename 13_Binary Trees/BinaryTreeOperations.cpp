#include <iostream>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};

// Insert a node in BST
TreeNode *insert(TreeNode *root, int val)
{
    if (!root)
        return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Search for a node in BST
bool search(TreeNode *root, int val)
{
    if (!root)
        return false;
    if (root->val == val)
        return true;
    return (val < root->val) ? search(root->left, val) : search(root->right, val);
}

// Find minimum value node in BST (Used in delete operation)
TreeNode *minValueNode(TreeNode *node)
{
    TreeNode *current = node;
    while (current && current->left)
    {
        current = current->left;
    }
    return current;
}

// Delete a node in BST
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return root;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else
    {
        if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;

        TreeNode *temp = minValueNode(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

// Inorder Traversal (Left -> Root -> Right)
void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Preorder Traversal (Root -> Left -> Right)
void preorder(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (Left -> Right -> Root)
void postorder(TreeNode *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Level Order Traversal (BFS)
void levelOrder(TreeNode *root)
{
    if (!root)
        return;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        cout << node->val << " ";

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
}

// Height of the tree
int height(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Size of the tree (Total number of nodes)
int size(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

// Main function
int main()
{
    TreeNode *root = NULL;

    // Insert nodes into BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    cout << "Level Order Traversal: ";
    levelOrder(root);
    cout << endl;

    cout << "Height of Tree: " << height(root) << endl;
    cout << "Size of Tree: " << size(root) << endl;

    // Search for a value in BST
    int searchVal = 40;
    cout << "Search " << searchVal << ": " << (search(root, searchVal) ? "Found" : "Not Found") << endl;

    // Delete a node
    int deleteVal = 30;
    cout << "Deleting " << deleteVal << "...\n";
    root = deleteNode(root, deleteVal);

    cout << "Inorder Traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
