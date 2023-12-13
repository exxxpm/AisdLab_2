#include <iostream>
#include <cstdlib> 
#include <stdexcept> 


namespace Linkedlist {

	template<typename T>
	class Node {
	public:
		T value;
		Node* next;
		Node(T value) :value(value), next(nullptr) {}
	};

}

	