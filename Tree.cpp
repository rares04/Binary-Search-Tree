#include <iostream>
#include "Node.h"
#include "Tree.h"

using namespace std;

Tree::Tree() {
    root = NULL;
}

Tree::Tree(int value) {
    root = new Node(value);
}

Tree::~Tree() {
    delete root;
}

Node* Tree::insert(int v, Node* tree) {
    // If the tree is empty the function will create a new node single node, the root node
    if (tree == NULL) {  
        tree = new Node;
        tree->value = v;
        tree->left = tree->right = NULL;
    }
    else // Else recurrently searching for the right position where to add the new node
        if (v < tree->value)  // If the value of the new node is lower than the current node, search on the left side
            tree->left = insert(v, tree->left);
        else
            if (v > tree->value)  // If the value of the new node is higher than the current node, search on the right side
                tree->right = insert(v, tree->right);

    return tree;
}

Node* Tree::find_min(Node* tree) const {
    // If the tree is empty, there's no minimum
    if (tree == NULL)
        return NULL;
    else 
        if (tree->left == NULL) // If the left pointer of the current is NULL, it means this is the node with the lowest value
            return tree;
        else
            return find_min(tree->left);  // Else search for the minimum recurrently
}

Node* Tree::find_max(Node* tree) const {
    // If the tree is empty, there's no maximum
    if (tree == NULL)
        return NULL;
    else
        if (tree->right == NULL)  // If the right pointer of the current is NULL, it means this is the node with the highest value
            return tree;
        else
            return find_max(tree->right);  // Else search for the maximum recurrently
}


Node* Tree::del(int v, Node* tree) {
    Node* to_delete;

    // If the tree is empty or this is the last node on this side of the tree
    if (tree == NULL)
        return NULL;
    else // Else search for the node with value v recurently
        if (v < tree->value)
            tree->left = del(v, tree->left);
        else 
            if (v > tree->value)
                tree->right = del(v, tree->right);
            else 
                // If the executions reaches this points it means the node to be deleted was found and now are 2 possible cases:
                // 1. The node is on the bottom of the tree, so no replacements needed after the node will be deleted
                // 2. The node is not on the bootom of the tree, so the subtree built by the subnodes of the current node need to be places higher
                if (tree->left && tree->right) { // This is case 2
                        to_delete = find_min(tree->right);
                        tree->value = to_delete->value;
                        tree->right = del(tree->value, tree->right);
                }
                else {  // This is case 1
                    to_delete = tree;
                    if (tree->left == NULL)
                        tree = tree->right;
                    else 
                        if (tree->right == NULL)
                            tree = tree->left;
                    delete to_delete;
                }

    return tree;
}

int Tree::countNodes(Node* tree)
{
    int count = 1;

    if (tree->left != NULL)
        count += countNodes(tree->left);

    if (tree->left != NULL)
        count += countNodes(tree->right);

    return count;
}

int Tree::countEdges(Node* tree)
{
    return countNodes(tree) - 1;
}

int Tree::height(Node* tree)
{
    return (countNodes(tree) - 1)/2;
}

