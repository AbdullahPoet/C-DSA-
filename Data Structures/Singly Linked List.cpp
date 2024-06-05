#include<iostream>

using namespace std;
using ll = long long;
#define endl "\n"

template <class T>
class Node {
public:
	T val;
	Node<T>* next;

	Node(T val): val(val), next(nullptr) {}
};

template <class T>
class LinkedList {
public:
	Node<T>* head;
	Node<T>* tail;
	int count;

	LinkedList(): head(nullptr), tail(nullptr), count(0) {}

	int size() {
		return count;
	}

	bool insert(T val) {
		Node<T> *node = new Node<T>(val);
		if (head == nullptr) {
			head = node;
			tail = node;
		}
		else {
			tail -> next = node;
			tail = node;
		}
		count++;
		return true;
	}

	bool insert_at_first(T val) {
		if (count == 0) return insert(val);
		Node<T>* node = new Node<T>(val);
		node->next = head;
		head = node;
		count++;
		return true;
	}

	bool insert_at_last(T val) {
		return insert(val);
	}

	bool insert_at_nth(int ind, T val) {
		if (ind > count) return false;
		if (ind == count) return insert(val);
		if (ind == 0) return insert_at_first(val);

		ind--;
		Node<T>* temp = head;
		while (ind) {
			temp = temp->next;
			ind--;
		}

		Node<T>* node = new Node<T>(val);
		node -> next = temp -> next;
		temp -> next = node;
		count++;
		return true;
	}

	bool remove_val(T val) {
		if (head == nullptr) return false;
		if (head->val == val) return remove_first();
		Node<T>* temp = head;
		bool flag = false;
		while (temp -> next != nullptr) {
			if (temp-> next -> val == val ) {
				flag = true;
				break;
			}
			temp = temp -> next;
		}
		if (!flag) return false;
		Node<T>* to_del = temp -> next;
		temp -> next = to_del -> next;
		if (to_del == tail) tail = temp;
		count--;
		delete to_del;
		return true;
	}

	bool remove_nth(int ind) {
		if (ind >= count) return false;
		if (ind == 0) return remove_first();

		ind--;
		Node<T>* temp = head;
		while (ind) {
			temp = temp->next;
			ind--;
		}
		Node<T>* to_del = temp -> next;
		temp -> next = to_del -> next;
		if (to_del == tail) tail = temp;
		count--;
		delete to_del;
		return true;

	}

	bool remove_first() {
		if (head == nullptr) return false;
		if (head == tail) {
			delete head;
			head = nullptr;
			tail = nullptr;
			count--;
			return true;
		}
		Node<T>* temp = head;
		temp = head;
		head = temp->next;
		delete temp;
		count--;
		return true;
	}

	void print_linkedlist() {
		Node<T>* temp = head;
		while (temp != nullptr) {
			cout << temp->val << endl;
			temp = temp -> next;
		}
	}

	void clear_helper() {
		Node<T>* temp = head;
		while (head != nullptr) {
			temp = head;
			head = head -> next;
			delete temp;
		}
	}

	void clear() {
		clear_helper();
		count = 0;
		head = nullptr;
		tail = nullptr;
	}

	~LinkedList() {
		clear_helper();
	}
};


int32_t main() {
	LinkedList<int> l;
}