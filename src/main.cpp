/*zyBooks: Chapter 4, Program 2.*/

#include <iostream>
#include <limits>
#include "node.cpp"
#include "binary_search_tree.cpp"
using namespace std;

void printOrders(BSTree *tree);
int menu(); 

int main( ) {
  system("rm -rf output_files");
  system("mkdir output_files");

  BSTree tree;
  int choice = menu();

  string entry;
  
  while (choice != 9) {
    if (choice == 1) {
      cout << "Enter string to insert: ";
      getline (cin, entry); 
      tree.insert(entry);

    } else if (choice == 2) {
      cout << "Enter string to remove: ";
      getline(cin, entry);
      tree.remove(entry);

    } else if (choice == 3) {
      printOrders(&tree);

    } else if (choice == 4) {
      cout << "Enter string to search for: ";
      getline(cin, entry);
      if( tree.search(entry) ) {
        cout << "Found.";
      } else {
        cout << "Not Found.";
      }

    } else if (choice == 5) {
      cout << "Smallest: " << tree.smallest(); 

    } else if (choice == 6) {
      cout << "Largest: " << tree.largest();

    } else if (choice == 7) {
      cout << "Enter string: ";
      getline(cin, entry);

      int height = tree.height(entry);

      if(height == -1) {
        cout << "String '" << entry 
          << "' is not in the BStree.";
      } else {
        cout << "Height of subtree rooted at '"
          << entry << "': "
          << tree.height(entry);
      }
    } else if (choice == 8) {
      tree.visualize_tree("./output_files/my_tree");
      system("code ./output_files/my_tree.jpg");
    }
    cout << endl;

    choice = menu();
  }
  return 0;
}

void printOrders(BSTree *tree) {
  cout << "Preorder = ";
  tree->preOrder( );
  cout << "Inorder = ";
  tree->inOrder( );
  cout << "Postorder = ";
  tree->postOrder( );
}

int menu() {
  int choice = 0;
  
  cout 
    << endl 
    << "1. Insert"   << endl
    << "2. Remove"   << endl
    << "3. Print"    << endl
    << "4. Search"   << endl
    << "5. Smallest" << endl
    << "6. Largest"  << endl
    << "7. Height"   << endl
    << "8. Visualize"<< endl
    << "9. Quit"     << endl
    << "Enter menu choice: ";
  cin >> choice;
  
  // fix buffer just in case non-numeric choice entered
  // also gets rid of newline character
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return choice;
}