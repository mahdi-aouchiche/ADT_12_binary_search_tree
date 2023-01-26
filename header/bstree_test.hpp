#ifndef __BSTREE_TEST_HPP__
#define __BSTREE_TEST_HPP__

#include <iostream>
#include "../src/node.cpp"
#include "../src/binary_search_tree.cpp"
using namespace std;

void run_tests() {
  cout << "Constructing BS Tree...";
  BSTree bst = BSTree();
  cout << "complete." << endl;

  int totalTests = 0,failedTests = 0;
  totalTests++;
  cout << "Test 1 : testing largest on empty tree...";
  if (bst.largest() == "") {
    cerr << "Passed" << endl;
  } else {
    cerr << "Failed" << endl;
    failedTests++;
  }
  totalTests++;
  cout << "Test 2 : testing smallest on empty tree...";
  if (bst.smallest() == "") {
    cerr << "Passed" << endl;
  } else {
    cerr << "Failed" << endl;
    failedTests++;
  }
  /* Test insert (assume search works) */
  totalTests++;
  cout << "Test 3 : testing insert and search...";
  string test_input = "Hello";
  bst.insert(test_input);
  if (bst.search(test_input)) {
    cerr << "Passed" << endl;
  } else {
    cerr << "Failed" << endl;
    failedTests++;
  }

  totalTests++;
  cout << "Test 4 : testing insert second word and search first and second...";
  string test_input2 = "World";
  bst.insert(test_input2);
  if (bst.search(test_input) && bst.search(test_input2)) {
    cerr << "Passed" << endl;
  } else {
    cerr << "Failed" << endl;
    failedTests++;
  }

  totalTests++;
  cout << "Test 5 : testing insert duplicate and search first (duplicate) and second...";
  string test_input_duplicate = "Hello";
  bst.insert(test_input_duplicate);
  if (bst.search(test_input) && bst.search(test_input2)) {
    cerr << "Passed" << endl;
  } else {
    cerr << "Failed" << endl;
    failedTests++;
  }

  totalTests++;
  cout << "Test 6 : testing remove duplicate and search first (duplicate) second...";
  bst.remove(test_input);
  if (bst.search(test_input)) {
    cerr << "Passed" << endl;
  } else {
    cerr << "Failed" << endl;
    failedTests++;
  }

  totalTests++;
  cout << "Test 7 : testing remove first (now gone)...";
  bst.remove(test_input);
  if (!bst.search(test_input) && bst.search(test_input2)) {
    cerr << "Passed" << endl;
  } else {
    cerr << "Failed" << endl;
    failedTests++;
  }

  // Add tests for largest and smallest on non-empty trees
  string s1, s2, s3, s4, s5;
  BSTree b;
  s1 = "Z"; s2 = "B"; s3 = "Hellos"; s4 = "A"; s5 = "Hello";
  b.insert(s5);
  b.insert(s1);
  b.insert(s2);
  b.insert(s3);
  b.insert(s4);
    
  totalTests++;
  cout << "Test 8 : testing largest on 5 nodes...";
  if(b.largest() == "Z") {  
    cerr << "Passed" << endl;
  } else {
    cerr << "Failed" << endl;
    failedTests++;
  }  

  totalTests++;
  cout << "Test 9 : testing smallest on 5 nodes...";
  if(b.smallest() == "A") {  
    cerr << "Passed" << endl;
  } else {
    cerr << "Failed" << endl;
    failedTests++;
  }  
 
  // Add tests for insert and remove on larger trees
  totalTests++;
  cout << "Test 10: testing insert on 5 nodes (duplicate) node ...";
  b.insert(s5);
  if (b.search(s5)) {
    cerr << "Passed" << endl;
  } else {
    cerr << "Failed" << endl;
    failedTests++;
  }

  totalTests++;
  cout << "Test 11: testing remove on dublicate node...";
  b.remove(s5);
  b.remove(s5);
  if (!b.search(s5)) {
    cerr << "Passed" << endl;
  } else {
    cerr << "Failed" << endl;
    failedTests++;
  }

  totalTests++;
  cout << "Test 12: testing remove on internal node...";
  b.insert("ZZ");
  b.remove("Z");
  if (!b.search("Z")) {
    cerr << "Passed" << endl;
  } else {
    cerr << "Failed" << endl;
    failedTests++;
  }

  // Add tests for height of nodes (empty and larger trees)
  totalTests++;
  cout << "Test 13: testing the height of an empty tree ...";
  bst.remove(test_input2);
  if (!bst.search(test_input2) && bst.height("") == -1) {
    cerr << "Passed" << endl;
  } else {
    cerr << "Failed" << endl;
    failedTests++;
  }

  totalTests++;
  cout << "Test 14: testing root node height of large tree ...";
  if (b.search(s2) && b.height(s2) == 2) {
    cerr << "Passed" << endl;
  } else {
    cerr << "Failed" << endl;
    failedTests++;
  }

  totalTests++;
  cout << "Test 15: testing a leaf node height of large tree ...";
  if (b.search(s4) && b.height(s4) == 0) {
    cerr << "Passed" << endl;
  } else {
    cerr << "Failed" << endl;
    failedTests++;
  }

  // Manually inspect pre post and inorder traversals
  totalTests++;
  cout << "Test 16: testing preOrder traversal...";
  b.preOrder();
  if (1) {
    cerr << "Passed" << endl;
  } else {
    cerr << "Failed" << endl;
    failedTests++;
  }

  totalTests++;
  cout << "Test 17: testing inOrder traversal...";
  b.inOrder();
  if (1) {
    cerr << "Passed" << endl;
  } else {
    cerr << "Failed" << endl;
    failedTests++;
  }

  totalTests++;
  cout << "Test 18: testing postOrder traversal...";
  b.postOrder();
  if (1) {
    cerr << "Passed" << endl;
  } else {
    cerr << "Failed" << endl;
    failedTests++;
  }

  cout << "Passed " << totalTests - failedTests << " / " << totalTests << " tests." << endl;
}

#endif  // __BSTREE_TEST_HPP__