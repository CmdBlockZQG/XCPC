#include <bits/stdc++.h>
using namespace std;

template<typename T> struct LinkList {
	struct Node {
		T dat;
		Node *next = nullptr, *prev = nullptr;
		Node() {}
		Node(T d, Node *n, Node *p): dat(d), next(n), prev(p) {}
	};
	Node *head, *tail;
	int size = 0;

	LinkList() {
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->prev = head;
	}

	~LinkList() {
		Node *i = head, *j;
		while (i) {
			j = i;
			i = i->next;
			delete j;
		}
	}

	Node *insert_after(T dat, Node *x = nullptr) {
		if (!x) x = head;
		++size;
		Node *y = new Node(dat, x->next, x);
		x->next->prev = y;
		x->next = y;
		return y;
	}

	Node *insert_before(T dat, Node *x = nullptr) {
		if (!x) x = tail;
		++size;
		Node *y = new Node(dat, x, x->prev);
		x->prev->next = y;
		x->prev = y;
		return y;
	}

	void del(Node *x) {
		if (!x || x == head || x == tail) return;
		x->prev->next = x->next;
		x->next->prev = x->prev;
		--size;
		delete x;
	}

	Node *find(T dat, Node *start = nullptr) {
		if (!start) start = head->next;
		for (Node *i = start; i != tail; i = i->next) {
			if (i->dat == dat) return i;
		}
		return nullptr;
	}

	Node *rfind(T dat, Node *start = nullptr) {
		if (!start) start = tail->prev;
		for (Node *i = start; i != head; i = i->prev) {
			if (i->dat == dat) return i;
		}
		return nullptr;
	}

	Node *push_front(T dat) {
		return insert_after(dat);
	}

	Node *push_back(T dat) {
		return insert_before(dat);
	}

	void pop_front() {
		del(head->next);
	}

	void pop_back() {
		del(tail->prev);
	}
};

int main() {
	LinkList<int> t;

	int x = 114514;
	auto p = t.head;
	while (p = t.find(x, p->next)) {
		printf("%p\n", p);
	}
	return 0;
}