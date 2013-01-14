/* 
   Exercise in implementing a Binary Search Tree in C++.
   This is one part of a three part exercise impleneting a BST in Java, C++, and Python.
   by simon doty, 1/2013
 */
#include <cstddef>
#include <iostream>
#include <string>
#include <cstdlib>

// templateed node class
template< typename T>
class BSTNode 
{

	public:

		/*
		 Constructor taking one argument for value
		 @param info:
		 		initial value of node
		 */
		BSTNode (T info) : _myInfo (info), _myRight (NULL), _myLeft (NULL) {}
		
		/*
		 getInfo returns the value stored in the node
		 */
		T getInfo() { 
			return _myInfo;
		}

		/*
		 getLeft returns the left child node
		 */
		BSTNode<T>* getLeft() {
			return _myLeft; // replace
		}

		/*
		 getRight returns the right child node
		 */
		BSTNode<T>* getRight() {
			return  _myRight; // replace
		}

		/*
		 Sets the right child node
		 @param newRight:
		 		the new right child node
		 */
		void setRight(BSTNode<T>* newRight) {
			_myRight = newRight;
		}

		/*
		 Sets the left child node
		 @param newLeft:
		 		the new left child node
		 */
		void setLeft(BSTNode<T>* newLeft) {
			_myLeft = newLeft;
		}

		void setInfo(T info) {
			_myInfo = info;
		}

	    // data members

		BSTNode<T>* _myRight;
		BSTNode<T>* _myLeft;
		T _myInfo;

};

template <typename T>
class BSTCpp {

public:	

	int _size;

	/*
	  default constructor
	 */
	BSTCpp (T rootInfo) {
		_size = 1;		
		_root =  new BSTNode<T>(rootInfo);
	}
 	
 	/*
 	  Destructor to delete values on heap
 	 */
 	~BSTCpp() {
 		recursiveDelete(_root);
 		//delete _root;
 	}

 	/*
 	  recursiveDelete helper to delete allocs
 	  @param node:
 	  		current node
 	 */
 	void recursiveDelete(BSTNode<T>* node) {
 		if (node != NULL) {
 			recursiveDelete(node->getLeft());
 			recursiveDelete(node->getRight());
 			delete node;
 		} 			
 	}

	/*
	 insert method
	 @param info:
	 	value to insert into tree
	 */
	void insert(T info) {
		// use iterative algo
		BSTNode<T>* temp = _root;
		bool insert_node = false;

		while (!insert_node) {

			if (info < temp->getInfo()) {
				if (temp->getLeft() == NULL) {
					temp->_myLeft = new BSTNode<T>(info);
					insert_node = true;
				} else 
					temp = temp->getLeft();
			}
			else if (info > temp->getInfo()) {
				if (temp->getRight() == NULL) {
					temp->_myRight = new BSTNode<T>(info);					
					insert_node = true;
				} else 
					temp = temp->getRight();
			} 
			else
				std::cout << "Value to add is already present." << std::endl;
		}		
	}   
	
	/*
	 remove specified value from the tree if present
	 @param info:
	 	value to remove from tree if present
	 */
	void remove(T info) {
		_root = recursiveRemove(_root, info);
	}

	/*
	  Recursive helper for remove method
	  @param node:
	  		current node to be evaluated
	  @param info:
	  		value to be removed if found
	 */
	BSTNode<T>* recursiveRemove(BSTNode<T>* node, T info) {
		// base case
		if (node == NULL)
			return node;
		T tempInfo = node->getInfo();
		if (info < tempInfo)
			node->setLeft(recursiveRemove(node->getLeft(), info));
		else if (info > tempInfo)
			node->setRight(recursiveRemove(node->getRight(), info));
		else {
			_size -= 1;
			if (node->getRight() == NULL && node->getLeft() == NULL) {
				delete node;
				node = NULL; //node = NULL;
			}
			else if (node->getRight() == NULL) {
				BSTNode<T>* temp = node;
				node = node->getLeft();
				delete temp;
			}
			else if (node->getLeft() == NULL) {
				BSTNode<T>* temp = node;
				node = node->getRight();
				delete temp;
			}
			else {
				node->setInfo(max(node->getLeft()));
				node->setLeft(recursiveRemove(node->getLeft(), node->getInfo()));
				_size += 1;
			}
		}
		return node;
	}

	/*
	 Return max value given starting node.
	 @param tempNode:
	 		starting node
	 */
	T max(BSTNode<T>* tempNode) {
		if (tempNode == NULL)
			std::cout << "Invalid parameter domain" << std::endl;
		while (tempNode->getRight() != NULL)
			tempNode = tempNode->getRight();
		return tempNode->getInfo();
	}
	/*
	  determine if giving value is present in tree or not
	  @param:
	  	 info is the value to check whether present in tree or not
	 */
	bool is_present(T info) {
		if (_size == 0)
			return false;
		BSTNode<T>* temp = _root;
		while (temp != NULL){
			T tempInfo = temp->getInfo();
			if (info > tempInfo)
				temp = temp->getRight();
			else if (info < tempInfo)
				temp = temp->getLeft();
			else
				return true;
		}
		return false; 
	}


	void print_tree() {
        print_tree_help(_root, "");
        std::cout << std::endl;
    }

    void print_tree_help(BSTNode<T>* n, std::string spaces) {
        if(n != NULL){
            print_tree_help(n->getRight(), spaces + "  ");
            std::cout << spaces << n->getInfo() << std::endl;
            print_tree_help(n->getLeft(), spaces + "  ");
        }
    }

	/*
	 return root 
	 */
	BSTNode<T>* get_root() {
		return _root;
	}

private:

	BSTNode<T>* _root;

};



