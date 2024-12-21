#include <iostream>
using namespace std;

template <typename T>
struct Node
{
  T data;
  Node* next;
  Node(T value) {
    data = value;
    next = nullptr;
  }
};

template <typename T>
class linkedList {
  private: 
  Node<T>* head;

  public:
  linkedList() {
    head = nullptr;
  }

  ~linkedList() {
    Node<T>* current = head;
    while (current) {
      Node<T>* nextNode = current->next;
      delete current;
      current = nextNode;
    }
  }

  Node<T>* searchNode(T value) {
    Node<T>* current = head;
    while (current != nullptr) {
      if (current->data == value) {
        return current;
      }
      current = current->next;
    }
    return nullptr;
  }

  Node<T>* searchPredecessor(T value) {
    Node<T>* current = head;
    while (current != nullptr) {
      if ((current->next)->data == value) {
        return current;
      }
      current = current->next;
    }
    return nullptr;
  }

  void insertNode(T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
  }

  void deleteNode(T value) {
    if (head != nullptr && head->data == value) {
      Node<T>* toDelete = head;
      head = head->next;
      delete toDelete;
      return;

    }
    Node<T>* pred = searchPredecessor(value);
    if (pred != nullptr) {
      Node<T>* toDelete = pred->next;
      pred->next = (pred->next)->next;
      delete toDelete;
    }
  }
};

int main() {
    linkedList<int> list;

    list.insertNode(10);
    list.insertNode(20);
    list.insertNode(7000);
    list.insertNode(45);
    list.insertNode(100);
    list.insertNode(2);

    Node<int>* found = list.searchNode(100);
    if (found) {
        cout << "Node found with value: " << found->data << endl;
    } else {
        cout << "Node not found" << endl;
    }

    list.deleteNode(20);

    found = list.searchNode(20);
    if (found) {
        cout << "Node found with value: " << found->data << endl;
    } else {
        cout << "Node not found" << endl;
    }

    // expected output:
    // Node found with value: 100
    // Node not found
    return 0;
}