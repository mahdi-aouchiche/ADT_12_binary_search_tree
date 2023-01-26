#include "../header/binary_search_tree.hpp"

BSTree::BSTree() {
  root = nullptr;
  this->ID = 0;
}

BSTree::~BSTree() {
  this->treeNode(root);
}

/*Used by the Destructor*/
void BSTree::treeNode(Node *node) {
  if(node == nullptr) {
    return;
  }

  treeNode(node->getLeftChild());  // go to the left node
  treeNode(node->getRightChild()); // go to the right node
  delete node; 
}

void BSTree::insert(const string &newString) {
  if(newString == "") {
    cout << "Cannot insert an empty string." << endl;
    return;
  }

  // create a Node with the inserted string
  Node *newNode = new Node();
  newNode->setStr(newString);
  newNode->setCount(1);
 
  // Insert the Node
  if(this->root == nullptr) {   // insert to an empty list
    newNode->setNodeID(this->ID++);
    this->root = newNode;
  } else {  // insert to a non empty list 
    Node *curr = this->root;   // start from the root 
    
    // go through the list to insert in the appropriate location
    // starting from the root 
    while (curr != nullptr) {

      // the newNode is a dublicate 
      if(curr->getStr() == newString ) {
        // increment count
        curr->setCount(curr->getCount() + 1);  
        
        // delete newNode
        delete newNode;

        // done with insertion 
        return; 

      } else if (curr->getStr() < newString ) { // go to the right subtree
        
        // if the right subtree is empty insert node, else update curr
        if(curr->getRightChild() == nullptr ) {
          newNode->setNodeID(this->ID++);
          curr->setRightChild(newNode);           
          return;   // done with insertion  
        } else {
          curr = curr->getRightChild(); 
        }

      } else {  // go to the left subtree

        // if the left subtrr is empty, insert node else update curr
        if(curr->getLeftChild() == nullptr ) {
          newNode->setNodeID(this->ID++);
          curr->setLeftChild(newNode);  
          return;   // done with insertion  
        } else {
          curr = curr->getLeftChild(); 
        }
      }
    }
  }
}

void  BSTree::remove(const string &key) { 
  if(!this->root) {
    cout << "BST is empty." << endl;
    return;
  }

  Node *parent = nullptr;         // parent of curr node 
  Node *curr   = this->root;      // curr node 
    
  while(curr != nullptr) {        // search for node 
        
    if( curr->getStr() == key) {          // Node found, 

      if(curr->getCount() > 1){                                     // string is a dublicate 
        curr->setCount(curr->getCount() - 1);  // decrement count 
        return;  // done  

      } else if (!curr->getLeftChild() && !curr->getRightChild()){  // remove leaf
        if(parent == nullptr) {                       // node is the root 
          this->root = nullptr;     // update root to null 
        } else if ( parent->getLeftChild() == curr) { // node is the left child
          parent->setLeftChild(nullptr);  // set nodes parent left child to null
        } else {                                      // node is the right leaf
          parent->setRightChild(nullptr); // set nodes parent right child to null     
        }
        delete curr; 
        curr = nullptr;     // done removing node 

      } else if (!curr->getLeftChild() && curr->getRightChild()) {  // remove node with only a right child  
        // find a successor from the left subtree
        Node *successor = smallest(curr->getRightChild());

        // save successor's date 
        string successorStr = successor->getStr();
        int successorCount  = successor->getCount(); 

        // set successor count to 1
        successor->setCount(1);

        // remove successor 
        remove(successorStr) ; 

        // copy successor data to curr Node  
        curr->setCount(successorCount);
        curr->setStr(successorStr);
                             

      } else if (curr->getLeftChild()) {                            // remove node with a left child,
               
        // find a successor from the left subtree
        Node *successor = largest(curr->getLeftChild());

        // save successor's date 
        string successorStr = successor->getStr();
        int successorCount  = successor->getCount(); 

        // set successor count to 1
        successor->setCount(1);

        // remove successor 
        remove(successorStr) ; 

        // copy successor data to curr Node  
        curr->setCount(successorCount);
        curr->setStr(successorStr); 
      }
    } else if ( curr->getStr() < key ) {  // search the right tree  
      parent = curr;
      curr   = curr->getRightChild();
    } else {                              // search the left tree 
      parent = curr;
      curr   = curr->getLeftChild();           
    }
  }
}

bool BSTree::search(const string &key) const {
  Node *currNode = this->root;
  int diff;   
  
  while(currNode != nullptr) {
    diff = key.compare(currNode->getStr()); 
    if(diff == 0) {
      return true;
    } else if (diff < 0) {
      currNode = currNode->getLeftChild(); 
    } else {
      currNode = currNode->getRightChild();
    }
  }
  return false;
}
   
string BSTree::largest() const {  
  if(!this->root) {
    return "";
  }
  return largest(this->root)->getStr();  
}

/* 
  Return a node with the largest string in a subtree
  used by largest and remove functions. 
*/
Node* BSTree::largest(Node* node) const {      
  if(node == nullptr) {
    return nullptr;
  }

  Node *currNode = node;
  while (currNode->getRightChild() != nullptr) {
    currNode = currNode->getRightChild(); 
  }
  return currNode; 
}
  
string BSTree::smallest() const {  
  if(!this->root) {
    return "";
  } 
  return smallest(this->root)->getStr(); 
}

/* 
  Return a node with the smallest string in a subtree
  used by smallest and remove functions
*/
Node* BSTree::smallest(Node* node) const {      
  if(node == nullptr) {
    return nullptr;
  }

  Node *currNode = node;
  while (currNode->getLeftChild() != nullptr) {
    currNode = currNode->getLeftChild(); 
  }
  return currNode; 
}
 
int BSTree::height(const string& s) const { 
  Node* curr = this->root; 
  while(curr) {
    if(s < curr->getStr()) {
      curr = curr->getLeftChild();
    } else if(s > curr->getStr()) {
      curr = curr->getRightChild();
    } else {
      return BSTGetHeight(curr);
    }
  }
  // string not found 
  return -1; 
}

/* used by height function to return the height of a node*/
int BSTree::BSTGetHeight(Node *node) const {
  if( node == nullptr) {
    return -1;
  } 
  
  int leftHeight  = BSTGetHeight(node->getLeftChild());
  int rightHeight = BSTGetHeight(node->getRightChild());

  return max(leftHeight, rightHeight) + 1; 
} 

void BSTree::preOrder() const {
  this->preOrder(root);
  cout << endl;
}

/* preOrder Recursive helper function */
void BSTree::preOrder(Node *node) const { 
  if(node == nullptr) {
    return;
  }
  
  // print the node's string
  cout                            
    << node->getStr()   << "("
    << node->getCount() << "), ";
  
  // go to the left node
  preOrder(node->getLeftChild());  
  // go to the right node
  preOrder(node->getRightChild()); 
}

void BSTree::postOrder() const {
  this->postOrder(root);
  cout << endl;
}

/* postOrder Recursive helper function */
void BSTree::postOrder(Node *node) const { 
  if(node == nullptr) {
    return;
  }

  // go to the left node
  postOrder(node->getLeftChild());  
  // go to the right node
  postOrder(node->getRightChild());
  // print the node's string 
  cout                             
    << node->getStr() << "("
    << node->getCount() << "), ";
}

void BSTree::inOrder() const {
  this->inOrder(root);
  cout << endl;
}

/* inOrder Recursive helper function */
void BSTree::inOrder(Node *node) const { 
  if(node == nullptr) {
    return;
  }

  // go to the left node  
  inOrder(node->getLeftChild());  

  // print the node's string 
  cout                                 
    << node->getStr()   << "(" 
    << node->getCount() << "), ";  
  
  // go to the right node
  inOrder(node->getRightChild());           
}

void BSTree::visualize_tree(const string &outputFilename) {
  ofstream outFS(outputFilename.c_str());
  if(!outFS.is_open()){
    cout << "Error opening "<< outputFilename << endl;
    return;
  }

  outFS << "/* If you do not have graphviz program installed: " << endl; 
  outFS << " Use webgraphviz.com to display the visualizeTree." << endl; 
  outFS << " Copy the content of the .dot files generated, "    << endl;
  outFS << " and paste the digraph function to see the graph."  << endl;
  outFS << "*/ " << endl << endl;
  
  outFS << "digraph G {" << endl;
  // output the nodes 
  outFS << "  // nodes:" << endl;
  if(this->root != nullptr) {
    this->visualize_nodes(outFS,this->root);
  }
  // output the edges 
  outFS << "  // edges:" << endl;
  if(this->root != nullptr) {
    this->visualize_tree(outFS,this->root);
  }  
  outFS << "}";

  outFS.close();

  try
  {
    string jpgFilename = outputFilename.substr(0,outputFilename.size())+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    cout << "The \"sh: 1: dot not found\" exception results from missing graphviz program which displays the AVL tree graphs." << endl; 
    cout << "Try installing graphviz using the command: sudo apt-get install graphviz" <<endl;
  }
}

void BSTree::visualize_tree(ofstream &outFS, Node* node) {
  if(!node) {
    return;
  }

  if(node->getLeftChild()) {
    visualize_tree( outFS, node->getLeftChild() );
    outFS 
      << "  "
      << node->getNodeID() << " -> " 
      << node->getLeftChild()->getNodeID() 
      << ";" << endl
    ;    
  }

  if(node->getRightChild()) {
    visualize_tree( outFS, node->getRightChild() );
    outFS 
      << "  "
      << node->getNodeID() << " -> " 
      << node->getRightChild()->getNodeID() 
      << ";" << endl
    ;    
  }
}

void BSTree::visualize_nodes(ofstream &outputfile, Node* node) {
  if(!node) { 
    return; 
  } 
  /* Write the nodes in postfix */
  visualize_nodes(outputfile, node->getLeftChild());
  visualize_nodes(outputfile, node->getRightChild());
  
  outputfile << "  " << node->getNodeID();  
  outputfile << " [shape=circle, color=lightblue, peripheries=2, style=filled, label=\""; 
  outputfile << node->getStr() << "\\n(" << node->getCount() << ")\"]" << endl; 
}
