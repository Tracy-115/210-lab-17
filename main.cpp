#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *hd);
void addFront(Node* &head, float value);
void deleteNode(Node* &head, int posit);
void insertNode(Node* &head, int posit, float value);
void deleteList(Node* &head);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        addFront(head, tmp_val);
    }
    output(head);

    

    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // delete that node
    deleteNode(head, entry); 
    cout << "After deleting:\n";
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    insertNode(head, entry, 10000);
    cout << "After insertion:\n";
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);

    return 0;
}
void addFront(Node* &head, float value) {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    head = newNode;
}
void addBack(Node* &head, float value) {
    Node *newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node *current = head;
    while (current->next) current = current->next;
    current->next = newNode;
}
void insertNode(Node* &head, int posit, float value) {
    if (!head || posit < 1) return;

    Node *current = head;
    for (int i = 1; i < posit && current; i++) {
        current = current->next;
    }
    if (current) {
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = current->next;
        current->next = newNode;
    }
}
void deleteList(Node*& head){
    Node* current = head;
    while (current) {
      Node* tmp = current ->next;
      delete current;
      current = tmp;
    }
    head = nullptr;
}
void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}
