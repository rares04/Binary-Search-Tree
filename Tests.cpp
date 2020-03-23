#include "Tests.h"
#include "Node.h"
#include "Tree.h"
#include <iostream>
#include <cassert>
using namespace std;

void TestCount()
{
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

    cout << "\nNumber of nodes: " << BT.countNodes(BT.root);
    cout << "\nNumber of edges: " << BT.countEdges(BT.root);
    cout << "\nHeight: " << BT.height(BT.root);

    cout << "\nTest insert and delete";
}

void TestOrder()
{
    Tree BT;
    BT.root = new Node(1);

    BT.root->left = new Node(2);
    BT.root->right = new Node(3);
    BT.root->left->left = new Node(4);
    BT.root->left->right = new Node(5);

    cout << "\nPreorder traversal of binary tree is \n";
    BT.ShowPreorder(BT.root);

    cout << "\nInorder traversal of binary tree is \n";
    BT.ShowInorder(BT.root);

    cout << "\nPostorder traversal of binary tree is \n";
    BT.ShowPostorder(BT.root);
}