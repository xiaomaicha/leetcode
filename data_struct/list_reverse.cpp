//
// Created by Administrator on 2019/8/13.
//

#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int data;
  Node *next;
  explicit Node(int data) : data(data), next(nullptr) {}
};

void list_reverse(Node **head) {
  if (*head == nullptr || (*head)->next == nullptr)
    return;
  Node *p1 = *head, *p2 = (*head)->next, *p3 = nullptr;
  while (p2 != nullptr) {
    p3 = p2->next;
    p2->next = p1;
    p1 = p2;
    p2 = p3;
  }
  (*head)->next = nullptr;
  (*head) = p1;
}

int main(int argc, char **argv) {
  Node *head = new Node(5);
  Node *l1 = new Node(4);
  Node *l2 = new Node(6);
  Node *l3 = new Node(1);
  Node *l4 = new Node(2);
  head->next = l1;
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;

  {
    cout << "----original----" << endl;
    Node *temp = head;
    while (temp) {
      cout << temp->data << ",";;
      temp = temp->next;
    }
    cout << endl;
  }

  {
    cout << "----reverse----" << endl;
    list_reverse(&head);
    Node *temp = head;
    while (temp) {
      cout << temp->data << ",";;
      temp = temp->next;
    }
    cout << endl;
  }

  return EXIT_SUCCESS;
}