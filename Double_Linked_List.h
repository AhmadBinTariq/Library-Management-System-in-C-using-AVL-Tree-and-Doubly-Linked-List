/*
Ahmad Bin Tariq
23L-2510
BDS_3C
*/
#include <iostream>
#include "DLL_Node.h"
#include <utility>
#pragma once

using namespace std;

template<typename Key, typename Value>
class Double_Linked_List {
    DLL_Node<pair<Key, Value>>* head;
    DLL_Node<pair<Key, Value>>* tail;

public:
    Double_Linked_List() : head(nullptr), tail(nullptr) {}

    void insert(Key key, Value value) {
        DLL_Node<pair<Key, Value>>* new_node = new DLL_Node<pair<Key, Value>>(make_pair(key, value));
        if (!head) {
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            new_node->previous = tail;
            tail = new_node;
        }
    }
    void display() const {
        DLL_Node<pair<Key, Value>>* temp = head;
        while (temp) {
            cout << *(temp->data.second);
            temp = temp->next;
            cout << endl;
        }
        cout << endl;
    }

    bool remove(Key key) {
        DLL_Node<pair<Key, Value>>* temp = head;

        while (temp) {
            if (temp->data.first == key) {
                if (temp == head) {
                    head = head->next;
                    if (head) head->previous = nullptr;
                }
                else if (temp == tail) {
                    tail = tail->previous;
                    if (tail) tail->next = nullptr;
                }
                else {
                    temp->previous->next = temp->next;
                    temp->next->previous = temp->previous;
                }
                delete temp;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    DLL_Node<Value>* find_node(Key key) const {
        DLL_Node<pair<Key, Value>>* temp = head;
        while (temp) {
            if (temp->data.first == key) {
				DLL_Node<Value>* Data = new DLL_Node<Value>(temp->data.second);
				return Data;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void insert_sorted(Key key, Value value) {
        DLL_Node<pair<Key, Value>>* newNode = new DLL_Node<pair<Key, Value>>(make_pair(key, value));

        if (!head) {
            head = tail = newNode;
            return;
        }
        DLL_Node<pair<Key, Value>>* temp = head;
        while (temp && temp->data.first < key) {
            temp = temp->next;
        }
        if (temp == head) {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
            return;
        }
        if (!temp) {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
            return;
        }
        DLL_Node<pair<Key, Value>>* prevNode = temp->previous;
        prevNode->next = newNode;
        newNode->previous = prevNode;
        newNode->next = temp;
        temp->previous = newNode;
    }

	DLL_Node<pair<Key, Value>>* get_head() const {
		return head;
	}
    ~Double_Linked_List() {
        DLL_Node<pair<Key, Value>>* temp = head;
        while (temp) {
            DLL_Node<pair<Key, Value>>* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};
