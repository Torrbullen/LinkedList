#include "List.h"
#include <iostream>
using namespace std;

Node::Node(int Data) {
	data = Data;
	next = nullptr;
	prev = nullptr;
}

int Node::getData() {
	return data;
}

void Node::setData(int newData) {
	data = newData;
}

Node* Node::getNext() {
	if (next == nullptr) {
		return nullptr;
	}
	return next;
}

void Node::setNext(Node* nextNode) {
	if (nextNode) {
		next = nextNode;
	}
	else {
		cout << "nullptr";
	}
}

Node* Node::getPrev() {
	return prev;
}

void Node::setPrev(Node* prevNode) {
	prev = prevNode;
}

//Node* DoublyLinkedList::nodeAt(int pos) {
//	for (int i = 0; i < pos; i++) {
//
//	}
//}

bool DoublyLinkedList::add(Node* node, int pos) {
	if (pos != size || node == nullptr) {
		return false;
	}
	else {
		if (head == nullptr) {
			head = node;
			tail = node;
			size++;
			return true;
		}
		else {
			node->setNext(nullptr);
			node->setPrev(tail);
			tail = node;

			size++;
			return  true;
		}
	}
}

void DoublyLinkedList::display_backward() {
	if (head == nullptr) {
		cout << "emptyList";
	}
	Node* current = this->tail;
	while (current != nullptr) {
		cout << current->getData() << "    ";
		current = current->getPrev();
	}
}


int DoublyLinkedList::sizeOf() {
	return size;
}