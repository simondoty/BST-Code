/* 
  Excersise in implementing a Binary Search Tree in Java.
  implemented by: simon doty, 2012.
 */

  import java.util.*;

  private static class BSTNode<E extends Comparable<E?> > {

  	// data memebers
  	private E myData;

  	private BSTNode myLeft;
  	private BSTNode myRight;

  	/*
  	 Default Constructor
  	 */
  	public void BSTNode () {
  		myLeft = null;
  		myRight = null;  		
  	}

  	/*
  	 One-arg Constructor with data value
  	   @param data:
  	   		initial value of objects myData field
  	 */
  	public void BSTNode (E data){
  		this.myData = data;
  		myLeft = null;
  		myRigth = null;
  	}

  	/*
  	 multiple-arg Constructor with data value and child nodes
  	   @param leftNode:
  	   		left child node
  	   @param rightNode:
  	   		right child node
  	   @param data:
  	   		initial value of objects myData field
  	 */
  	public void BSTNode (BSTNode leftNode, BSTNode rightNode, E data) {
  		this.myData = data;
  		myLeft = leftNode;
  		myRight = rightNode;
  	}


  }