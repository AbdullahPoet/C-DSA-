#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define endl "\n"

template <class T>
class Node {
public:
	T val;
	Node<T>* next;

	Node(T val) : val(val), next(nullptr) {}
};

template <class T>
class Queue {
private:
	Node<T>* head;
	Node<T>* tail;
	int count;

public:
	Queue() : head(nullptr), tail(nullptr), count(0) {}

	bool push(T val) {
		Node<T>* node = new Node<T>(val);
		if (head == nullptr) {
			head = node;
			tail = node;
		} else {
			tail->next = node;
			tail = node;
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
			Node<T>* temp = head->next;
			delete head;
			head = temp;
		}
		count--;
		return true;
	}

	T front() {
		if (head != nullptr) {
			return head->val;
		}
		throw runtime_error("Queue is empty");
	}

	int size() {
		return count;
	}

	bool empty() {
		return count == 0;
	}

	~Queue() {
		Node<T>* temp = head;
		while (head != nullptr) {
			head = head->next;
			delete temp;
			temp = head;
		}
	}
};

int main() {
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;

	return 0;
}
