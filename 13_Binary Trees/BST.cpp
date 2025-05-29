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

// Find minimum value node in BST
TreeNode *findMin(TreeNode *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

// Find maximum value node in BST
TreeNode *findMax(TreeNode *root)
{
    while (root && root->right)
        root = root->right;
    return root;
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

        TreeNode *temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

// Find Inorder Predecessor and Successor
void findPreSuc(TreeNode *root, TreeNode *&pre, TreeNode *&suc, int key)
{
    if (!root)
        return;

    if (root->val == key)
    {
        if (root->left)
        {
            TreeNode *temp = root->left;
            while (temp->right)
                temp = temp->right;
            pre = temp;
        }
        if (root->right)
        {
            TreeNode *temp = root->right;
            while (temp->left)
                temp = temp->left;
            suc = temp;
        }
        return;
    }

    if (root->val > key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

// Find Lowest Common Ancestor (LCA)
TreeNode *findLCA(TreeNode *root, int n1, int n2)
{
    if (!root)
        return NULL;
    if (root->val > n1 && root->val > n2)
        return findLCA(root->left, n1, n2);
    if (root->val < n1 && root->val < n2)
        return findLCA(root->right, n1, n2);
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

// Height of the BST
int height(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Size of the BST (Total number of nodes)
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

    cout << "Height of BST: " << height(root) << endl;
    cout << "Size of BST: " << size(root) << endl;

    // Find Min & Max
    cout << "Minimum value in BST: " << findMin(root)->val << endl;
    cout << "Maximum value in BST: " << findMax(root)->val << endl;

    // Search for a value
    int searchVal = 40;
    cout << "Search " << searchVal << ": " << (search(root, searchVal) ? "Found" : "Not Found") << endl;

    // Find Inorder Predecessor & Successor
    TreeNode *pre = NULL, *suc = NULL;
    findPreSuc(root, pre, suc, searchVal);
    cout << "Predecessor of " << searchVal << ": " << (pre ? to_string(pre->val) : "None") << endl;
    cout << "Successor of " << searchVal << ": " << (suc ? to_string(suc->val) : "None") << endl;

    // Find LCA of two nodes
    int n1 = 20, n2 = 40;
    TreeNode *lca = findLCA(root, n1, n2);
    cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << ": " << (lca ? lca->val : -1) << endl;

    // Delete a node
    int deleteVal = 30;
    cout << "Deleting " << deleteVal << "...\n";
    root = deleteNode(root, deleteVal);

    cout << "Inorder Traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
