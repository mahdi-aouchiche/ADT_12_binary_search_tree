# Abstact Data Types : Binary Search Tree (BST)

Author: Mahdi Aouchiche (<https://github.com/mahdi-aouchiche/ADT_12_binary_search_tree>)

* Build a Binary Search Tree (BST).
* BST user interface allows to:
  * Insert   : inserts a string. dublicates are accepted by increasing the count of occurences.
  * Remove   : deletes a string from the tree if it is present.
  * Print    : prints the BST in 3 different ways (Preorder, Inorder, Postorder).
  * Search   : searches for a specific string if it exists in the tree or not.
  * Smallest : displays the smallest string in the BST.
  * Largest  : displays the largest string in the BST.
  * Height   : displays the height of a given string in the tree.
  * Visualize: display a visual of the BST.

> Notes: The BST is written to a ".dot" file as a graph in 'output_files' folder. Graphviz program uses the the generated ".dot" file to display the BST tree as a 'jpg' image.
If the graphviz program is not installed or not installed correctly. Copy the ".dot" file and paste it on [webgraphviz][graphviz] to see the BST tree visualization.

## To run the project nicely run the following commands

```c++
cmake -S . -B build
cmake --build build/ 
```

## 2 executables are created, use the following command to run an executable

```c++
// to build a BST
./build/bstree

// run the test harness
./build/run_tests
```

[graphviz]: http://www.webgraphviz.com/
