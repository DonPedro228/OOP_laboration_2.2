#pragma once
#include <iostream>
#include <stdexcept>

class Node {
public:
	int data;
	Node* next;

	Node(int value) : data(value), next(nullptr) {}

	~Node() {
		delete next;
	}
};
