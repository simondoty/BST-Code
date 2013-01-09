/*
 Driver file to help test and use BSTCpp.h code.
 */

 #include "BSTCpp.h"
 #include <iostream>
 
int main() {
	std::cout << "Testing BSTCpp Code" << std::endl;
	BSTCpp<int> myTree = BSTCpp<int>(5);
	std::cout << "Printing root, should be null: " << myTree.get_root()->getInfo() << std::endl;

	return 0;
}