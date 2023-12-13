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

	template<typename T>
	class LinkedList {
		Node<T>* head;
	public:
		LinkedList();

		LinkedList(LinkedList& other);
		LinkedList(int size);
		~LinkedList();
		LinkedList& operator=(LinkedList& other);
		int length();

		void push_tail(const T& elem);
		void push_tail(LinkedList& other);
		void push_head(const T& elem);
		void push_head(LinkedList& other);

		void pop_head();
		void pop_tail();
		void delete_node(Node<T>& node);
		T& operator[](int index);
		const T operator[](int index) const;
		void reverse();
		void printTower();
		T& back();
		Node<T>* getHead() const {
			return head;
		}
		LinkedList& operator=(const LinkedList& other) {
			if (this == &other) {
				return *this;
			}

			while (head) {
				pop_head();
			}

			Node<T>* otherCurrent = other.head;
			while (otherCurrent) {
				push_tail(otherCurrent->value);
				otherCurrent = otherCurrent->next;
			}

			return *this;
		}

	};

	template<typename T>
	LinkedList<T>::LinkedList() : head(nullptr) {}

	template<typename T>
	LinkedList<T>::LinkedList(LinkedList& other) : head(nullptr) {
		Node<T>* otherCurrent = other.head;
		while (otherCurrent) {
			push_tail(otherCurrent->value);
			otherCurrent = otherCurrent->next;
		}
	}

	template<typename T>
	LinkedList<T>::LinkedList(int size) {
		for (int i = 0; i < size; ++i) {
			push_tail(rand() % 100);
		}
	}

	template<typename T>
	LinkedList<T>::~LinkedList() {
		while (head) {
			pop_head();
		}
	}
}

	