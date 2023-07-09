// Stack operation on the books
#include <iostream>
using namespace std;

class Book
{
private:
    string Isbn;
    string title;
    string author;
    float price;

public:

    // for Taking input to set book object data members
    void input()
    {
        cout<<"Enter book details.."<<endl;
        cout << "Enter the ISBN of the book : ";
        getline(cin,Isbn);
        getline(cin,Isbn);
        cout << "Enter the Title of the book : ";
        getline(cin,title);
        cout << "Enter the Author of the book : ";
        getline(cin,author);
        cout << "Enter the Price of the book : ";
        cin >> price;
    }

    // for Displaying information of book
    void Display()
    {
        // to check the book is empty or not
        if (Isbn != "")
        {
            cout << "ISBN : " << Isbn << endl;
            cout << "Title : " << title << endl;
            cout << "Author : " << author << endl;
            cout << "Price : " << price << endl;
        }
    }
};

class Stack_books
{
private:
    int top;
    int Capacity;
    Book *B;

public:
    Stack_books(int n)
    {
        Capacity = n;
        top = -1;
        B = new Book[n];
    }

    // Pushing book to stack
    void push(Book nb)
    {
        if (top == (Capacity - 1))
        {
            cout << "Overflow condition." << endl;
        }
        else
        {
            B[++top] = nb;
            cout << "Book is pushed to stack successfully." << endl;
        }
    }

    // Poping book from stack
    Book pop()
    {
        if (top == -1)
        {
            cout << "Underflow condition." << endl;
            Book n;
            return n;
        }
        else
        {
            cout << "Book is poped from stack successfully." << endl;
            return B[top--];
        }
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty.." << endl;
        }
        else
        {
            cout << "Stack" << endl;
            for (int i = top; i >= 0; i--)
            {
                cout << "Book " << (i + 1) << endl;
            }
        }
    }
};

int main()
{
    cout << "*** Stack on books ***" << endl;
    int n;
    cout << "Enter total number of books : ";
    cin >> n;
    Stack_books S(n);
    while (1)
    {
        cout << endl;
        cout << "*** Stack operations. ***" << endl;
        cout << "1. Push operation." << endl;
        cout << "2. Pop operation. " << endl;
        cout << "3. Display." << endl;
        cout << "4. Exit. " << endl;
        cout << "Enter the choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Book bn;
            bn.input();
            S.push(bn);
            S.display();
            break;
        }
        case 2:
        {
            Book popedBook = S.pop();
            popedBook.Display();
            S.display();
            break;
        }
        case 3:
            S.display();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Please enter valid choice." << endl;
        }
    }
      
    return 0;
}