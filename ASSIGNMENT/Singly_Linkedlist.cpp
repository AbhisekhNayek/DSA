#include <iostream>
using namespace std;

class Node 
{
    public :
    int data;
    Node* next;
};

class LinkedList 
{
    public:
        Node* head;

        LinkedList()
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

void LinkedList :: insertAtBeginning(int value) 
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
    
  void LinkedList :: insertAtEnd(int value) 
  {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) 
        {
            head = newNode;
        } 
        else 
        {
            Node* current = head;
            while (current->next != NULL) 
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    
 void LinkedList :: insertAtLocation(int value, int location) 
 {
        Node* newNode = new Node;
        newNode->data = value;
        if (location == 1) 
        {
            newNode->next = head;
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
                current->next = newNode;
            } 
            else 
            {
                cout << "\nINVALID LOCATION !\n" << endl;
            }
        }
    }
    
    void LinkedList :: deleteFirstNode() 
    {
        if (head == NULL) 
        {
            cout << "\nLINKED LIST IS EMPTY\n" << endl;
        } 
        else 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            temp = NULL;
        }
    }
    
void LinkedList :: deleteLastNode() 
{
    if (head == NULL) 
    {
        cout << "\nLINKED LIST IS EMPTY\n" << endl;
    } 
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        Node* temp = head;
        while (temp->next->next != NULL) 
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}
    
void LinkedList :: deleteAtLocation(int location) 
{
        if (head == NULL) 
        {
            cout << "\nLINKED LIST IS EMPTY\n";
        } 
        else if (location == 1) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        } 
        else 
        {
            Node* current = head;
            for (int i = 1; i < location - 1 && current != NULL; i++) 
            {
                current = current->next;
            }
            if (current != NULL && current->next != NULL) 
            {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
            } 
            else 
            {
                cout << "\nINVALID LOCATION !\n" ;
            }
        }
    }

void LinkedList ::displayList() 
{
    if (head == NULL) 
    {
        cout << "\nLINKED LIST IS EMPTY\n" ;
    } 
    else 
    {
        Node* temp = head;
        while (temp != NULL) 
        {
            cout << temp->data << " ---> ";
            temp = temp->next;
        }
        cout <<"NULL"<<endl;
    }
}

int main() 
{
    LinkedList myList;
    int choice, value, location;
    do 
    { 
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
