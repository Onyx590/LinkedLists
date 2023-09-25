#include "LinkedListIterator.h"

template<typename T>
linkedListIterator<T>::linkedListIterator() {
	current = nullptr;
}

template<typename T>
linkedListIterator<T>::linkedListIterator(nodeType<T>* ptr) {
	current = ptr;
}

template<typename T>
T linkedListIterator<T>::operator*() {
	return current->info;
}

template<typename T>
linkedListIterator<T> linkedListIterator<T>::operator++() {
	current = current->link;
	return *this;
}

template<typename T>
bool linkedListIterator<T>::operator==(const linkedListIterator<T>& right) const {
	return (current == right.current);
}

template<typename T>
bool linkedListIterator<T>::operator!=(const linkedListIterator<T>& right) const {
	return (current != right.current);
}

