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
	next = nextNode;
}

Node* Node::getPrev() {
	return prev;
}

void Node::setPrev(Node* prevNode) {
	prev = prevNode;
}

int DoublyLinkedList::sizeOf() {
	return size;
}

Node* DoublyLinkedList::nodeAt(int pos) {
	if (pos == 0) {
		return head;
	}
	else {
		Node* current = this->head;
		for (int i = 0; i <= pos; i++) {
			current = current->getNext();
		}
		if (current != nullptr) {

			return current;
		}
		else {
			return nullptr;
		}
	}
}

bool DoublyLinkedList::remove(int pos) {
	if (pos <= size && pos > 0) {
		
		/*current->getNext()->setPrev(current->getPrev());
		current->getPrev()->setNext(current->getNext());
		current->setNext(nullptr);
		current->setPrev(nullptr);
		delete current;*/
		this->nodeAt(pos - 1)->setNext(this->nodeAt(pos + 1));
		this->nodeAt(pos + 1)->setPrev(this->nodeAt(pos - 1));
		this->nodeAt(pos)->setNext(nullptr);
		this->nodeAt(pos)->setPrev(nullptr);
		delete this->nodeAt(pos);

		return true;
	
	}
	else {
		return false;
	}
}
bool DoublyLinkedList::add(Node* node, int pos) {
	if (pos > size || pos < 0 || node == nullptr) {
		return false;
	}
	else {
		if (head == nullptr) {
			head = node;
			tail = node;
			node->setPrev(nullptr);
			node->setNext(nullptr);

			size++;
			return true;
		}
		else if (pos == size){
			Node* temp;
			temp = tail;
			node->setNext(nullptr);
			node->setPrev(temp);
			temp->setNext(node);
			tail = node;
			
			size++;
			return  true;
		}
		else{
			Node* temp = this->nodeAt(pos);
			cout << temp->getData() << endl;
			/*
			node->setNext(temp->getNext());
			temp->setNext(node);
			temp->getNext()->setPrev(node);
			node->setPrev(temp);
			*/

			size++;
			return true;
		}
	}
}

void DoublyLinkedList::display_backward() {
	if (head == nullptr) {
		cout << "emptyList";
	}
	Node* current = this->tail;
	while (current != nullptr) {
		cout << current->getData() << ", ";
		current = current->getPrev();
	}
		cout << endl;
}

void DoublyLinkedList::display_forward() {
	if (head == nullptr) {
		cout << "emptyList";
	}
	Node* current = this->head;
	while (current != nullptr) {
		cout << current->getData() << ", ";
		current = current->getNext();
	}
		cout << endl;
}


//int DoublyLinkedList::sizeOf() {
//	return size;
//}