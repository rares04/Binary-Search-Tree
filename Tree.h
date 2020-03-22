#pragma once
#include "Node.h"

class Node;

// This is a binary tree
class Tree {
public:
    // Root node of the Tree 
    Node* root;

    // Giving acces to the class members of Node
    friend class Node;

public:

    // Default Constructor
    Tree();

    // Constructor to initalize the root node of the tree
    Tree(int data);

    // Destructor of the Tree class
    ~Tree();

    // Inserts a node into the binary tree
    Node* insert(int v, Node* tree);

    // Delete a node from the bnary tree
    Node* del(int v, Node* tree);

    // Finds the node with the minimal value
    Node* find_min(Node* tree) const;

    // Finds the node with the maximal value
    Node* find_max(Node* tree) const;

    // Returns the number of Nodes
    int countNodes(Node* tree);

    // Returns the number of Edges
    int countEdges(Node* tree);

    // Returns the height of the Binary Tree
    int height(Node* tree);


};