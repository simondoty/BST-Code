/* 
   Exercise in implementing a Binary Search Tree in C++.
   This is one part of a three part exercise impleneting a BST in Java, C++, and Python.
   by simon doty, 1/2013
 */
#include <cstddef>
#include <iostream>

// templateed node class
template< typename T>
class BSTNode 
{

	public:

		BSTNode (T info) : _myInfo (info), _myRight (NULL), _myLeft (NULL) {}
		
		T getInfo() { 
			return _myInfo;
		}

		BSTNode<T>* getLeft() {
			return _myLeft; // replace
		}

		BSTNode<T>* getRight() {
			return  _myRight; // replace
		}

		void setRight(BSTNode<T>* newRight) {
			_myRight = newRight;
		}

		void setLeft(BSTNode<T>* newLeft) {
			_myLeft = newLeft;
		}

		void setInfo(T info) {
			_myInfo = info;
		}

	//private:
		// private data members
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
 		delete _root->_myLeft;
 		delete _root->_myRight;
 		delete _root;
 	}

	/*
	 insert method
	 @param info:
	 	value to insert into tree
	 */
	void insert(T info) {
		// use iterative algo
		BSTNode<T>* temp = _root;
		BSTNode<T>* newNode;
		bool insert_node = false;

		while (!insert_node) {

			if (info < temp->getInfo()) {
				if (temp->getLeft() == NULL) {
					temp->_myLeft = new BSTNode<T>(info);
					insert_node = true;
				} 
				else 
					temp = temp->getLeft();
			}
			else if (info > temp->getInfo()) {
				if (temp->getRight() == NULL) {
					temp->_myRight = new BSTNode<T>(info);					
					insert_node = true;
				}  
				else 
					temp = temp->getRight();
			} else
				std::cout << "Value to add is already present." << std::endl;
		}
		//if (newNode != 0)
			//delete newNode;
	}   
	
	/*
	 remove specified value from the tree if present
	 @param info:
	 	value to remove from tree if present
	 */
	void remove(T info) {

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

	/*
	  print tree 
	 */
	void print_tree() {

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



