/*
Ahmad Bin Tariq
23L-2510
BDS_3C
*/
#include <iostream>
#pragma once
using namespace std;

template <typename T>
struct AVL_Node {
	T data;
	AVL_Node* left;
	AVL_Node* right;
	int height;
	AVL_Node(T data) : data(data), left(nullptr), right(nullptr), height(0) {}
};