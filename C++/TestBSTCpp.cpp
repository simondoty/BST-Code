/*
 Driver file to help test and use BSTCpp.h code.
 */

 #include "BSTCpp.h"
 #include <iostream>
 
int main() {
	std::cout << "Testing BSTCpp Code" << std::endl;
	BSTCpp<int> myTree = BSTCpp<int>(5);

	myTree.insert(2);
	myTree.print_tree();
	myTree.insert(8);
	myTree.insert(19);
	myTree.insert(1);
	myTree.insert(3);
	myTree.insert(4);
	myTree.insert(6);
	myTree.insert(7);

	myTree.print_tree();

	myTree.remove(8);
	myTree.remove(19);
	myTree.remove(2);

	myTree.print_tree();
	
	return 0;
}