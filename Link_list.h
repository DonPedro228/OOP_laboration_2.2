#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;

public:
    LinkedList();
    LinkedList(const LinkedList& other);
    ~LinkedList();

    void operator + (int value); 
    LinkedList& operator+=(int value);
    void operator - (int value); 

    LinkedList& operator=(const LinkedList& other); 
    bool operator==(const LinkedList& other) const; 
    bool operator!=(const LinkedList& other) const; 
    bool operator>(const LinkedList& other) const; 
    bool operator<(const LinkedList& other) const; 
    bool operator>=(const LinkedList& other) const; 
    bool operator<=(const LinkedList& other) const; 
    int operator[](int index) const; 

    void operator++();
    void operator--(); 

    void operator()(int start, int end) const;


    friend ostream& operator<<(ostream& os, const LinkedList& list); 
    friend istream& operator>>(istream& is, LinkedList& list); 
    operator string() const; 
};