#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;
};

class CircularLinkedList
{
public:
    Node* head;

    CircularLinkedList() 
    {
        head = NULL;
    }

    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAtLocation(int value, int location);

    void deleteFirstNode();
    void deleteLastNode();
    void deleteAtLocation(int location);

    void displayList();
};

void CircularLinkedList::insertAtBeginning(int value) 
{
    Node* newNode = new Node;
    newNode->data = value;
    if (head == NULL) 
    {
        newNode->next = newNode; 
    }
    else 
    {
        newNode->next = head;
        Node* current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    head = newNode;
}

void CircularLinkedList::insertAtEnd(int value) 
{
    Node* newNode = new Node;
    newNode->data = value;
    if (head == NULL) 
    {
        newNode->next = newNode; 
        head = newNode;
    }
    else 
    {
        Node* temp = head;
        while (temp->next != head) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void CircularLinkedList::insertAtLocation(int value, int location) 
{
    Node* newNode = new Node;
    newNode->data = value;
    if (location == 1) 
    {
        newNode->next = head;
        Node* temp = head;
        while (temp->next != head) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
        head = newNode;
    }
    else 
    {
        Node* temp = head;
        for (int i = 1; i < location - 1 && temp != NULL; i++) 
        {
            temp = temp->next;
        }
        if (temp != NULL) 
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else 
        {
            cout << "\nINVALID LOCATION !\n";
        }
    }
}

void CircularLinkedList::deleteFirstNode() 
{
    if (head == NULL) 
    {
        cout << "\nCIRCULAR LINKED LIST IS EMPTY\n";
    }
    else if (head->next == head) 
    { 
        delete head;
        head = NULL;
    }
    else 
    {
        Node* temp = head;
        Node* current = head;
        while (current->next != head) 
        {
            current = current->next;
        }
        head = head->next;
        current->next = head;
        delete temp;
    }
}

void CircularLinkedList::deleteLastNode() 
{
    if (head == NULL) 
    {
        cout << "\nCIRCULAR LINKED LIST IS EMPTY\n";
    }
    else if (head->next == head) 
    { 
        delete head;
        head = NULL;
    }
    else 
    {
        Node* temp = head;
        while (temp->next->next != head) 
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = head;
    }
}

void CircularLinkedList::deleteAtLocation(int location) 
{
    Node* temp = head;
    Node* prev = NULL;
    if (head == NULL) 
    {
       cout << "\nCIRCULAR LINKED LIST IS EMPTY\n";
       return;
    }
    if(location==1)
    {
        delete head;
        head = NULL;
        return;
    }
    for (int i = 1; i < location; i++) 
    {
        prev = temp;
        temp = temp->next;

        if (temp == NULL) 
        {
            cout << "\nINVALID LOCATION ! " << endl;
            return;
        }
    }
    if (prev == NULL) 
    {
        head = temp->next;
        delete temp;
        return;
    }
    if (temp->next == NULL) 
    {
        prev->next = NULL;
        delete temp;
        return;
    }
    prev->next = temp->next;
    delete temp;
}

void CircularLinkedList::displayList() 
{
    if (head == NULL) {
        cout << "\nCIRCULAR LINKED LIST IS EMPTY\n";
    } else {
        Node* temp = head;
        do {
            cout << temp->data << " ---> ";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD" << endl;
    }
}

int main() 
{
    CircularLinkedList myList;
    int ch, value, location;
    do 
    { 
        cout << "1. INSERT NODE AT BEGINING" << endl;
        cout << "2. INSERT NODE AT END" << endl;
        cout << "3. INSERT NODE AT ANY LOCATION" << endl;
        cout << "4. DELETE THE FIRST NODE" << endl;
        cout << "5. DELETE THE LAST NODE" << endl;
        cout << "6. DELETE ANY NODE AT ANY LOCATION" << endl;
        cout << "7. TRAVERSE THE LINKED LIST" << endl;
        cout << "8. EXIT" << endl;
        cout << "\nENTER THE CHOICE : " << endl;
        cin >> ch;

        switch(ch) 
        {
            case 1:
                cout << "\nENTER THE VALUE TO BE INSERTED : ";
                cin >> value;
                myList.insertAtBeginning(value);
                break;
            case 2:
                cout << "\nENTER THE VALUE TO BE INSERTED : ";
                cin >> value;
                myList.insertAtEnd(value);
                break;
            case 3:
                cout << "\nENTER THE VALUE TO BE INSERTED : ";
                cin >> value;
                cout << "ENTER THE LOCATION OF NODE : ";
                cin >> location;
                myList.insertAtLocation(value, location);
                break;
            case 4:
                myList.deleteFirstNode();
                break;
            case 5:
                myList.deleteLastNode();
                break;
            case 6:
                cout << "ENTER THE LOCATION OF NODE : ";
                cin >> location;
                myList.deleteAtLocation(location);
                break;
            case 7:
                cout<<"\nCIRCULAR LINKED LIST IS : \n";
                myList.displayList();
                break;
            case 8:
                cout << "ENDING..." << endl;
                break;
            default:
                cout << "WRONG INPUT ! PLEASE ENTER VALID INPUT" << endl;
        }
    } 
    while (ch != 8);
    return 0;
}

