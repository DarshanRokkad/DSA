/*
Program no . 13
Design a C++ program that uses functions to perform the following:
a. Create a binary search tree of integers.
b. Search for an integer key in the above binary search tree non recursively.
c. Search for an integer key in the above binary search tree recursively.
*/
// Binary search tree

#include <iostream>
using namespace std;

class treeNode
{
public:
    int data;
    treeNode *lchild;
    treeNode *rchild;
    treeNode(int x)
    {
        data = x;
        lchild = rchild = NULL;
    }
};

class BinarySearchTree
{
private:
    treeNode *root;

public:
    BinarySearchTree()
    {
        root = NULL;
        while (1)
        {
            cout << endl
                 << "BST operation" << endl;
            cout << "1. Create ." << endl;
            cout << "2. Iterative search ." << endl;
            cout << "3. Recursive search ." << endl;
            cout << "4. Display inorder." << endl;
            cout << "5. Exit." << endl;
            cout << "Enter chioce : ";
            int c;
            cin >> c;
            switch (c)
            {
            case 1:
                create();
                break;
            case 2:
                if (root != NULL)
                    isearch();
                else
                    cout << "There is no tree." << endl;
                break;
            case 3:
                if (root != NULL)
                    rsearch();
                else
                    cout << "There is no tree." << endl;
                break;
            case 4:
                if (root != NULL)
                {
                    cout << "Inorder : ";
                    rinorder(root);
                    cout << endl;
                }
                else
                    cout << "There is no tree." << endl;
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid input." << endl;
            }
        }
    }

    // this will create a binary tree until user gives -1 for the nodes
    void create()
    {
        int x;
        cout << "Enter the root value : ";
        cin >> x;
        root = new treeNode(x);
        while (x != -1)
        {
            cout << "Enter the data to add to the tree : ";
            cin >> x;
            if (x != -1)
            {
                bool duplicate = false;
                treeNode *f = root;
                treeNode *t = NULL;
                while (f)
                {
                    t = f;
                    if (f->data == x)
                    {
                        cout << x << " is already present in the BST." << endl;
                        duplicate = true;
                        break;
                    }
                    else if (x < f->data)
                    {
                        f = f->lchild;
                    }
                    else
                    {
                        f = f->rchild;
                    }
                }
                f = new treeNode(x);
                if (!duplicate && x < t->data)
                {
                    t->lchild = f;
                }
                else if (!duplicate)
                {
                    t->rchild = f;
                }
            }
        }
    }

    // the inorder traversal of a binary search tree
    // this traversal gives the sorted elements
    void rinorder(treeNode *p)
    {
        if (!p)
        {
            return;
        }
        rinorder(p->lchild);
        cout << p->data << " ";
        rinorder(p->rchild);
    }

    // this function search the element the binary search tree and return that node
    void rsearch()
    {
        // recursive binary search
        cout << "Enter the element to be searched : ";
        int c;
        cin >> c;
        bool result = rsearch(root, c);
        if (result)
        {
            cout << c << " is found." << endl;
        }
        else
        {
            cout << c << " is not present in the binary search tree." << endl;
        }
    }
    bool rsearch(treeNode *p, int x)
    {
        if (!p)
        {
            return false;
        }
        if (x > p->data)
        {
            return rsearch(p->rchild, x);
        }
        else if (x < p->data)
        {
            return rsearch(p->lchild, x);
        }
        return true;
    }

    // iterative search of a key inside a BST
    void isearch()
    {
        // iterative binary search
        cout << "Enter the element to be searched : ";
        int c;
        cin >> c;
        bool result = isearch(c);
        if (result)
        {
            cout << c << " is found." << endl;
        }
        else
        {
            cout << c << " is not present in the binary search tree." << endl;
        }
    }
    bool isearch(int x)
    {
        treeNode *p = root;
        while (p && p->data != x)
        {
            if (x < p->data)
            {
                p = p->lchild;
            }
            else
            {
                p = p->rchild;
            }
        }
        if (p)
        {
            return true;
        }
        return false;
    }
};

// sample input : 9 15 5 20 16 8 12 3 6 -1

int main()
{
    BinarySearchTree b;

    return 0;
}