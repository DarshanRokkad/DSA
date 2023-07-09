// Binary search tree
#include <iostream>
#include "Mystack.h"
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
                iinsert(x);
            }
        }

        // extra
        cout << endl;
        cout << "Inorder traversal : ";
        rinorder(root);
        cout << endl;
        rsearch();
        isearch();
        iinsert();
        rinsert();
        deleteN();
    }

    // the inorder traversal of a binary search tree
    // this traversal gives the sorted elements
    void rinorder(treeNode *p)
    {
        if (!p)
        {
            return;
        }
        else
        {
            rinorder(p->lchild);
            cout << p->data << " ";
            rinorder(p->rchild);
        }
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

    // iterative insert of a key
    void iinsert()
    {
        cout << "Enter the element you need to insert : ";
        int c;
        cin >> c;
        iinsert(c);
        // Inorder traversal of a BST
        cout << "Inorder traversal : ";
        rinorder(root);
        cout << endl;
    }
    void iinsert(int key)
    {
        treeNode *f = root;
        treeNode *t = NULL;
        while (f)
        {
            t = f;
            if (f->data == key)
            {
                cout << key << " is already present in the BST." << endl;
                return;
            }
            else if (key < f->data)
            {
                f = f->lchild;
            }
            else
            {
                f = f->rchild;
            }
        }
        f = new treeNode(key);
        if (key < t->data)
        {
            t->lchild = f;
        }
        else
        {
            t->rchild = f;
        }
    }

    // recursive insert of a key
    void rinsert()
    {
        cout << "Enter the element you need to insert : ";
        int c;
        cin >> c;
        root = rinsert(root, c);

        // Inorder traversal of the BST
        cout << "Inorder traversal : ";
        rinorder(root);
        cout << endl;
    }
    treeNode *rinsert(treeNode *p, int key)
    {
        if (!p)
        {
            p = new treeNode(key);
            return p;
        }
        if (key < p->data)
        {
            p->lchild = rinsert(p->lchild, key);
        }
        else if (key > p->data)
        {
            p->rchild = rinsert(p->rchild, key);
        }
        return p;
    }

    // this function gives the height of the bst
    int maxHeight(treeNode *p)
    {
        int x, y;
        if (p)
        {
            x = maxHeight(p->lchild);
            y = maxHeight(p->rchild);
            if (x > y)
            {
                return x + 1;
            }
            else
            {
                return y + 1;
            }
        }
        return 0;
    }

    // this function gives the inorder predessor of the particular tree
    treeNode *inPre(treeNode *p)
    {
        while (p->rchild)
        {
            p = p->rchild;
        }
        return p;
    }

    // this function gives the inorder predessor of the particular tree
    treeNode *inSuc(treeNode *p)
    {
        while (p->lchild)
        {
            p = p->lchild;
        }
        return p;
    }

    // this function will delete the node from the BST
    void deleteN()
    {
        cout << "Enter the data to be deleted : ";
        int x;
        cin >> x;
        root = deleteN(root, x);
        rinorder(root);
    }
    treeNode *deleteN(treeNode *p, int key)
    {
        if (!p)
        {
            return NULL;
        }
        if (!p->lchild && !p->rchild)
        {
            if (p == root)
            {
                root = NULL;
            }
            delete p;
            return NULL;
        }
        if (key < p->data)
        {
            p->lchild = deleteN(p->lchild, key);
        }
        else if (key > p->data)
        {
            p->rchild = deleteN(p->rchild, key);
        }
        else
        {
            treeNode *q;
            if (maxHeight(p->lchild) > maxHeight(p->rchild))
            {
                q = inPre(p->lchild);
                p->data = q->data;
                p->lchild = deleteN(p->lchild, q->data);
            }
            else
            {
                q = inSuc(p->rchild);
                p->data = q->data;
                p->rchild = deleteN(p->rchild, q->data);
            }
        }
        return p;
    }

    void createUsePre(int pre[], int n)
    {
        Mystack<treeNode *> st;
        int i = 0;
        root = new treeNode(pre[i++]);
        treeNode *p = root, *t;
        while (i < n)
        {
            if (pre[i] < p->data)
            {
                t = new treeNode(pre[i++]);
                p->lchild = t;
                st.push(p);
                p = t;
            }
            else
            {
                if (pre[i] > p->data && pre[i] < (st.empty() ? INT_MAX : st.top()->data))
                {
                    t = new treeNode(pre[i++]);
                    p->rchild = t;
                    p = t;
                }
                else
                {
                    p = st.top();
                    st.pop();
                }
            }
        }
        rinorder(root);
    }
};

// sample input : 9 15 5 20 16 8 12 3 6 -1

int main()
{
    BinarySearchTree b;
    int a[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int size = sizeof(a) / sizeof(a[0]);
    b.createUsePre(a, size);

    return 0;
}