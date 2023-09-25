#pragma once
#include <iostream>
#include "LinkedListType.h"

using namespace std;

template<typename T>
class unorderedLinkedList : public linkedListType<T> {
public:
	bool search(const T& searchItem) const;
	void insertFirst(const T& newItem);
	void insertLast(const T& newItem);
	void deleteNode(const T& deleteItem);
};