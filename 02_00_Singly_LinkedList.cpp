
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

// Insert a new node at the end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};


    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

   
    temp->next = newNode;
}

bool modifyNode(Node* head, int oldValue, int newValue) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            return true;
        }

        temp = temp->next;
    }

    return false; 
}


void printList(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " - ";
        temp = temp->next;
    }

}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = new Node{10, nullptr};
    head->next = new Node{20, nullptr};
    head->next->next = new Node{30, nullptr};

    cout << "Original list: ";
    printList(head);

  
    insertAtEnd(head, 40);

    cout << "After insertion: ";
    printList(head);

    
    if (modifyNode(head, 20, 25)) {
        cout << "After modification: ";
        printList(head);
    } else {
        cout << "Value not found!" << endl;
    }

 
    deleteList(head);

    return 0;
}