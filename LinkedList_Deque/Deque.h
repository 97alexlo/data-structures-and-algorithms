//  Deque template implementation
//  cmpt225
//  Created by Alexander Lo on 2020-06-03.

#pragma once
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

template <class T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node(T val) : data(val), next(nullptr), prev(nullptr) { ; };
    Node(T val, Node* nd) : data(val), next(nd) { ; };
};

template <class T>
class Deque{
public:
    Deque();
    // deep copy
    Deque(const Deque& dq);
    // overloaded deep copy
    ~Deque();
    Deque & operator=(const Deque& dq);
    void insertFront(T val);
    void insertBack(T val);
    T removeFront();
    T removeBack();
    T peekFront();
    T peekBack();
    bool empty();
    T size();
    void print();
private:
    int dequeSize;
    Node<T>* head;
    void copyDeque(const Deque& dq);
    void deleteDeque();
};

/*//////////////// public ////////////////*/

// print deque
template <class T>
void Deque<T>::print() {
    Node<T>* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// constructor
template <class T>
Deque<T>::Deque() {
    head = nullptr;
    dequeSize = 0;
}

// deep copy constructor
template <class T>
Deque<T>::Deque(const Deque& dq) {
    copyDeque(dq);
}

//destructor
template <class T>
Deque<T>::~Deque() {
    deleteDeque();
}

// overloaded = operator, makes a deep copy
template <class T>
Deque<T> & Deque<T>::operator=(const Deque& dq) {
    if(this != &dq) {
        deleteDeque();
        copyDeque(dq);
    }
    return* this;
}

// insert value in front
template <class T>
void Deque<T>::insertFront(T val) {
    Node<T>* newNode = new Node<T>(val);
    if(head == nullptr) {
        head = newNode;
        dequeSize = 1;
    }
    else {
        head->prev = newNode;
        newNode->next = head; // like back and forth
        head = newNode;
        dequeSize++;
    }
}

// insert value at the back
template <class T>
void Deque<T>::insertBack(T val) {
    Node<T>* newNode = new Node<T>(val);
    if(head == nullptr) {
        head = newNode;
        dequeSize = 1;
    }
    else {
        Node<T>* curr = head;
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->next = nullptr;
        newNode->prev = curr;
        dequeSize++;
    }
}

// remove front value
template <class T>
T Deque<T>::removeFront() {
    if (head == nullptr) {
        throw std::runtime_error("Deque is empty!");
    }
    else {
        Node<T>* curr = head;
        T result = head->data;
        head = head->next;
        delete curr;
        dequeSize--;
        return result;
    }
}

// remove last value
template <class T>
T Deque<T>::removeBack() {
    if (head == nullptr) {
        throw std::runtime_error("Deque is empty!");
    }
    else {
        Node<T>* curr = head;
        T result = head->data;
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        Node<T>* temp = curr->prev;
        temp->next = nullptr;
        delete curr;
        dequeSize--;
        return result;
    }
}

// returns front value without removing
template <class T>
T Deque<T>::peekFront() {
    if(head == nullptr) {
        throw std::runtime_error("Deque is empty!");
    }
    else {
        return head->data;
    }
}

// returns last value without removing
template <class T>
T Deque<T>::peekBack() {
    if(head == nullptr) {
        throw std::runtime_error("Deque is empty!");
    }
    else {
        Node<T>* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }
}

// return true if deque is empty, otherwise false
template <class T>
bool Deque<T>::empty() {
    if(dequeSize == 0) {
        return true;
    }
    return false;
}

// get size of deque
template <class T>
T Deque<T>::size() {
    return dequeSize;
}

/*//////////////// private ////////////////*/

//method called by destructor
template <class T>
void Deque<T>::deleteDeque() {
    Node<T>* temp = head;
    while(head != nullptr && head->next != nullptr) {
        head = head->next;
        delete temp;
        temp = head;
    }
    dequeSize = 0;
}

//method called by copy constructor and overload = operator
template <class T>
void Deque<T>::copyDeque(const Deque &dq) {
    head = nullptr;
    dequeSize = dq.dequeSize;
    Node<T>* original = dq.head;
    if(original != nullptr) {
        // copy head
        head = new Node<T>(original->data);
        head->prev = nullptr;
        original = original->next;
        Node<T>* copy = head;
        //copy rest of parameters
        //makes a copy of each node while walking through it
        while(original != nullptr) {
            Node<T>* newNode = new Node<T>(original->data);
            copy->next = newNode;
            newNode->prev = copy;
            copy = copy->next;
            original = original->next;
        }
    }
}
