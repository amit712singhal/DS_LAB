// Implement Insertion, Deletion and Display (Inorder, Preorder and Postorder) on Binary Search Tree

#include <iostream>

using namespace std;

// Node structure for the BST
struct Node
{
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a value into the BST
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
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to find the minimum value node in a BST
Node *findMin(Node *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

// Function to delete a value from the BST
Node *deleteNode(Node *root, int value)
{
    if (root == nullptr)
    {
        return root;
    }

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        // Node with only one child or no child
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node *temp = findMin(root->right);

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to perform inorder traversal of the BST
void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Function to perform preorder traversal of the BST
void preorder(Node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to perform postorder traversal of the BST
void postorder(Node *root)
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    Node *root = nullptr;

    // Insertion
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << endl
         << "Inorder traversal: ";
    inorder(root);

    cout << endl
         << "Preorder traversal: ";
    preorder(root);

    cout << endl
         << "Postorder traversal: ";
    postorder(root);

    // Deletion
    root = deleteNode(root, 20);
    root = deleteNode(root, 30);

    cout << endl
         << "Inorder traversal (after deletion): ";
    inorder(root);
    cout << endl
         << "Preorder traversal (after deletion): ";
    preorder(root);

    cout << endl
         << "Postorder traversal (after deletion): ";
    postorder(root);

    return 0;
}
