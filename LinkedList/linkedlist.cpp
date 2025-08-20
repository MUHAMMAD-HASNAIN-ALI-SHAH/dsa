#include<iostream>;
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(val) {
            data = val;
            next = null;
        }
}

class List {
    public:
        Node* head;
        Node* tail;

        List() {
            head = null;
            tail = null;
        }

        void push_front(val) {
            Node* newNode = new Node(val)
            if(head == null){
                head = tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
        }

        void push_back(val) {
            Node* newNode = new Node(val)
            if(head == null){
                head = tail = newNode;
            } else {
                tail->next = newNode
                tail = newNode
            }
        }

        void printList(){
            Node* temp = head;
             while(temp!=null){
                count<<temp->data<< " -> ";
                temp = temp->next'
             }
        }
}

int main() {
    List ll();
    ll.push_front(3)
    ll.push_front(2)
    ll.push_front(1)

    ll.printList();
}