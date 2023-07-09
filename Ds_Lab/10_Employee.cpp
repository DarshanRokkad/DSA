/*
Design a menu driven Program in C++ for the following operations on
Doubly Linked List (DLL) of Employee Data with the fields: SSN, Name, Dept,
Designation and salary. Perform the following operations.
a. Create a double linked list of employees data.
b. Insert a new employee to the left of the node whose key value (employee
name) is read as an input.
c. Delete a node with given data, if it is found. Otherwise display appropriate
error message
*/

#include <iostream>
using namespace std;

class node
{
private:
    string SSN, name, Dept, Designation;
    float salary;
    node *next;
    node *prev;
    friend class Employee;

public:
    node(string ssn, string n, string d, string des, float s)
    {
        SSN = ssn;
        name = n;
        Dept = d;
        Designation = des;
        salary = s;
        prev = next = NULL;
    }
};

class Employee
{
private:
    node *head;

public:
    Employee()
    {
        head = NULL;
    }

    node *createNode()
    {
        string ssn, name, dept, designation;
        float salary;
        cout << "Enter the employee details: " << endl;
        cout << "Name : ";
        cin >> name;
        cout << "SSN : ";
        cin >> ssn;
        cout << "Department : ";
        cin >> dept;
        cout << "Designation : ";
        cin >> designation;
        cout << "Salary : ";
        cin >> salary;
        node *temp = new node(ssn, name, dept, designation, salary);
        return temp;
    }

    void create()
    {
        cout << "Enter the details of frist employee." << endl;
        head = createNode();
        node *last = head;
        while (true)
        {
            cout << "Do you want to add employee \n(Enter 1 to add else enter 0 to delete) : " << endl;
            int flag;
            cin >> flag;
            if (flag)
            {
                node *temp = createNode();
                last->next = temp;
                temp->prev = last;
                last = temp;
            }
            else
            {
                break;
            }
        }
    }

    node *search(string name)
    {
        node *ans = NULL;
        node *p = head;
        while (p)
        {
            if (p->name == name)
            {
                ans = p;
                break ;
            }
            p = p->next;
        }
        return ans;
    }

    void insert_Employee()
    {
        node *temp = createNode();

        string na;
        cout << "Enter the name of the employee beside which new employee is to be added : ";
        getline(cin, na);
        getline(cin, na);
        node *p = search(na);
        if (p == NULL)
        {
            cout << "Employee beside who you need to insert is not present." << endl;
        }
        else
        {
            if (p == head)
            {
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
            else
            {
                temp->prev = p->prev;
                temp->next = p;
                p->prev->next = temp;
                p->prev = temp;
            }
        }
        display();
    }

    void delete_Employee()
    {
        if (head == NULL)
        {
            cout << "Underflow condition." << endl;
        }
        else
        {
            string na;
            cout << "Enter the name of the employee to be deleted from list : ";
            getline(cin, na);
            getline(cin, na);
            node *p = search(na);
            if (p == NULL)
            {
                cout << "Employee "<<na<<" is not present." << endl;
            }
            else
            {
                if (p == head)
                {
                    // if only one node in a list and if it is to be deleted
                    if (head->next == NULL)
                    {
                        delete head;
                        head = NULL;
                    }
                    // if we have more nodes but want to delete head
                    else
                    {
                        head = head->next;
                        delete (head->prev);
                        head->prev = NULL;
                    }
                }
                else
                {
                    // if p is the middle node
                    if (p->next && p->prev)
                    {
                        p->prev->next = p->next;
                        p->next->prev = p->prev;
                    }
                    // if p is last node
                    else
                    {
                        p->prev->next = NULL;
                    }
                    delete p;
                }
            }
            display();
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "No Employee list is present . " << endl;
        }
        else
        {
            cout << "** Doubly Linked list **" << endl;
            node *temp = head;
            cout << "Employee : ";
            while (temp)
            {
                cout << temp->name << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    cout << "** Employee doubly Linked list **" << endl;
    Employee e;
    while (true)
    {
        cout << endl;
        cout << "** Menu **" << endl;
        cout << "1. Create a employee list." << endl;
        cout << "2. Insert a new employee ." << endl;
        cout << "3. Delete a employee ." << endl;
        cout << "4. Display the employee list ." << endl;
        cout << "5. Exit ." << endl;
        cout << "Enter the choice : ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            e.create();
            break;
        case 2:
            e.insert_Employee();
            break;
        case 3:
            e.delete_Employee();
            break;
        case 4:
            e.display();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}