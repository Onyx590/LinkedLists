#pragma once
#include <iostream>

using namespace std;


template <typename T>
struct nodeType {
	T info;
	nodeType<T>* link;
};