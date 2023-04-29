#include <iostream>
#include <string>
using namespace std;

class Student 
{
public:
    int reg_no;
    string name;
    string branch;
    double cgpa;
    
    Student() 
    {
        reg_no = 0;
        name = "";
        branch = "";
        cgpa = 0.0;
    }
    
    Student(int reg_no, string name, string branch, double cgpa) 
    {
        this->reg_no = reg_no;
        this->name = name;
        this->branch = branch;
        this->cgpa = cgpa;
    }
};


void linear_search(Student arr[], int n, int reg_no) 
{
    int i;
    for(i = 0; i < n; i++) 
    {
        if(arr[i].reg_no == reg_no) 
        {
            cout << "\nREGISTRATION NO.: " << arr[i].reg_no << endl;
            cout << "\nNAME : " << arr[i].name << endl;
            cout << "\nBRANCH : " << arr[i].branch << endl;
            cout << "\nCGPA : " << arr[i].cgpa << endl;
            return;
        }
    }
    cout << "\nSTUDENT WITH REGISTRATION NO. " << reg_no << " IS NOT FOUND." << endl;
}

int main() 
{
    
    int n;
    cout << "\nENTER THE NUMBER OF STUDENTS : ";
    cin >> n;
    
    Student arr[n];
    for(int i = 0; i < n; i++) 
    {
        int reg_no;
        string name, branch;
        double cgpa;
        cout << "\nENTER THE REGISTRATION NO : ";
        cin>>reg_no;
        cout << "\nENTER THE NAME : ";
        cin>>name;
        cout << "\nENTER THE BRANCH : ";
        cin>>branch;
        cout << "\nENTER THE CGPA : ";
        cin>>cgpa;
        arr[i] = Student(reg_no, name, branch, cgpa);
    }
    
    int reg_no;
    cout << "\nENTER THE REGISTRATION NO YOU WANT TO FIND : ";
    cin >> reg_no;
    
    linear_search(arr, n, reg_no);
    
    return 0;
}
