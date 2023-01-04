#include "List.h"
#include <iostream>
using namespace std;


Node* n0 = new Node(0);
Node* n1 = new Node(1);

DoublyLinkedList list;

int main() {
	cout << list.add(n0, 0);
	cout << list.add(n1, 1);

	//list.display_forward();

	return 0;
}