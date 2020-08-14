//
//  RedBlackTree.h
//  cmpt225
//
//  Created by Alex Lo on 2020-07-22.
//  Copyright © 2020 Alex Lo. All rights reserved.
//

#pragma once
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <class K, class V>
class NodeT {
public:
    K key;
    V value;
    NodeT* left;
    NodeT* right;
    NodeT* parent;
    bool isBlack; // color of node
    NodeT(K key, V value) {
        this->key = key;
        this->value = value;
        isBlack = false;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
    // used in deep copy constructor to create a new node
    NodeT(K key, V value, NodeT* par, bool isBlack) {
        this->key = key;
        this->value = value;
        this->isBlack = isBlack;
        left = nullptr;
        right = nullptr;
        parent = par;
    }
};

template <class K, class V>
class RedBlackTree {
public:
    // default constructor
    RedBlackTree();
    // deep copy constructor
    RedBlackTree(const RedBlackTree &rbt);
    // overloaded = operator, makes a deep copy
    RedBlackTree & operator=(const RedBlackTree &rbt);
    //destructor
    ~RedBlackTree();
    // insert hey and value, return true is key exists
    // return false otherwise
    bool insert(const K key, const V value);
    // removes key and its value and returns true,
    // returns false otherwise
    bool remove(const K key);
    // searches for key and returns true if found
    // return false otherwise
    bool search(const K key);
    // searches for values whos keys are between value1 and value2
    // returns a vector of these values
    vector<V> search(K value1, K value2);
    // returns a vector of all values in tree in ascending order
    vector<V> values();
    // returns a vector of all keys in tree in ascending order
    vector<K> keys();
    // returns number of items in tree
    int size() const;
    // returns pointer to tree's root node
    NodeT<K, V>* getRoot() const;
    
    void print() const;
private:
    NodeT<K, V>* root;
    
    int treeSize;
    // destructor helper to delete all nodes and deallocate dynamic memory
    void clear(NodeT<K, V>* nd);
    // deep copy helper
    void copyTree(NodeT<K, V>* &copyTo, NodeT<K, V> *copyFrom, NodeT<K, V>* copyFromParent ) ;
    // BST insert helper
    NodeT<K, V>* insertBST(NodeT<K, V> *newNode);
    // insert helper to fix tree if rules are violated
    void insertFix(NodeT<K, V> *newNode);
    // rotation helpers
    void leftRotation(NodeT<K, V> *nd);
    void rightRotation(NodeT<K, V> *nd);
    // get successor
    NodeT<K, V>* predeccessor(NodeT<K, V> *nd);
    // helper to fix violations for remove
    void removeFix(NodeT<K, V>* x, NodeT<K, V>* xParent, bool isRight);
    // returns left most node of a given node
    NodeT<K, V>* leftMost(NodeT<K, V>* nd);
    // helper for search
    void inOrderBetween(NodeT<K, V>* nd, vector<V> &values, K key1, K key2);
    // helper that sort all values in ascending order
    void inOrderValues(NodeT<K, V>* nd, vector<V> &values);
    // helper that sort all keys in ascending order
    void inOrderKeys(NodeT<K, V>* nd, vector<K> &keys);
    
//    void inOrderPrint(NodeT<K, V>* nd) const;
};

/*//////////////////////////////// public ////////////////////////////////*/

// default constructor
template <class K, class V>
RedBlackTree<K, V>::RedBlackTree() {
    root = nullptr;
    treeSize = 0;
}

// copy constructor that calls copyTree helper
template <class K, class V>
RedBlackTree<K, V>::RedBlackTree(const RedBlackTree &rbt) {
    treeSize = 0;
    copyTree(root, rbt.root, nullptr);
    treeSize = rbt.treeSize;
}

// overloadded = operator that calls copyTree helper
// and de-allocates dynamic memory if not the same
template <class K, class V>
RedBlackTree<K, V> &RedBlackTree<K, V>::operator=(const RedBlackTree &rbt) {
    treeSize = 0;
    if(this != &rbt) {
        clear(root);
        copyTree(root, rbt.root, nullptr);
    }
    treeSize = rbt.treeSize;
    return *this;
}

// destructor that calls clear helper
template <class K, class V>
RedBlackTree<K, V>::~RedBlackTree() {
    clear(root);
    root = nullptr;
}

// looks for a node with a matching key and inserts if it is not found
// returns true inserted successfully, false otherwise
template <class K, class V>
bool RedBlackTree<K, V>::insert(const K key, const V value) {
    NodeT<K, V> *curr = root;
    NodeT<K, V> *newNode = new NodeT<K, V>(key, value);
    // check for duplicate key
    while (curr != nullptr) {
        if (key == curr->key) {
            return false;
        }
        else if (key < curr->key) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
    // insert with BST method and fix if RBT rules are violated
    insertFix(insertBST(newNode));
    return true;
}

// searches for node with matching key and returns true if found
// returns false otherwise
template <class K, class V>
bool RedBlackTree<K, V>::search(const K key) {
    NodeT<K, V>* curr = root;
    while(curr != nullptr && key != curr->key) {
        if(key < curr->key) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
    if(curr == nullptr) {
        return false;
    }
    return true;
}

// searches for values whos keys are between value1 and value2
// returns a vector of these values
template <class K, class V>
vector<V> RedBlackTree<K, V>::search(K value1, K value2) {
    NodeT<K, V>* curr = root;
    if(value1 > value2) {
        K temp = value1;
        value1 = value2;
        value2 = temp;
    }
    vector<V> values;
    inOrderBetween(curr, values, value1, value2);
    return values;
}

// returns a vector with all values in ascending order
template <class K, class V>
vector<V> RedBlackTree<K, V>::values() {
    vector<V> values;
    NodeT<K, V>* curr = root;
    inOrderValues(curr, values);
    return values;
}

// returns a vector with all keys in ascending order
template <class K, class V>
vector<K> RedBlackTree<K, V>::keys() {
    vector<K> keys;
    NodeT<K, V>* curr = root;
    inOrderKeys(curr, keys);
    return keys;
}

// returns size of tree
template <class K, class V>
int RedBlackTree<K, V>::size() const {
    return treeSize;
}

// returns a pointer to the root of tree
template <class K, class V>
NodeT<K, V>* RedBlackTree<K, V>::getRoot() const {
    return root;
}

// finds and removes the node with the matching key
// returns true if removed, false otherwise
template <class K, class V>
bool RedBlackTree<K, V>::remove(const K key) {
    NodeT<K, V>* curr = root;
    bool isRight = true;
    NodeT<K, V>* nodeRemove = nullptr;
    NodeT<K, V>* y = nullptr;
    NodeT<K, V>* x = nullptr; // child
    // find node with matching key to be removed
    while(curr != nullptr) {
        if(curr->key == key) {
            nodeRemove = curr;
            break;
        }
        else if(key > curr->key) {
            curr = curr->right;
        }
        else {
            curr = curr->left;
        }
    }
    if(nodeRemove == nullptr) {
        return false;
    }
    if(nodeRemove->left == nullptr || nodeRemove->right == nullptr) {
        y = nodeRemove;
    }
    else {
        y = predeccessor(nodeRemove);
    }
    if(y->left != nullptr) {
        x = y->left;
    }
    else {
        x = y->right;
    }
    if(x != nullptr) {
        x->parent = y->parent;
    }
    if(y->parent == nullptr) {
        root = x;
    }
    else {
        if(y == y->parent->left) {
            y->parent->left = x;
            isRight = false;
        }
        else {
            y->parent->right = x;
            isRight = true;
        }
    }
    if(y != nodeRemove) {
        nodeRemove->key = y->key;
        nodeRemove->value = y->value;
    }
    if(y->isBlack == true) {
        if(x == nullptr) {
            removeFix(nullptr, y->parent, isRight);
        }
        else {
            removeFix(x, y->parent, isRight);
        }
    }
    delete y;
    treeSize--;
    return true;
}

// print test DELETE
//template <class K, class V>
//void RedBlackTree<K, V>::print() const
//{
//    inOrderPrint(root);
//}

/*/////////////////////////////// private ///////////////////////////////*/

// deep copy helper
template <class K, class V>
void RedBlackTree<K, V>::copyTree(NodeT<K, V>* &copyTo, NodeT<K, V> *copyFrom, NodeT<K, V>* copyFromParent) {
    if(copyFrom == nullptr) {
        copyTo = nullptr;
    }
    else {
        K key = copyFrom->key;
        V value = copyFrom->value;
        bool color = copyFrom->isBlack;
        copyTo = new NodeT<K, V>(key, value, copyFromParent, color);
        copyTree(copyTo->left, copyFrom->left, copyTo);
        copyTree(copyTo->right, copyFrom->right, copyTo);
        treeSize++;
    }
}

// helper to fix violations for remove
template <class K, class V>
void RedBlackTree<K, V>::removeFix(NodeT<K, V> *x, NodeT<K, V> *xParent, bool isRight) {
    NodeT<K, V> *s; //sibling
    bool sRightBlack = true;
    bool sleftBlack = true;
    bool xIsBlack = true;
    if(x == nullptr) {
        xIsBlack = true;
    }
    else {
        xIsBlack = x->isBlack;
    }
    while (x != root && xIsBlack == true) {
        if(x != nullptr) {
            // find if x is a left or right child
            if(x == xParent->left)
            {
                isRight = false;
            }
            else
            {
                isRight = true;
            }
        }
        if (isRight == false) { // x is left child
            s = xParent->right;
            if (s->isBlack == false) {
                s->isBlack = true;
                xParent->isBlack = false;
                leftRotation(xParent);
                s = xParent->right;
            }
            // assign siblings left and right children's colors to black
            // if not alerady
            if(s->right == nullptr) {
                sRightBlack = true;
            }
            else {
                sRightBlack = s->right->isBlack;
            }
            if(s->left == nullptr) {
                sleftBlack = true;
            }
            else {
                sleftBlack = s->left->isBlack;
            }
            if (sleftBlack && sRightBlack) {
                s->isBlack = false;
                x = xParent;
                xIsBlack = x->isBlack;
                xParent = xParent->parent; // push up the tree
            }
            else { // not all siblings are black
                if (sRightBlack == true) {
                    s->left->isBlack = true;
                    s->isBlack = false;
                    rightRotation(s);
                    s = xParent->right;
                }
                s->isBlack = xParent->isBlack;
                xParent->isBlack = true;
                s->right->isBlack = true;
                leftRotation(xParent);
                x = root;
            }
        }
        else { // isRight is true (x is the right child)
            s = xParent->left;
            if (s->isBlack == false) {
                s->isBlack = true;
                xParent->isBlack = false;
                rightRotation(xParent);
                s = xParent->left;
            }
            // assign siblings left and right children's colors to black
            // if not already
            if(s->right == nullptr) {
                sRightBlack = true;
            }
            else {
                sRightBlack = s->right->isBlack;
            }
            if(s->left == nullptr) {
                sleftBlack = true;
            }
            else {
                sleftBlack = s->left->isBlack;
            }
            if (sleftBlack && sRightBlack) {
                s->isBlack = false;
                x = xParent;
                xIsBlack = x->isBlack;
                xParent = xParent->parent;
            }
            else { // not all siblings are black
                if (sleftBlack == true) {
                    s->right->isBlack = true;
                    s->isBlack = false;
                    leftRotation(s);
                    s = xParent->left;
                }
                s->isBlack = xParent->isBlack;
                xParent->isBlack = true;
                s->left->isBlack = true;
                rightRotation(xParent);
                x = root;
            }        }
    }
    if(x != nullptr) {
        x->isBlack = true;
    }
}

// BST insert helper
template <class K, class V>
NodeT<K, V>* RedBlackTree<K, V>::insertBST(NodeT<K, V>* newNode) {
    NodeT<K, V>* parent = root;
    NodeT<K, V>* next = root;
    if (root == nullptr) {
        root = newNode;
        root->isBlack = true;
    }
    else { //non-empty
           // Find parent of new node
        while (next != nullptr) {
            parent = next;
            if (newNode->key < parent->key) {
                next = parent->left;
            }
            else {
                next = parent->right;
            }
        }
        // Insert new node
        if (newNode->key < parent->key) {
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }
    }
    newNode->parent = parent;
    treeSize++;
    return newNode;
}

// helper to fix tree after insertion
template <class K, class V>
void RedBlackTree<K, V>::insertFix(NodeT<K, V> *newNode) {
    while (newNode != root && newNode->parent->isBlack == false) {
        if (newNode->parent == newNode->parent->parent->right) {
            NodeT<K, V> *y = newNode->parent->parent->left; // uncle
            if(y != nullptr) { // uncle is not a leaf
                if (y->isBlack == false) { // uncle is red
                    y->isBlack = true;
                    newNode->parent->isBlack = true;
                    newNode->parent->parent->isBlack = false;
                    newNode = newNode->parent->parent;
                }
                else { // uncle is black
                    if (newNode == newNode->parent->left) {
                        newNode = newNode->parent;
                        rightRotation(newNode);
                    }
                    newNode->parent->isBlack = true;
                    newNode->parent->parent->isBlack = false;
                    leftRotation(newNode->parent->parent);
                }
            }
            else { // uncle is a leaf
                if (newNode == newNode->parent->left) {
                    newNode = newNode->parent;
                    rightRotation(newNode);
                }
                newNode->parent->isBlack = true;
                newNode->parent->parent->isBlack = false;
                leftRotation(newNode->parent->parent);
            }
        }
        else { // symmetric to if
            NodeT<K, V> *y = newNode->parent->parent->right; // uncle
            if(y != nullptr) {
                if (y->isBlack == false) {
                    y->isBlack = true;
                    newNode->parent->isBlack = true;
                    newNode->parent->parent->isBlack = false;
                    newNode = newNode->parent->parent;
                }
                else {
                    if (newNode == newNode->parent->right) {
                        newNode = newNode->parent;
                        leftRotation(newNode);
                    }
                    newNode->parent->isBlack = true;
                    newNode->parent->parent->isBlack = false;
                    rightRotation(newNode->parent->parent);
                }
            }
            else {
                if (newNode == newNode->parent->right) {
                    newNode = newNode->parent;
                    leftRotation(newNode);
                }
                newNode->parent->isBlack = true;
                newNode->parent->parent->isBlack = false;
                rightRotation(newNode->parent->parent);
            }
        }
    }
    root->isBlack = true;
}

// returns the successor (even if it is nullptr)
template <class K, class V>
NodeT<K, V>* RedBlackTree<K, V>::predeccessor(NodeT<K, V> *nd) {
    NodeT<K, V>* temp = nd->left;
    if(temp == nullptr) {
        return nullptr;
    }
    else {
        while(temp->right != nullptr) {
            temp = temp->right;
        }
        return temp;
    }
}

// left rotaton helper
template <class K, class V>
void RedBlackTree<K, V>::leftRotation(NodeT<K, V> *x) {
    NodeT<K, V> *y = x->right;
    x->right = y->left;
    if (y->left != nullptr) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    }
    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

// right rotation helper
template <class K, class V>
void RedBlackTree<K, V>::rightRotation(NodeT<K, V> *x) {
    NodeT<K, V> *y = x->left;
    x->left = y->right;
    if (y->right != nullptr) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    }
    else if (x == x->parent->right) {
        x->parent->right = y;
    }
    else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

// destructor helper
template <class K, class V>
void RedBlackTree<K, V>::clear(NodeT<K, V> *nd) {
    if(nd != nullptr) {
        clear(nd->left);
        clear(nd->right);
        delete nd;
    }
}

// finds values between v1 and v2 in ascending key order
template <class K, class V>
void RedBlackTree<K, V>::inOrderBetween(NodeT<K, V>* nd, vector<V> &values, K key1, K key2) {
    if(nd != nullptr) {
        inOrderBetween(nd->left, values, key1, key2);
        if(nd->key >= key1 && nd->key <= key2) {
            values.push_back(nd->value);
        }
        inOrderBetween(nd->right, values, key1, key2);
    }
}

// helper to sort all values in ascending key order
template <class K, class V>
void RedBlackTree<K, V>::inOrderValues(NodeT<K, V> *nd, vector<V> &values) {
    if(nd != nullptr) {
        inOrderValues(nd->left, values);
        values.push_back(nd->value);
        inOrderValues(nd->right, values);
    }
}

// helper to sort all values in ascending key order
template <class K, class V>
void RedBlackTree<K, V>::inOrderKeys(NodeT<K, V> *nd, vector<K> &keys) {
    if(nd != nullptr) {
        inOrderKeys(nd->left, keys);
        keys.push_back(nd->key);
        inOrderKeys(nd->right, keys);
    }
}

// print test DELETE
template <class K, class V>
void RedBlackTree<K, V>::inOrderPrint(NodeT<K, V>* nd) const
{
    if (nd != nullptr) {
        inOrderPrint(nd->left);
        cout << nd->key << " " << nd->isBlack << " ";
        if(nd->parent != nullptr) {
            cout << nd->parent->key <<endl;
        }
        else {cout << endl;}
        inOrderPrint(nd->right);
    }
}
