/*
 Some simple tests to check construction of BSTJava.
 simon doty, 1/2013
 */

 public class BSTJavaTest {

 	public static void main(String[] args) {
 		BSTJava<String> t = new BSTJava<String>();
 		t.add("hi");
 		t.printTree();
 		System.out.println("Printing if 'hi' isPresent in tree: " + t.isPresent("hi")); 		
 	}
 }