/*
 Some simple tests to check construction of BSTJava.
 simon doty, 1/2013
 */

 public class BSTJavaTest {

 	public static void main(String[] args) {
 		BSTJava<String> t = new BSTJava<String>();
 		//t.add("hi");
 		t.printTree();
 		System.out.println("Printing if 'hi' isPresent in tree: " + t.isPresent("hi")); 
 		t.add("bello");
 		t.add("helloe");
 		t.add("z");
 		t.add("a");
 		t.printTree();
 		System.out.println("Printing if 'bello' isPresent in tree: " + t.isPresent("bello")); 
 		System.out.println("Printing if 'bellos' isPresent in tree: " + t.isPresent("bell")); 
 		System.out.println("Printing if 'z' isPresent in tree: " + t.isPresent("z")); 
        t.remove("helloe");
 		System.out.println("removed z");
 		t.printTree();


 	}
 }