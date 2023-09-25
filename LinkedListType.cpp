#include "LinkedListType.h"

template <typename T>
bool linkedListType<T>::isEmptyList() const {
	return (first == nullptr);
}

template <typename T>
linkedListType<T>::linkedListType() {
	first = nullptr;
	last = nullptr;
	count = 0;
}

template<typename T>
void linkedListType<T>::destroyList() {
	nodeType<T>* temp;

	while (first != nullptr) {
		temp = first;
		first = first->link;
		delete temp;
	}
	last = nullptr;

	count = 0;
}

template<typename T>
void linkedListType<T>::initializeList() {
	destroyList();
}

template<typename T>
void linkedListType<T>::print() const {
	nodeType<T>* current;
	current = first;

	while (current != nullptr) {
		cout << current->info << " ";
		current = current->link;
	}
}

template <typename T>
int linkedListType<T>::length() const {
	return count;
}

template<typename T>
T linkedListType<T>::front() const {
	assert(first != nullptr);

	return first->info;
}

template<typename T>
T linkedListType<T>::back() const {
	assert(last != nullptr);

	return last->info;
}

template<typename T>
linkedListIterator<T> linkedListType<T>::begin() {
	linkedListIterator<T> temp(first);
	return temp;
}

template<typename T>
linkedListIterator<T> linkedListType<T>::end() {
	linkedListIterator<T> temp(nullptr);

	return temp;
}

template<typename T>
void linkedListType<T>::copyList(const linkedListType<T>& otherList) {
	nodeType<T>* newNode;
	nodeType<T>* current;

	if (first != nullptr)
		destroyList;

	if (otherList.first == nullptr) {
		first = nullptr;
		last = nullptr;
		count = 0;	
	}
	else {
		current = otherList.first;
		count = otherList.count;

		first = new nodeType<T>;
		first->info = current->info;
		first->link = nullptr;

		last = first;

		current = current->link;

		while (current != nullptr) {
			newNode = new nodeType<T>;
			newNode->info = current->info;
			newNode->link = nullptr;

			last->link = newNode;
			last = newNode;

			current = current->link;
		}
	}
}

template <typename T>
linkedListType<T>::~linkedListType() {
	destroyList();
}

template <typename T>
linkedListType<T>::linkedListType(const linkedListType<T>& otherList) {
	first = nullptr;
	copyList(otherList);
}

template<typename T>
const linkedListType<T>& linkedListType<T>::operator=(const linkedListType<T>& otherList) {
	if (this != &otherList) {
		copyList(otherList);
	}
	return *this;
}