#include "LinkedList.h"

// To be completed for exercise 4
// Recursive helper method for remove(int)
// ONLY CHANGE BODY OF THIS METHOD
void LinkedList::remove(Node* nd, int val)
{
    // if the head is null
    if(nd == nullptr) {
        return;
    }
    else {
        Node* curr = nd;
        Node* next = nd->next;
        if(curr->data == val && curr == head) {
            head = curr->next;
            delete curr;
            remove(curr->next, val);
        }
        else if(next != nullptr && next->data == val) {
            curr->next = next->next;
            remove(curr, val);
        }
        else {
            remove(curr->next, val);
        }
    }
}

void LinkedList::print() {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// Constructors and destructor
// Creates an empty list
LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::~LinkedList()
{
	deleteList();
}
// Copy constructor and overloaded assignment operator not implemented

// Mutators------------------
// PARAM: val = value to be inserted
// POST: inserts val at the front of the list
void LinkedList::insert(int val)
{
	Node* newNode = new Node(val, head);
	head = newNode;
}

// PARAM: val = value to be removed from list
// POST: removes all incidences of val from list,
// Calls remove(Node*, int)
void LinkedList::remove(int val)
{
	remove(head, val);
}

// Helper method for destructor
// (and un-implemented overloaded assignment operator)
void LinkedList::deleteList()
{
	Node* temp = head;
	while (head != nullptr) {
		head = head->next;
		delete temp;
		temp = head;
	}
}

// Accessors
bool LinkedList::check(const vector<int> & v)
{
	Node* p = head;
	for (int x : v) {
		if (p == nullptr || p->data != x) {
			return false;
		}
		p = p->next;
	}
	return (p == nullptr); // p != nullptr list contains unchecked values
}
