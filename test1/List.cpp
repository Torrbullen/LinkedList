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
	return next;
}

void Node::setNext(Node* nextNode) {
	
	if (nextNode == nullptr) {
		next = nullptr;
	}
	else{
		next = nextNode;
	}
}

Node* Node::getPrev() {
	return prev;
}

void Node::setPrev(Node* prevNode) {
	prev = prevNode;
}



bool DoublyLinkedList::add(Node* node, int pos) {
	if (pos != size || node == nullptr) {
		return false;
	}
	else {
		if (head == nullptr) {
			head->setNext(node);
			tail->setPrev(node);
			head->setPrev(nullptr);
			tail->setNext(nullptr);
			node->setPrev(head);
			node->setNext(tail);
			size++;
			return true;
		}
		else {
			//nodedata->setNext(tail);
			node->setNext(tail);
			node->setPrev(tail->getPrev());
			(tail->getPrev())->setNext(node);
			tail->setPrev(node);

			size++;
			return  true;
		}
	}
}

void DoublyLinkedList::display_forward() {
	if (head == nullptr) {
		cout << "emptyList";
	}
	Node* current = head->getNext();
	while (current != nullptr) {
		cout << current << "    ";
		current = current->getNext();
	}
}
//Node* Node::nodeAt(int pos) {
//	for (int i = 1; i <= pos; i++) {
//		
//	}
//}

int DoublyLinkedList::sizeOf() {
	return size;
}