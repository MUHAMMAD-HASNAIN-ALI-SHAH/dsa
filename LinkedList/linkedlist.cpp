#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }

    ~Node()
    {
        if (next != nullptr)
        {
            delete next;
            next = nullptr;
        }
    }
};

class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = nullptr;
        tail = nullptr;
    }

    ~List()
    {
        if (head != nullptr)
        {
            delete head;
            head = nullptr;
        }
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void insert(int val, int pos)
    {
        Node *newNode = new Node(val);

        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "Empty ll";
            return;
        }
        Node *temp = head;
        head = head->next;

        temp->next = nullptr;
        delete temp;
    }

    void pop_end()
    {
        if (tail == nullptr)
        {
            cout << "Empty ll";
            return;
        }
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
        delete tail;
        tail = temp;
    }

    int iterativeSearch(int key)
    {
        Node *temp = head;
        int idx = 0;
        while (temp->next != nullptr)
        {
            if (temp->data == key)
            {
                return idx;
            }

            temp = temp->next;
            idx++;
        }
    }

    int recursiveSearch(int key)
    {
    }

    // size - n + 1
    int findAndRemoveNthNodeFromEnd(int node)
    {
        Node *tempIdx = head;
        int size = 0;
        while (tempIdx != nullptr)
        {
            size++;
            tempIdx = tempIdx->next;
        }

        int nodePosi = size - node +1;
        int prevNodePosi = nodePosi -1;

        Node *temp = head;
        for (int i = 1; i < prevNodePosi; i++)
        {
            temp = temp->next;
        }

        Node *del = temp->next;
        temp->next = del->next;
        del->next = nullptr;
        delete del;

        return 1;
    }
};

int main()
{
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.findAndRemoveNthNodeFromEnd(3);
    ll.printList();
    return 0;
}
