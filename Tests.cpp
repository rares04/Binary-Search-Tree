#include "Tests.h"
#include "Node.h"
#include "Tree.h"
#include <iostream>
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

    cout << "\nNumber of nodes: " << BT.countNodes(BT.root);
    cout << "\nNumber of edges: " << BT.countEdges(BT.root);
    cout << "\nHeight: " << BT.height(BT.root);

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
