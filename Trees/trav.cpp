//TREE TRAVERSALS

#include<iostream>
#include<stdlib.h>
using namespace std;

template <class T>

//class node declaration

class node
{
    public:
        T ele;                  //data
        node<T> *lc;            //pointer to left child
        node<T> *rc;            //pointer to right child

        //parameterised constructor function where in data and pointer to both left and right child is passed

        node(T e, node<T> *l, node<T> *r)
        {
            ele=e;              //data is stored in node
            lc=l;               //assigning left child
            rc=r;               //assigning right child
        }
};

//class binary tree declation

template <class T>

class btree
{
    public:
        node<T> *root;
        btree();
        void makeTree(T ele, btree<T> *l, btree<T> *r);
        void visit(node<T> *p);
        void preorder(node<T> *p);
        void preorder();
        void inorder(node<T> *p);
        void inorder();
        void postorder(node<T> *p);
        void postorder();
};

//constructor function for binary tree

template <class T>

btree<T>::btree()
{
    root=NULL;
}

//makeTree function : data and pointer to both left and right subtrees are passed

template <class T>

void btree<T>::makeTree(T ele, btree<T> *l, btree<T> *r)
{
    root=new node<T>(ele, l->root, r->root); //node is created with the passed pointer arguments being set as its left and right subtrees
}

template <class T>

//visit function : we output the data contained in the node thus marking it as visited

void btree<T>::visit(node<T> *p)
{
    cout<<p->ele<<"\t";
}

//preorder function : a node is passed and the node's preorder traversal is done

template <class T>

void btree<T>::preorder(node<T> *p)
{
    if(p!=NULL)
        {
            visit(p);
            preorder(p->lc);
            preorder(p->rc);
        }
}

//the root node's preorder traversal is done in this function

template <class T>

void btree<T>::preorder()
{
    preorder(root);
}

//inorder function : a node is passed and the node's inorder traversal is done

template <class T>

void btree<T>::inorder(node<T> *p)
{
    if(p!=NULL)
        {
            inorder(p->lc);
            visit(p);
            inorder(p->rc);
        }
}

//the root node's inorder traversal is done in this function

template <class T>

void btree<T>::inorder()
{
    inorder(root);
}

//postorder function : a node is passed and the node's postorder traversal is done

template <class T>

void btree<T>::postorder(node<T> *p)
{
    if(p!=NULL)
        {
            postorder(p->lc);
            postorder(p->rc);
            visit(p);
        }
}

//the root node's postorder traversal is done in this function

template <class T>

void btree<T>::postorder()
{
    postorder(root);
}

//main function

main()
{

    //declaring binary tree objects each of which consist of a single root node which are assigned as NULL

    btree<char>t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15;

    //assigning data and left and right child to t7

    t7.makeTree('G',&t14, &t15);
    
    //assigning data and left and right child to t6
    
    t6.makeTree('F',&t12, &t13);

    //assigning data and left and right child to t5
    
    t5.makeTree('E',&t10, &t11);

    //assigning data and left and right child to t4
    
    t4.makeTree('D',&t8, &t9);
    
    //assigning data and left and right child to t3
    
    t3.makeTree('C',&t6, &t7);

    //assigning data and left and right child to t2
    
    t2.makeTree('B',&t4, &t5);

    //assigning data and left and right child to t1
    
    t1.makeTree('A',&t2, &t3);

/*

the tree looks like this :

                 A
            /        \
          B            C
       /    \       /     \
      D      E     F       G
     / \    / \   / \     / \
    0   0  0   0 0   0   0   0

(0 here stands for NULL)

*/

    //finding preorder traversal

    cout<<"\n Preorder traversal of the given tree is : \n";
    t1.preorder();
    
    //finding inorder traversal

    cout<<"\n Inorder traversal of the given tree is : \n";
    t1.inorder();
    
    //finding postorder traversal

    cout<<"\n Postorder traversal of the given tree is : \n";
    t1.postorder();
}