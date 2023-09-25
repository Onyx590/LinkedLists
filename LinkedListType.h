#pragma once
#include <iostream>
#include "nodeType.h"
#include "LinkedListIterator.h"
using namespace std;

template <typename T>
class linkedListType {
public:
	const linkedListType<T>& operator=(const linkedListType<T>&);
	void initializeList();
	bool isEmptyList() const;
	void print() const;
	int length() const;
	void destroyList();
	T front() const;
	T back() const;
	virtual bool search(const T& searchItem) const = 0;
	virtual void insertFirst(const T& newITem) = 0;
	virtual void deleteNode(const T& deleteItem) = 0;
	linkedListIterator<T> begin();
	linkedListIterator<T> end();
	linkedListType();
	linkedListType(const linkedListType<T>& otherList);
	~linkedListType();

protected:
	int count;
	nodeType<T>* first;
	nodeType<T>* last;

private:
	void copyList(const linkedListType<T>& otherList);
};