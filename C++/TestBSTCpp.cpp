/*
 Driver file to help test and use BSTCpp.h code.
 */

 #include "BSTCpp.h"
 #include <iostream>
 
int main() {
	std::cout << "Testing BSTCpp Code" << std::endl;
	BSTCpp<int> myTree = BSTCpp<int>(5);
	std::cout << "Printing root, should be 5: " << myTree.get_root()->getInfo() << std::endl;
	std::cout << "Printing isPresent(5), should be true: " << myTree.is_present(5) << std::endl;
	myTree.insert(2);
	myTree.print_tree();
	myTree.insert(8);
	myTree.insert(19);
	myTree.insert(1);
	myTree.print_tree();

	std::cout << "Printing isPresent(7), should be false: " << myTree.is_present(7) << std::endl;
	std::cout << "Pinting isPresent(8), should be true: " << myTree.is_present(8) << std::endl;
	myTree.remove(8);
	myTree.remove(19);
	myTree.remove(2);


	myTree.print_tree();

	std::cout << "Printing isPresent(8), should be false: " << myTree.is_present(8) << std::endl;


	return 0;
}