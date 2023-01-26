#include "../header/node.hpp"

Node::Node() {
  this->left  = nullptr;
  this->right = nullptr; 
  this->str   = "";
  this->count = 0; 
  this->ID    = 0;
}

void Node::setStr(string str) {
  this->str = str;
}

void Node::setCount(int count) {
  this->count = count;
}

void Node::setLeftChild(Node * leftNode) {
  this->left =  leftNode; 
}

void Node::setRightChild(Node * rightNode) {
  this->right =  rightNode;
}

void Node::setNodeID(unsigned id) {
  this->ID = id;
}

string Node::getStr() const {
  return this->str;
}

int Node::getCount() const {
  return this->count;
}

Node* Node::getLeftChild() const {
  return this->left;
}

Node* Node::getRightChild() const {
  return this->right; 
}

unsigned Node::getNodeID() const {
  return this->ID;
}
