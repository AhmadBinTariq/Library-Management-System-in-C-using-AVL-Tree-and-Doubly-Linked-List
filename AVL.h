/*
Ahmad Bin Tariq
23L-2510
BDS_3C
*/
#include <iostream>
#include <utility>
#include <algorithm>
#include "AVL_Node.h"
#pragma once
using namespace std;



template <typename Key, typename Value>
class AVL {
    AVL_Node<pair<Key, Value>>* root;

    int getHeight(AVL_Node<pair<Key, Value>>* node) {
        if (node == nullptr) return -1;
        return node->height;
    }

    void updateHeight(AVL_Node<pair<Key, Value>>* node) {
        if (node == nullptr) return;
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }

    AVL_Node<pair<Key, Value>>* rotateRight(AVL_Node<pair<Key, Value>>* node) {
        AVL_Node<pair<Key, Value>>* temp = node->left;
        node->left = temp->right;
        temp->right = node;
        updateHeight(node);
        updateHeight(temp);
        return temp;
    }

    AVL_Node<pair<Key, Value>>* rotateLeft(AVL_Node<pair<Key, Value>>* node) {
        AVL_Node<pair<Key, Value>>* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        updateHeight(node);
        updateHeight(temp);
        return temp;
    }

    int getBalance(AVL_Node<pair<Key, Value>>* node) {
        if (node == nullptr) return -1;
        return getHeight(node->left) - getHeight(node->right);
    }

    AVL_Node<pair<Key, Value>>* balanceIt(AVL_Node<pair<Key, Value>>*& node) {
        updateHeight(node);
        if (getBalance(node) > 1) {
            if (getBalance(node->left) < 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }
        else if (getBalance(node) < -1) {
            if (getBalance(node->right) > 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }
        return node;
    }

    AVL_Node<pair<Key, Value>>* insert(AVL_Node<pair<Key, Value>>* node, pair<Key, Value> data) {
        if (node == nullptr) {
            return new AVL_Node<pair<Key, Value>>(data);
        }
        if (data.first < node->data.first) {
            node->left = insert(node->left, data);
        }
        else if (data.first > node->data.first) {
            node->right = insert(node->right, data);
        }
        else {
            return node;
        }
        return balanceIt(node);
    }

    AVL_Node<pair<Key, Value>>* minValueNode(AVL_Node<pair<Key, Value>>* node) {
        AVL_Node<pair<Key, Value>>* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    AVL_Node<pair<Key, Value>>* deleteNode(AVL_Node<pair<Key, Value>>* node, Key key) {
        if (node == nullptr) return node;
        if (key < node->data.first) {
            node->left = deleteNode(node->left, key);
        }
        else if (key > node->data.first) {
            node->right = deleteNode(node->right, key);
        }
        else {
            if (node->left == nullptr || node->right == nullptr) {
                AVL_Node<pair<Key, Value>>* temp = node->left ? node->left : node->right;
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                }
                else {
                    *node = *temp;
                }
                delete temp;
            }
            else {
                AVL_Node<pair<Key, Value>>* temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data.first);
            }
        }
        if (node == nullptr) return node;
        return balanceIt(node);
    }

    void printInorderHelper(AVL_Node<pair<Key, Value>>* node) {
        if (node == nullptr) return;
        printInorderHelper(node->left);
        cout << "(" << node->data.first << ", " << node->data.second << ") ";
        printInorderHelper(node->right);
    }

    Value search(AVL_Node<pair<Key, Value>>* node, Key key) {
        if (node == nullptr) {
            return nullptr;
        }
        if (key < node->data.first) {
            return search(node->left, key);
        }
        else if (key > node->data.first) {
            return search(node->right, key);
        }
        else {
            return (node->data.second);
        }
    }

public:
    AVL() : root(nullptr) {}

    void insert(Key key, Value value) {
        root = insert(root, make_pair(key, value));
    }

    void printInorder() {
        cout << "AVL in inorder:\n";
        printInorderHelper(root);
        cout << "\n";
    }

    Value search(Key key) {
        return search(root, key);
    }

    void deleteNode(Key key) {
        root = deleteNode(root, key);
    }

	AVL_Node<pair<Key, Value>>* get_root() {
		return root;
	}
};
