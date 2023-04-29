#include <iostream>
using namespace std;

class Node 
{
    public :
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList 
{
    public:
        Node* head;
        Node* tail;

        DoublyLinkedList ()
        {
            head = NULL;
            tail = NULL;
        }

        void insertAtBeginning(int value);
        void insertAtEnd(int value);
        void insertAtLocation(int value, int location);

        void deleteFirstNode();
        void deleteLastNode();
        void deleteAtLocation(int location);

        void displayList();
};

void DoublyLinkedList  :: insertAtBeginning(int value) 
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head == NULL) 
    {
        tail = newNode;
    }
    else 
    {
        head->prev = newNode;
    }
    head = newNode;
}

void DoublyLinkedList  :: insertAtEnd(int value) 
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) 
    {
        newNode->prev = NULL;
        head = newNode;
        tail = newNode;
    } 
    else 
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void DoublyLinkedList  :: insertAtLocation(int value, int location) 
{
    Node* newNode = new Node;
    newNode->data = value;
    if (location == 1) 
    {
        newNode->prev = NULL;
        newNode->next = head;
        if (head == NULL) 
        {
            tail = newNode;
        }
        else 
        {
            head->prev = newNode;
        }
        head = newNode;
    } 
    else 
    {
        Node* current = head;
        for (int i = 1; i < location - 1 && current != NULL; i++) 
        {
            current = current->next;
        }
        if (current != NULL) 
        {
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next == NULL) 
            {
                tail = newNode;
            }
            else 
            {
                current->next->prev = newNode;
            }
            current->next = newNode;
        } 
        else 
        {
            cout << "\nINVALID LOCATION !\n" << endl;
        }
    }
}

void DoublyLinkedList ::deleteFirstNode() 
{
    if(head == NULL) 
    {
        cout << "\nDOUBLY LINKED LIST IS EMPTY!\n";
    }
    else if(head == tail) 
    {
        delete head;
        head = tail = NULL;
    }
    else 
    {
        head = head->next;
        delete head->prev;
        head->prev = NULL;
    }
}

void DoublyLinkedList ::deleteLastNode() 
{
    if(head == NULL) 
    {
        cout << "\nDOUBLY LINKED LIST IS EMPTY!\n";
    }
    else if(head == tail) 
    {
        delete head;
        head = tail = NULL;
    }
    else 
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = NULL;
    }
}

void DoublyLinkedList ::deleteAtLocation(int location) 
{
    if(head == NULL) 
    {
        cout << "\nDOUBLY LINKED LIST IS EMPTY!\n";
    }
    else if(location == 1) 
    {
        deleteFirstNode();
    }
    else 
    {
        Node* temp = head;
        for(int i = 1; i < location && temp != NULL; i++) 
        {
            temp = temp->next;
        }
        if(temp == NULL) 
        {
            cout << "\nINVALID LOCATION !\n";
        }
        else if(temp == tail) 
        {
            deleteLastNode();
        }
        else 
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }
}

void DoublyLinkedList ::displayList() 
{
    Node* temp = head;
    
    if(head == NULL)
    {
        cout<<"\nDOUBLY LINKED LIST IS EMPTY ! \n";
        return;
    }
    while (temp != NULL) 
    {
        cout << temp->data << " <---> ";
        temp = temp->next;
    }
    cout << "NULL"<<endl;
}

int main() 
{
    DoublyLinkedList myList;
    int choice, value, location;
    do 
    { 
        cout<<"\n--- DOUBLY LINKED LIST ---\n";
        cout << "1. INSERT AT BEGINING" << endl;
        cout << "2. INSERT AT END" << endl;
        cout << "3. INSERT AT ANY LOCATION" << endl;
        cout << "4. DELETE FIRST NODE" << endl;
        cout << "5. DELETE LAST NODE" << endl;
        cout << "6. DELETE ANY NODE AT ANY LOCATION" << endl;
        cout << "7. TRAVERSE THE LINKED LIST" << endl;
        cout << "8. EXIT" << endl;
        cout << "\nENTER YOUR CHOICE : " << endl;
        cin >> choice;

        switch(choice) 
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
                cout<<"\nLINKED LIST IS : \n";
                myList.displayList();
                break;
            case 8:
                cout << "ENDING..." << endl;
                break;
            default:
                cout << "WRONG INPUT ! PLEASE ENTER VALID INPUT" << endl;
        }
    } 
    while (choice != 8);
    return 0;
}


