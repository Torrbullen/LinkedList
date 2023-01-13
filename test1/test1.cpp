//#include "List.h"
//#include <iostream>
//using namespace std;
//
//
//Node* n0 = new Node(0);
//Node* n1 = new Node(1);
//Node* n2 = new Node(2);
//Node* n3 = new Node(3);
//Node* n4 = new Node(4);
//Node* n5 = new Node(5);
//
//
//DoublyLinkedList list;
//
//int main() {
//
//	cout << list.Add(n0, 0) << endl;
//	//cout << list.Search(n0) << endl;
//	//cout << list.Add(n1, 10) << endl; //should be a false or -1 (error/invalid) 
//	//cout << list.Add(nullptr, 1) << endl; //should be a false or -1 (error/invalid) 
//	list.Add(n1, 1);
//	//cout << list.Remove(3) << endl; //should be a false or -1 (error/invalid) 
//	list.Add(n2, 2);
//	list.Display_forward();
//	list.Add(n3, 1);
//	list.Display_forward();
//	list.Remove(2);
//	list.Display_forward();
//	list.Display_backward();
//	//cout << list.Search(n4) << endl; //should be a false or -1 (error/invalid) 
//	cout << list.Search(n3) << endl;
//	//cout << list.Replace(n3, nullptr) << endl; //should be a false or -1 (error/invalid) 
//	//cout << list.Replace(n5, n4) << endl; //should be a false or -1 (error/invalid) 
//	list.Replace(n3, n4);
//	list.Display_forward();
//	cout << list.Size() << endl;
//
//
//
//
//
//	return 0;
//}