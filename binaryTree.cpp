#include <iostream>

template <typename T>
struct treeNode {
  T data;
  treeNode<T>* left;
  treeNode<T>* right;
  treeNode(T value) {
    data = value;
    left = nullptr;
    right = nullptr;
  }
};

template <typename T>
class binarySearchTree {
  private:
  treeNode<T>* root;
  public:
};