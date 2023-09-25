#include "unorderedLinkedList.h"

template<typename T>
bool unorderedLinkedList<T>::search(const T& searchItem) const {
	nodeType<T>* current;
	bool found = false;

	current = first;

	while (current != nullptr && !found) {
		if (current->info == searchItem)
			found = true;
		else
			current = current->link;

	}
	return found;
}

template<typename T>
void unorderedLinkedList<T>::insertFirst(const T& newItem) {
	nodeType<T>* newNode;
	newNode = new nodeType<T>;
	newNode->info = newItem;
	newNode->link = first;
	first = newNode;

	count++;

	if (last == nullptr)
		last = newNode;
}

template<typename T>
void unorderedLinkedList<T>::insertLast(const T& newItem) {
	nodeType<T>* newNode;
	newNode = new nodeType<T>;

	newNode->info = newItem;
	newNode->link = nullptr;

	if (first == nullptr) {
		first = newNode;
		last = newNode;
		count++;
	}
	else {
		last->link = newNode;
		last = newNode;

		count++;
	}
}

template<typename T>
void unorderedLinkedList<T>::deleteNode(const T& deleteItem) {
	nodeType<T>* current;
	nodeType<T>* trailCurrent;
	bool found;

	if (first == nullptr) {
		cout << "Cannot delete from an empty list" << endl;
	}
	else {
		if (first->info == deleteItem) {
			current = first;
			first = first->link;
			count--; 
			if (first == nullptr)
				last = nullptr;
			delete current;
		}
		else {
			found = false;
			trailCurrent = first;

			current = first->link;

			while (current != nullptr && !found) {
				if (current->info != deleteItem) {
					trailCurrent = current;
					current = current->link;
				}
				else
					found = true;
			}//end while

			if (found) {
				trailCurrent-> = current->link;
				cout--;
				if (last == current)
					last = trailCurrent;
				delete current;
			}
			else
				cout << "The item to be deleted is not in the list" << endl;
		}
	}
}