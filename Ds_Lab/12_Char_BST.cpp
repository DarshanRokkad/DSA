/*
Design a C++ program that uses functions to perform the following:
a. Create a binary search tree of characters.
b. Traverse the above Binary search tree recursively in preorder, in order and post order.
*/
// Binary search tree
#include <iostream>
using namespace std;

class treeNode
{
public:
    char data;
    treeNode *lchild;
    treeNode *rchild;
    treeNode(char x)
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
            cout << endl;
            cout << "BST Creation and traversal" << endl;
            cout << "1. Create ." << endl;
            cout << "2. Preorder traversal ." << endl;
            cout << "3. Inorder traversal ." << endl;
            cout << "4. Postorder traversal." << endl;
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
                {
                    cout << "Preorder : ";
                    preorder(root);
                    cout << endl;
                }
                else
                    cout << "There is no tree." << endl;
                break;
            case 3:
                if (root != NULL)
                {
                    cout << "Inorder : ";
                    inorder(root);
                    cout << endl;
                }
                else
                    cout << "There is no tree." << endl;
                break;
            case 4:
                if (root != NULL)
                {
                    cout << "Postorder : ";
                    postorder(root);
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
        char x;
        cout << "Enter the root value : ";
        cin >> x;
        root = new treeNode(x);
        while (x != '0')
        {
            cout << "Enter the data to add to the tree : ";
            cin >> x;
            if (x != '0')
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

    void inorder(treeNode *p)
    {
        if (!p)
        {
            return;
        }
        else
        {
            inorder(p->lchild);
            cout << p->data << " ";
            inorder(p->rchild);
        }
    }
    void preorder(treeNode *p)
    {
        if (!p)
        {
            return;
        }
        else
        {
            cout << p->data << " ";
            preorder(p->lchild);
            preorder(p->rchild);
        }
    }
    void postorder(treeNode *p)
    {
        if (!p)
        {
            return;
        }
        else
        {
            postorder(p->lchild);
            postorder(p->rchild);
            cout << p->data << " ";
        }
    }
};

// sample input : h s w e a b u e f 0

int main()
{
    BinarySearchTree b;

    return 0;
}