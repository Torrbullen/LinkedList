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
	bool Add(Node* nodedata, int pos);
	bool Remove(int pos);
	bool Replace(Node* oldnode, Node* newnode);
	int Search(Node* nodedata);
	Node* NodeAt(int pos);
	void Display_forward();
	void Display_backward();
	int Size();
};

