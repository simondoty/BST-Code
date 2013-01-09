/* 
   Exercise in implementing a Binary Search Tree in C++.
   This is one part of a three part exercise impleneting a BST in Java, C++, and Python.
   by simon doty, 1/2013
 */
#include <cstddef>
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
			return  &BSTNode<T>(); // replace
		}

		BSTNode<T>* getRight() {
			return  &BSTNode<T>(); // replace
		}

		void setRight(BSTNode<T>*) {

		}

		void setLeft(BSTNode<T>*) {

		}

		void setInfo(T info) {

		}

	private:
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
		_size = 0;
		BSTNode<T> root = BSTNode<T>(rootInfo);
		_root =  &root;
	}
 
	/*
	 insert method
	 @param info:
	 	value to insert into tree
	 */
	void insert(T info) {

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
		return false; // change
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



