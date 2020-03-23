#include "Tests.h"
#include "Node.h"
#include "Tree.h"
#include <iostream>
#include <cassert>

void TestCount()
{
    std::cout << "Testing count functions\n";

    Tree BT;
    BT.root = new Node(1);

    BT.root->left = new Node(2);
    BT.root->right = new Node(3);
    BT.root->left->left = new Node(4);
    BT.root->left->right = new Node(5);
    BT.root->right->left = new Node(6);
    BT.root->right->right = new Node(7);
    BT.root->left->left->left = new Node(8);
    BT.root->left->left->right = new Node(9);

    assert(BT.countNodes(BT.root) == 9);
    assert(BT.countEdges(BT.root) == 8);
    assert(BT.height(BT.root) == 4);

}

void TestInsert()
{
    std::cout << "\nTesting insert and delete functions\n";

    Tree BT;
    Node* root = new Node(1);
    BT.root = root;

    BT.insert(4, root);
    BT.insert(2, root);
    BT.insert(3, root);
    BT.insert(6, root);
    BT.insert(5, root);
    BT.del(5, root);
    BT.del(4, root);

    assert(BT.countNodes(BT.root) == 4);
    assert(BT.countEdges(BT.root) == 3);
    assert(BT.height(BT.root) == 4);

}

void TestOrder()
{
    Tree BT;
    BT.root = new Node(1);

    BT.root->left = new Node(2);
    BT.root->right = new Node(3);
    BT.root->left->left = new Node(4);
    BT.root->left->right = new Node(5);

    std::cout << "\nPreorder traversal of binary tree is \n";
    BT.ShowPreorder(BT.root);

    std::cout << "\nInorder traversal of binary tree is \n";
    BT.ShowInorder(BT.root);

    std::cout << "\nPostorder traversal of binary tree is \n";
    BT.ShowPostorder(BT.root);
}