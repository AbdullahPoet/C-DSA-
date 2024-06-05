#include <iostream>

using namespace std;
using ll = long long;
#define endl "\n"

template <class T>
class Node {
public:
	T val;
	Node<T>* next;
	Node<T>* prev;

	Node(T val) : val(val), next(nullptr), prev(nullptr) {}
};

template <class T>
class Stack {
private:
	Node<T>* head;
	Node<T>* tail;
	int count;

public:
	Stack() : head(nullptr), tail(nullptr), count(0) {}

	int size() {
		return count;
	}

	bool push(T val) {
		Node<T>* n = new Node<T>(val);
		if (head == nullptr) {
			head = n;
			tail = n;
		} else {
			tail->next = n;
			n->prev = tail;
			tail = n;
		}
		count++;
		return true;
	}

	bool pop() {
		if (count <= 0) return false;
		if (head == tail) {
			delete head;
			head = nullptr;
			tail = nullptr;
		} else {
			Node<T>* temp = tail->prev;
			temp->next = nullptr;
			delete tail;
			tail = temp;
		}
		count--;
		return true;
	}

	T top() {
		if (tail != nullptr) {
			return tail->val;
		}
		throw runtime_error("Stack is empty");
	}

	bool empty() {
		return count == 0;
	}

	~Stack() {
		while (head != nullptr) {
			Node<T>* temp = head;
			head = head->next;
			delete temp;
		}
	}
};

int main() {
	Stack<int> st;
	st.push(12);
	st.push(13);
	st.push(14);

	while (!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}

	return 0;
}
