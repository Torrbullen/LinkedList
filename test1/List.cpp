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

int DoublyLinkedList::Size() {
	return size;
}

int DoublyLinkedList::Search(Node* nodedata) {
	if (nodedata == nullptr) {
		return 0;
	}
	if (nodedata->getNext() == nullptr && nodedata->getPrev() == nullptr && nodedata != this->NodeAt(0)) {
		return 0;
	}
	int pos = 0;
	Node* current = this->head;
	while (nodedata != current) {
		pos++;
		current = current->getNext();
	}
	return this->NodeAt(pos)->getData();
}

Node* DoublyLinkedList::NodeAt(int pos) {
	if (pos == 0) {
		return head;
	}
	else {
		Node* current = this->head;
		for (int i = 0; i < pos; i++) {
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

bool DoublyLinkedList::Remove(int pos) {
	if (pos <= size && pos > 0) {
		Node* current = this->NodeAt(pos);
		current->getNext()->setPrev(current->getPrev());
		current->getPrev()->setNext(current->getNext());
		current->setNext(nullptr);
		current->setPrev(nullptr);
		current = nullptr;
		delete current;

		return true;
	}
	else {
		return false;
	}
}
bool DoublyLinkedList::Add(Node* node, int pos) {
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
			Node* temp = tail;
			node->setNext(nullptr);
			node->setPrev(temp);
			temp->setNext(node);
			tail = node;
			
			size++;
			return  true;
		}
		else{
			Node* temp = this->NodeAt(pos);
			
			temp->getPrev()->setNext(node);
			node->setPrev(temp->getPrev());
			node->setNext(temp);
			temp->setPrev(node);

			size++;
			return true;
		}
	}
}

void DoublyLinkedList::Display_backward() {
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

void DoublyLinkedList::Display_forward() {
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

bool DoublyLinkedList::Replace(Node* oldnode, Node* newnode) {
	if (oldnode->getNext() == nullptr && oldnode->getPrev() == nullptr) {
		return false;
	}
	if (newnode == nullptr) {
		return false;
	}
	if (oldnode->getNext() == nullptr) {
		tail = newnode;
		newnode->setNext(nullptr);
		oldnode->getPrev()->setNext(newnode);
		newnode->setPrev(oldnode->getPrev());

	} 
	else if (oldnode->getPrev() == nullptr) {
		head = newnode;
		newnode->setPrev(nullptr);
		oldnode->getNext()->setPrev(newnode);
		newnode->setNext(oldnode->getNext());
	}
	else {
		oldnode->getPrev()->setNext(newnode);
		oldnode->getNext()->setPrev(newnode);
		newnode->setPrev(oldnode->getPrev());
		newnode->setNext(oldnode->getNext());
	}

	oldnode->setNext(nullptr);
	oldnode->setPrev(nullptr);
	oldnode = nullptr;
	delete oldnode;
	return true;
}