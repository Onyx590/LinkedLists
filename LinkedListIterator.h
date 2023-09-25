#pragma once
#include <iostream>
#include "nodeType.h"

using namespace std;

template <typename T>
class linkedListIterator {
public:
	linkedListIterator();
	linkedListIterator(nodeType<T>* ptr);
	T operator*();
	linkedListIterator<T> operator++();
	bool operator==(const linkedListIterator<T>& right) const;
	bool operator!=(const linkedListIterator<T>& right) const;

private:
	nodeType<T>* current;
};