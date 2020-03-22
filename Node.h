#pragma once
#include <iostream>

class Node {
public:
	int value;
	Node* left;
	Node* right;
public:
	// Default Constructor
	Node();

	// Constructor with 1 parameter
	Node(int data);

	// Destructor of the Node class
	~Node();

	// Copy Costructor
	Node(const Node& other);
};