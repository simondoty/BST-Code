/* 
  Excersise in implementing a Binary Search Tree in Java.
  implemented by: simon doty, 2012.
 */

  import java.util.*;

  private static class BSTNode<E extends Comparable<? super E> > {

  	// data memebers
  	private E myData;

  	private BSTNode<E> myLeft;
  	private BSTNode<E> myRight;

  	/*
  	 Default Constructor
  	 */
  	public void BSTNode () {
  		this(null); 		
  	}

  	/*
  	 One-arg Constructor with data value
  	   @param data:
  	   		initial value of objects myData field
  	 */
  	public void BSTNode (E data){
  		this(null, null, data);
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
  	public void BSTNode (BSTNode<E> leftNode, BSTNode<E> rightNode, E data) {
  		this.myData = data;
  		myLeft = leftNode;
  		myRight = rightNode;
  	}

    /*
     return value stored in the node
     */
     public E getValue () {
        return this.myData;
     }

    /*
      Set the data of the node
      @param newData:
        the new value of the node
     */
    public void setValue(E data) {
        this.myData = data;
    }

    /*
      return the left child node
     */
    public BSTNode<E> getLeft () {
        return this.myLeft;
    }

    /*
      return the right child node
     */
    public BSTNode<E> getRight () {
        return this.myRight;
    }
    
    /*
      set the right child node
      @param newRight:
            new myRight node
     */
    public void setRight (BSTNode<E> newRight) {
        this.myRight = newRight;
    }
  } // end class BSTNode