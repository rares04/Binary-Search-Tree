#include "Node.h"

Node::Node()
{
    this->value = 0;
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(int val)
{
    this->value = val;
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(const Node& copy_node)
{
    this->value = copy_node.value;
    this->left = copy_node.left;
    this->right = copy_node.right;
}

Node::~Node()
{
    delete left;
    delete right;
}