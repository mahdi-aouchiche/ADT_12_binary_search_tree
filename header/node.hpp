#ifndef __NODE_HPP__
#define __NODE_HPP__

#include <string>
using namespace std;

class Node {
  private:
    Node* left;       // node's left child pointer 
    Node* right;      // node's right child pointer 
    string str;       // holds data
    int count;        // holds the count of nodes in the tree 
    unsigned ID;      // holds the nodes ID to visualize the BST
  
  public:
    // Constructor 
    Node();

    /* setters  */
    void setStr(string );         
    void setCount(int );
    void setLeftChild(Node * );
    void setRightChild(Node * );
    void setNodeID(unsigned );

    /* getters */
    string getStr() const;
    int getCount() const;
    Node* getLeftChild() const;
    Node* getRightChild() const;
    unsigned getNodeID() const; 
};

#endif // __NODE_HPP__