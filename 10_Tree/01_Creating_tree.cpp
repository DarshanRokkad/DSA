// Creating the binary tree
#include <iostream>
// including the queue class to store the address of the tree node
#include "00_queue.h"
#include "02_stack.h"
#include <stack>
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

class BinaryTree
{
private:
    treeNode *root;

public:
    BinaryTree()
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
        MyQueue<treeNode *> q;
        q.enque(root);
        treeNode *p, *t;
        while (!q.isEmpty())
        {
            cout << endl;
            p = q.deque();

            cout << "Enter the left node of " << (p->data) << " : ";
            cin >> x;
            if (x != -1)
            {
                t = new treeNode(x);
                p->lchild = t;
                q.enque(t);
            }

            cout << "Enter the right node of " << (p->data) << " : ";
            cin >> x;
            if (x != -1)
            {
                t = new treeNode(x);
                p->rchild = t;
                q.enque(t);
            }
        }
        cout << endl;
    }

    // this will recursively print the tree in different traversal
    void recursivePrint()
    {
        cout << "** Recursive traversal **" << endl;
        cout << "Recursive Preorder : ";
        preorder();
        cout << endl;
        cout << "Recursive Inorder : ";
        inorder(root);
        cout << endl;
        cout << "Recursive Postorder : ";
        postorder(root);
        cout << endl
             << endl;
    }

    // this will iteratively print the tree in different traversal
    void iterativePrint()
    {
        cout << "** Iterative traversal **" << endl;
        cout << "Iterative Preorder : ";
        ipreorder(root);
        cout << endl;
        cout << "Iterative Inorder : ";
        iinorder(root);
        cout << endl;
        cout << "Iterative Postorder : ";
        ipostorder(root);
        cout << endl;
        cout << "Iterative level order : ";
        levelorder();
        cout << endl
             << endl;
    }

    // here we can avoid taking input to the recursive function in fuction call by using dummy function that indirectly calls the recursive function by send the root node as a parameter .
    void preorder() { preorder(root); }
    // Preorder traversal of the binary tree
    void preorder(treeNode *p)
    {
        if (p)
        {
            cout << p->data << " ";
            preorder(p->lchild);
            preorder(p->rchild);
        }
    }

    // In order traversal of the binary tree
    void inorder(treeNode *p)
    {
        if (p)
        {
            inorder(p->lchild);
            cout << p->data << " ";
            inorder(p->rchild);
        }
    }

    // Post order traversal of the binary tree
    void postorder(treeNode *p)
    {
        if (p)
        {
            postorder(p->lchild);
            postorder(p->rchild);
            cout << p->data << " ";
        }
    }

    // iterative pre order traversal
    void ipreorder(treeNode *p)
    {
        stack<treeNode *> st;
        while (p || !st.empty())
        {
            if (p)
            {
                cout << p->data << " ";
                st.push(p);
                p = p->lchild;
            }
            else
            {
                p = st.top();
                st.pop();
                p = p->rchild;
            }
        }
    }

    // iterative inorder traversal
    void iinorder(treeNode *p)
    {
        stack<treeNode *> st;
        while (p || !st.empty())
        {
            if (p)
            {
                st.push(p);
                p = p->lchild;
            }
            else
            {
                p = st.top();
                st.pop();
                cout << p->data << " ";
                p = p->rchild;
            }
        }
    }

    // iterative post order traversal
    void ipostorder(treeNode *p)
    {
        long long temp = 0;
        stack<treeNode *> st;
        while (p || !st.empty())
        {
            if (p)
            {
                st.push(p);
                p = p->lchild;
            }
            else
            {
                p = st.top();
                st.pop();
                if ((long long)p > 0)
                {
                    st.push((treeNode *)(-(long long)p));
                    p = p->rchild;
                }
                else
                {
                    cout << ((treeNode *)(-(long long)p))->data << " ";
                    p = NULL;
                }
            }
        }
    }

    // iterative level order
    void levelorder()
    {
        treeNode *p = root;
        MyQueue<treeNode *> q;
        q.enque(root);
        cout << p->data << " ";
        while (!q.isEmpty())
        {
            p = q.deque();
            if (p->lchild)
            {
                cout << p->lchild->data << " ";
                q.enque(p->lchild);
            }
            if (p->rchild)
            {
                cout << p->rchild->data << " ";
                q.enque(p->rchild);
            }
        }
    }

    // count the number of nodes in a binary tree
    int count() { return count(root); }
    int count(treeNode *p)
    {
        int x = 0, y = 0;
        if (p)
        {
            x = count(p->lchild);
            y = count(p->rchild);
            return x + y + 1;
        }
        return 0;
    }

    // Gives the sum of all the nodes of the binary tree
    int sum() { return sum(root); }
    int sum(treeNode *p)
    {
        int x = 0, y = 0;
        if (p)
        {
            x = sum(p->lchild);
            y = sum(p->rchild);
            return x + y + (p->data);
        }
        return 0;
    }

    // Gives the height of the tree
    int height() { return height(root); }
    int height(treeNode *p)
    {
        int x = 0, y = 0;
        if (p)
        {
            x = height(p->lchild);
            y = height(p->rchild);
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

    // Gives the number of nodes with degree 2
    
    int nodes_with_degree2(){ return nodes_with_degree2(root);}
    int nodes_with_degree2(treeNode *p)
    {
        int x = 0, y = 0;
        if (p)
        {
            x = nodes_with_degree2(p->lchild);
            y = nodes_with_degree2(p->rchild);
            if (p->rchild && p->lchild)
            {
                return x + y + 1;
            }
            else
            {
                return x + y;
            }
        }
        return 0;
    }
};

//  the below is a sample binary tree
//              5
//    8                   6
//        9            3
//      4   2
// sample input : 5 8 6 -1 9 3 -1 4 2 -1 -1 -1 -1 -1 -1
int main()
{
    BinaryTree b;
    b.create();
    b.recursivePrint();
    b.iterativePrint();
    cout << "Total nodes : " << b.count() << endl;
    cout << "Sum of nodes: " << b.sum() << endl;
    cout << "Height of tree : " << b.height() << endl;
    cout << "Nodes with degree 2 : " << b.nodes_with_degree2() << endl;

    return 0;
}