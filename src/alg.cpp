// Copyright 2021 NNTU-CS
#ifndef TPQUEUE_H
#define TPQUEUE_H

struct SYM {
    char chc;
    int prioritet;
};

template<typename T>
class TPQueue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    TPQueue() : head(nullptr) {}
    ~TPQueue() {
        while (head != nullptr) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

void push(const T& item) {
        Node* nNode = new Node(item);
if (item.prior > head->data.prior) {
            nNode->next = head;
            head = nNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->data.prior >= item.prior) {
                current = current->next;
            }
            nNode->next = current->next;
            current->next = nNode;
        }
    }

T pop() {
      Node* temp = head;
      T result = head->data;
      head = head->next;
      delete temp;
      return result;
    }
};

#endif // TPQUEUE_H 
