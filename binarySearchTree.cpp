// Binary Search Tree implementation in C++

#include <iostream>
using namespace std;

class node 
{
  public:
  int key;
  node *left, *right;
};

// Create a node
node *createNode(int data) 
{
  node *temp = new node;
  temp->key = data;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(node *root) 
{
  if (root != NULL) 
  {
    // Traverse left
    inorder(root->left);

    // Traverse root
    cout << root->key << " -> ";

    // Traverse right
    inorder(root->right);
  }
}

// Insert a node
node *insert(node *node, int key) 
{
  // Return a new node if the tree is empty
  if (node == NULL) 
    return createNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) 
{
  struct node *cur = node;

  // Find the leftmost leaf
  while (cur && cur->left != NULL)
    cur = cur->left;

  return cur;
}

// Deleting a node
node *deleteNode(node *root, int key) 
{
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      node *temp = root->right;
      free(root);
      return temp;
    } 
    
    else if (root->right == NULL) {
      node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}


int main() 
{
  node *root = NULL;
  root = insert(root, 9);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 5);

  cout << "Inorder traversal: ";
  inorder(root);

  cout << "\nAfter deleting 7\n";
  root = deleteNode(root, 7);
  cout << "Inorder traversal: ";
  inorder(root);
}