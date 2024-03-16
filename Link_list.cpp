#include "Node.h"
#include "Link_list.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;


LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(const LinkedList& other) : head(nullptr) {
	Node* current = other.head;
	while (current != nullptr) {
		*this + current->data;
		current = current->next;
	}
}
LinkedList::~LinkedList() {
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}
void LinkedList::operator+(int value) {
	if (head == nullptr) {
		head = new Node{ value, nullptr };
	}
	else {
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = new Node{ value, nullptr };
	}
}

LinkedList& LinkedList::operator+=(int value) {
	head = new Node{ value, head };
	return *this;
}


void LinkedList::operator-(int value) {
	if (head == nullptr) {
		return;
	}

	if (head->data == value) {
		Node* temp = head;
		head = head->next;
		delete temp;
		return;
	}

	Node* current = head;
	while (current->next != nullptr) {
		if (current->next->data == value) {
			Node* temp = current->next;
			current->next = current->next->next;
			delete temp;
			return;
		}
		current = current->next;
	}
}

LinkedList& LinkedList::operator=(const  LinkedList& other) {
	if (this == &other)
		return *this;

	while (head) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	Node* current = other.head;
	while (current) {
		*this += current->data;
		current = current->next;
	}

	return *this;
}

bool LinkedList::operator==(const LinkedList& other) const {
	Node* current1 = head;
	Node* current2 = other.head;

	while (current1 != nullptr && current2 != nullptr) {
		if (current1->data != current2->data)
			return false;
		current1 = current1->next;
		current2 = current2->next;
	}


	return current1 == nullptr && current2 == nullptr;
}

bool LinkedList::operator!=(const LinkedList& other) const
{
	return !(*this == other);
}

bool LinkedList::operator>(const LinkedList& other) const {
	Node* current1 = head;
	Node* current2 = other.head;

	while (current1 != nullptr && current2 != nullptr) {
		if (current1->data > current2->data) {
			return true;
		}
		else if (current1->data < current2->data) {
			return false;
		}

		current1 = current1->next;
		current2 = current2->next;
	}

	
	if (current1 == nullptr && current2 == nullptr)
		return false; 
	else if (current1 == nullptr)
		return false; 
	else
		return true; 
}

bool LinkedList::operator<(const LinkedList& other) const {
	return !(*this > other) && !(*this == other);
}

bool LinkedList::operator>=(const LinkedList& other) const {
	return (*this > other) || (*this == other);
}

bool LinkedList::operator<=(const LinkedList& other) const {
	return (*this < other) || (*this == other);
}

int LinkedList::operator[](int index) const {
	int count = 0;
	Node* current = head;
	while (current != nullptr) {
		if (count == index)
			return current->data;
		++count;
		current = current->next;
	}
	throw out_of_range("Index out of range!");
}

void LinkedList::operator++() {
	if (head == nullptr) {
		throw runtime_error("Cannot increment empty list");
	}
	head = head->next;
}

void LinkedList::operator--() {
	throw runtime_error("Operation not supported");
}

void LinkedList::operator()(int start, int end) const {
	if (start < 0 || start > end) {
		throw out_of_range("Invalid range");
	}

	Node* current = head;
	for (int i = 0; i < start && current != nullptr; ++i) {
		current = current->next;
	}

	for (int i = start; i <= end && current != nullptr; ++i) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

ostream& operator<<(ostream& os, const LinkedList& list) {
	LinkedList::Node* current = list.head; 
	while (current != nullptr) {
		os << current->data << " ";
		current = current->next;
	}
	return os;
}
istream& operator>>(istream& is, LinkedList& list) {
	int value;
	is >> value;
	list + value;
	return is;
}

LinkedList::operator string() const {
	stringstream ss;
	Node* current = head;
	while (current != nullptr) {
		ss << current->data << " ";
		current = current->next;
	}
	return ss.str();
}