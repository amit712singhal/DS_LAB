// Create  a  Binary Tree using  linked list  (Display using Graphics)   and  perform the following operations:
// Tree traversals (Preorder,  Postorder, Inorder) using the concept of  recursion

#include <iostream>

using namespace std;

// Node structure for the binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the binary tree
Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform Preorder traversal
void preorderTraversal(Node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform Inorder traversal
void inorderTraversal(Node *root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Function to perform Postorder traversal
void postorderTraversal(Node *root)
{
    if (root != nullptr)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    Node *root = nullptr;

    // Inserting nodes into the binary tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << endl
         << "Preorder Traversal: ";
    preorderTraversal(root);

    cout << endl
         << "Inorder Traversal: ";
    inorderTraversal(root);

    cout << endl
         << "Postorder Traversal: ";
    postorderTraversal(root);

    return 0;
}
