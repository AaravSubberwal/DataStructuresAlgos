#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    int key;
    node *left;
    node *right;
    node *parent;
    node()
    {
        parent = nullptr;
    }
    node(int data)
    {
        key = data;
    }
};
class BST // A binary search tree has this property where the left leaf node is always smaller and right leaf node is always greater than the root node
{
public:
    node *root;
    BST(int val)
    {
        root = new node(val);
    }
    BST(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            insert(arr[i]);
        }
    }
    bool iterative_search(int target) // faster
    {
        node *temp = root;
        while (temp != nullptr)
        {
            if (temp->key == target)
            {
                return true;
            }
            if (target < temp->key)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return false;
    }
    int height()
    {
        return findheight(root);
    }
    void insert(int val)
    {
        if (root == nullptr)
        {
            root = new node(val);
            return;
        }
        node *insertme = new node(val);
        node *current = root;
        node *parent = nullptr;
        while (current != nullptr)
        {
            parent = current;
            if (current->key < val)
            {
                current = current->right;
            }
            else if (current->key > val)
            {
                current = current->left;
            }
            else
            {
                delete insertme;
                return;
            }
        }
        if (val < parent->key)
        {
            parent->left = insertme;
        }
        else
        {
            parent->right = insertme;
        }
    }
    void deleteit(int target)
    {
        node *current = root;
        node *parent = nullptr;
        while (current != nullptr && current->key != target)
        {
            parent = current;
            if (current->key < target)
            {
                current = current->right;
            }
            else
            {
                current = current->left;
            }
        }
        if (!current)
            return;

        if (!current->left && !current->right)
        { // no children
            if (!parent)
            {
                delete current;
                root = nullptr;
                return;
            }
            if (parent->left == current)
            {
                parent->left = nullptr;
            }
            else
            {
                parent->right = nullptr;
            }
            delete current;
            return;
        }
        else if (!current->left || !current->right) // one child
        {
            node *child = (current->left == nullptr) ? current->right : current->left;
            if (!parent)
            {
                delete current;
                root = nullptr;
                return;
            }
            if (parent->left == current)
            {
                parent->left = child;
            }
            else
            {
                parent->right = child;
            }
            delete current;
            return;
        }
        else // 2 childs
        {    // find succ
            node *successor = current->right;
            node *successorkaparent = current;
            while (successor->left != nullptr)
            {
                successorkaparent = successor;
                successor = successor->left;
            }
            current->key = successor->key;

            // Delete the successor node
            if (successorkaparent->left == successor)
            {
                successorkaparent->left = successor->right; // Successor can only have a right child
            }
            else
            {
                successorkaparent->right = successor->right;
            }
            delete successor;
        }
    }
    bool recursive_search(int target)
    {
        return recursive_search_wrap(target, root);
    }
    void inorderTraversal()
    {
        inorderTraversalwrap(root); // Call the wrapper with the root node.
    }
    void preorderTraversal()
    {
        preorderTraversalwrap(root); // Call the wrapper with the root node.
    }
    void postorderTraversal()
    {
        postorderTraversalwrap(root); // Call the wrapper with the root node.
    }
    
private:
    void inorderTraversalwrap(node *iter)
    {
        if (iter == nullptr)
        { // Base case: If iter is null, return.
            return;
        }
        inorderTraversalwrap(iter->left);  // Traverse the left subtree.
        cout << iter->key << " ";          // Visit the current node.
        inorderTraversalwrap(iter->right); // Traverse the right subtree.
    }
    void preorderTraversalwrap(node *iter)
    {
        if (iter == nullptr)
        { // Base case: If iter is null, return.
            return;
        }
        cout << iter->key << " ";          // Visit the current node.
        preorderTraversalwrap(iter->left);  // Traverse the left subtree.
        preorderTraversalwrap(iter->right); // Traverse the right subtree.
    }
    void postorderTraversalwrap(node *iter)
    {
        if (iter == nullptr)
        { // Base case: If iter is null, return.
            return;
        }
        postorderTraversalwrap(iter->left);  // Traverse the left subtree.
        postorderTraversalwrap(iter->right); // Traverse the right subtree.
        cout << iter->key << " ";          // Visit the current node.
    }
    bool recursive_search_wrap(int target, node *n) // *********
    {
        if (n == nullptr)
        {
            return false;
        }
        if (n->key == target)
        {
            return true;
        }
        if (target < n->key)
        {
            return recursive_search_wrap(target, n->left);
        }
        else
        {
            return recursive_search_wrap(target, n->right);
        }
    }
    int findheight(node *n)
    {
        if (root = nullptr)
        {
            return -1;
        }
        int left = findheight(n->left);
        int right = findheight(n->right);
        return 1 + max(left, right);
    }
};