/*
Ahmad Bin Tariq
23L-2510
BDS_3C
*/
#include <iostream>
#pragma once

using namespace std;
template<typename T>
struct DLL_Node {
	T data;
	DLL_Node<T>* next;
	DLL_Node<T>* previous;
	DLL_Node(T data) : data(data), next(nullptr), previous(nullptr) {}
};