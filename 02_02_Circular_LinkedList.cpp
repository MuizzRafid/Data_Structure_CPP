
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = this;
        prev = this;
    }
};

class CircularDoublyLinkedList {
private:
    Node* head;

public:
    CircularDoublyLinkedList() {
        head = nullptr;
    }

    // C: Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* tail = head->prev;

        newNode->next = head;
        newNode->prev = tail;

        tail->next = newNode;
        head->prev = newNode;

        head = newNode;
    }

    // C: Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* tail = head->prev;

        newNode->prev = tail;
        newNode->next = head;

        tail->next = newNode;
        head->prev = newNode;
    }

    // C: Insert at a 1-based position
    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Invalid position!\n";
            return;
        }

        if (position == 1) {
            insertAtBeginning(value);
            return;
        }

        if (head == nullptr) {
            cout << "Invalid position!\n";
            return;
        }

        Node* current = head;

        for (int i = 1; i < position - 1; i++) {
            current = current->next;

            if (current == head) {
                cout << "Invalid position!\n";
                return;
            }
        }

        Node* newNode = new Node(value);
        Node* nextNode = current->next;

        newNode->prev = current;
        newNode->next = nextNode;

        current->next = newNode;
        nextNode->prev = newNode;
    }

    // R: Display forward
    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* current = head;

        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);

        cout << '\n';
    }

    // R: Display backward
    void displayBackward() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* tail = head->prev;
        Node* current = tail;

        do {
            cout << current->data << " ";
            current = current->prev;
        } while (current != tail);

        cout << '\n';
    }

    // R: Search for a value
    void search(int value) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* current = head;
        int position = 1;

        do {
            if (current->data == value) {
                cout << "Found at position "
                     << position << '\n';
                return;
            }

            current = current->next;
            position++;
        } while (current != head);

        cout << "Value not found!\n";
    }

    // U: Update the first matching value
    void update(int oldValue, int newValue) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* current = head;

        do {
            if (current->data == oldValue) {
                current->data = newValue;
                cout << "Value updated successfully!\n";
                return;
            }

            current = current->next;
        } while (current != head);

        cout << "Value not found!\n";
    }

    // D: Delete the first matching value
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* current = head;

        do {
            if (current->data == value) {
                // Only one node
                if (current->next == current) {
                    delete current;
                    head = nullptr;
                    cout << "Node deleted!\n";
                    return;
                }

                // Reconnect neighboring nodes
                current->prev->next = current->next;
                current->next->prev = current->prev;

                // If deleting the head, move head forward
                if (current == head) {
                    head = current->next;
                }

                delete current;
                cout << "Node deleted!\n";
                return;
            }

            current = current->next;
        } while (current != head);

        cout << "Value not found!\n";
    }

    // D: Delete by a 1-based position
    void deleteAtPosition(int position) {
        if (head == nullptr || position < 1) {
            cout << "Invalid position or empty list!\n";
            return;
        }

        Node* current = head;

        for (int i = 1; i < position; i++) {
            current = current->next;

            if (current == head) {
                cout << "Invalid position!\n";
                return;
            }
        }

        // Only one node
        if (current->next == current) {
            delete current;
            head = nullptr;
            cout << "Node deleted!\n";
            return;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;

        if (current == head) {
            head = current->next;
        }

        delete current;
        cout << "Node deleted!\n";
    }

    // Release all dynamically allocated nodes
    ~CircularDoublyLinkedList() {
        if (head == nullptr) {
            return;
        }

        Node* current = head->next;

        while (current != head) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }

        delete head;
        head = nullptr;
    }
};

int main() {
    CircularDoublyLinkedList list;

    int choice, value, oldValue, newValue, position;

    do {
        cout << "\n===== Circular Doubly Linked List =====\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Display forward\n";
        cout << "5. Display backward\n";
        cout << "6. Search\n";
        cout << "7. Update\n";
        cout << "8. Delete by value\n";
        cout << "9. Delete at position\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            break;
        }

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;

            case 3:
                cout << "Enter value and position: ";
                cin >> value >> position;
                list.insertAtPosition(value, position);
                break;

            case 4:
                list.displayForward();
                break;

            case 5:
                list.displayBackward();
                break;

            case 6:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;

            case 7:
                cout << "Enter old and new values: ";
                cin >> oldValue >> newValue;
                list.update(oldValue, newValue);
                break;

            case 8:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteByValue(value);
                break;

            case 9:
                cout << "Enter position to delete: ";
                cin >> position;
                list.deleteAtPosition(position);
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
```