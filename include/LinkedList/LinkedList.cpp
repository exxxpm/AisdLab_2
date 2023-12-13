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
		void reverse();
		void printTower();
		T& operator[](int index);
		const T operator[](int index) const;
		
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

	template<typename T>
	int LinkedList<T>::length() {
		int count = 0;
		Node<T>* current = head;

		while (current != nullptr) {
			count++;
			current = current->next;
		}

		return count;
	}

	template<typename T>
	void LinkedList<T>::push_tail(const T& elem) {
		Node<T>* newNode = new Node<T>(elem);
		if (!head) {
			head = newNode;
		}
		else {
			Node<T>* current = head;
			while (current->next) {
				current = current->next;
			}
			current->next = newNode;
		}
	}

	template<typename T>
	void LinkedList<T>::push_tail(LinkedList& other) {
		Node<T>* otherCurrent = other.head;
		while (otherCurrent) {
			push_tail(otherCurrent->value);
			otherCurrent = otherCurrent->next;
		}
	}

	template<typename T>
	void LinkedList<T>::push_head(const T& elem) {
		Node<T>* newNode = new Node<T>(elem);
		if (!head) {
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}

	template<typename T>
	void LinkedList<T>::push_head(LinkedList& other) {
		LinkedList temp(other);
		temp.reverse();
		push_tail(temp);
	}

	template<typename T>
	void LinkedList<T>::pop_head() {
		if (head) {
			Node<T>* temp = head;
			head = head->next;
			delete temp;
		}
	}

	template<typename T>
	void LinkedList<T>::pop_tail() {
		if (!head) { return; }

		if (!head->next) {
			delete head;
			head = nullptr;
			return;
		}

		Node<T>* current = head;
		while (current->next->next) {
			current = current->next;
		}
		delete current->next;
		current->next = nullptr;
	}

	template<typename T>
	void LinkedList<T>::delete_node(Node<T>& node) {
		while (head && head->data == node) {
			pop_head();
		}

		Node<T>* current = head;
		while (current && current->next) {
			if (current->next->data == node.value) {
				Node<T>* temp = current->next;
				current->next = current->next->next;
				delete temp;
			}
			else {
				current = current->next;
			}
		}
	}

	template<typename T>
	void LinkedList<T>::reverse() {
		Node<T>* prev = nullptr;
		Node<T>* current = head;
		Node<T>* nextNode = nullptr;

		while (current) {
			nextNode = current->next;
			current->next = prev;
			prev = current;
			current = nextNode;
		}

		head = prev;
	}

	template<typename T>
	void LinkedList<T>::printTower() {
		Node<T>* current = head;
		while (current) {
			std::cout << current->value << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}


	template<typename T>
	T& LinkedList<T>::operator[](int index) {
		Node<T>* current = head;
		int count = 0;
		while (current) {
			if (count == index) {
				return current->value;
			}
			current = current->next;
			count++;
		}
		throw std::out_of_range("Index out of range");
	}

	template<typename T>
	const T LinkedList<T>::operator[](int index) const {
		Node<T>* current = head;
		int count = 0;
		while (current) {
			if (count == index) {
				return current->value;
			}
			current = current->next;
			count++;
		}
		throw std::out_of_range("Index out of range");
	}

	template<typename T>
	inline T& LinkedList<T>::back() {
		Node<T>* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		return current->value;
	}
	template<typename T>
	LinkedList<T> addNumbers(LinkedList<T>& num1, LinkedList<T>& num2) {
		LinkedList<T> result;
		int carry = 0;

		Node<T>* ptr1 = num1.getHead();
		Node<T>* ptr2 = num2.getHead();

		while (ptr1 != nullptr || ptr2 != nullptr || carry) {
			int sum = carry;

			if (ptr1 != nullptr) {
				sum += ptr1->value;
				ptr1 = ptr1->next;
			}

			if (ptr2 != nullptr) {
				sum += ptr2->value;
				ptr2 = ptr2->next;
			}

			carry = sum / 10;
			sum %= 10;
			result.push_tail(sum);
		}

		return result;
	}

	template<typename T>
	Linkedlist::LinkedList<T> multiplyNumbers(Linkedlist::LinkedList<T>& num1, Linkedlist::LinkedList<T>& num2) {
		Linkedlist::LinkedList<T> result;
		result.push_tail(0);

		typename Linkedlist::Node<T>* ptr2 = num2.getHead();

		int position = 0;

		while (ptr2 != nullptr) {
			Linkedlist::LinkedList<T> temp;
			int carry = 0;

			for (int i = 0; i < position; ++i) {
				temp.push_tail(0);
			}

			typename Linkedlist::Node<T>* ptr1 = num1.getHead();

			while (ptr1 != nullptr || carry) {
				int mul = carry;

				if (ptr1 != nullptr) {
					mul += ptr1->value * ptr2->value;
					ptr1 = ptr1->next;
				}

				carry = mul / 10;
				mul %= 10;
				temp.push_tail(mul);
			}

			result = addNumbers(result, temp);
			ptr2 = ptr2->next;
			position++;
		}

		return result;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, LinkedList<T>& list) {
		Node<T>* current = list.getHead();
		while (current != nullptr) {
			os << current->value;
			current = current->next;
		}
		return os;
	}
}

	