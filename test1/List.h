#pragma once

class Node {
private:
	int data;
	Node* next;
	Node* prev;
public:
	Node(int Data);
	int getData();
	void setData(int newData);
	Node* getNext();
	void setNext(Node* nextNode);
	Node* getPrev();
	void setPrev(Node* prevNode);
};

class DoublyLinkedList {
private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;
public:
	bool add(Node* nodedata, int pos);
	bool remove(int pos);
	bool replace(Node* oldnode, Node* newnode);
	int search(Node* nodedata);
	Node* nodeAt(int pos);
	void display_forward();
	void display_backward();
	int sizeOf();
};

