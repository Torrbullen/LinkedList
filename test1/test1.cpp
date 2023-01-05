#include "List.h"
#include <iostream>
using namespace std;


Node* n0 = new Node(0);
Node* n1 = new Node(1);
Node* n2 = new Node(2);
Node* n3 = new Node(3);
Node* n4 = new Node(4);

DoublyLinkedList list;

int main() {

	cout << list.add(n0, 0);
	cout << list.add(n1, 1) << endl;
	//list.remove(3);

	list.display_forward();
	
	cout << list.add(n2, 2) << endl;
	list.display_forward();
	
	cout << list.add(n3, 3) << endl;
	list.display_forward();
	list.display_backward();
	cout << list.add(n4, 1) << endl;
	list.display_forward();
	list.display_backward();
	//list.remove(2);




	return 0;
}