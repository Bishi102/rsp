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
  treeNode<T>* root = nullptr;

  treeNode<T>* searchNode(treeNode<T>* current, T value) {
    if (current == nullptr) {
      return nullptr;
    }
    if (current->data == value) {
      return current;
    }
    if (value < current->data) {
      return searchNode(current->left, value);
    } else {
      return searchNode(current->right, value);
    }
  }

  void traverseNode(treeNode<T>* node) {
    // placement of processNode function determines traversal order
    if (node != nullptr) {
      // processNode(node); preorder
      traverseNode(node->left);
      processNode(node); // inorder
      traverseNode(node->right);
      // processNode(node); postorder
    }
  }
  void processNode(treeNode<T>* node) {
    std::cout << node->data << std::endl;
  }

  treeNode<T>* insertNode(treeNode<T>* node, T value) {
    if (node == nullptr) {
      return new treeNode<T>(value);
    }
    if (value < node->data) {
      node->left = insertNode(node->left, value);
    } else if (value > node->data) {
      node->right = insertNode(node->right, value);
    }
    return node;
  }

  treeNode<T>* findsuccessor(treeNode<T>* node) {
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
  }

  treeNode<T>*  deleteNode(treeNode<T>* node, T value) {
    if (node == nullptr) {
      return node;
    }
    if (value < node->data) {
      node->left = deleteNode(node->left, value);
    } else if (value > node->data) {
      node->right = deleteNode(node->right, value);
    } else {
      if (node->left == nullptr && node->right == nullptr) {
        delete node;
        return nullptr;
      }
      if (node->left == nullptr) {
        treeNode<T>* temp = node->right;
        delete node;
        return temp;
      } else if (node->right == nullptr) {
        treeNode<T>* temp = node->left;
        delete node;
        return temp;
      }
      treeNode<T>* temp = findsuccessor(node->right);
      node->data = temp->data;
      node->right = deleteNode(node->right, temp->data);
    }
    return node;
  }

public:
  
  treeNode<T>* searchTree(T value) {
    return searchNode(root, value);
  }

  void traverseTree() {
    traverseNode(root);
  }

  void insertTree(T value) {
    root = insertNode(root, value);
  }

  void deleteTree(T value) {
    root = deleteNode(root, value);
  }
  
};

int main() {
    binarySearchTree<int> bst;

    // Insert elements
    bst.insertTree(50);
    bst.insertTree(30);
    bst.insertTree(70);
    bst.insertTree(20);
    bst.insertTree(40);
    bst.insertTree(60);
    bst.insertTree(80);

    // Delete a node
    std::cout << "Deleting 50..." << std::endl;
    bst.deleteTree(50);

    // Traversals after deletion
    std::cout << "In-order traversal after deletion: ";
    bst.traverseTree();

    return 0;
}