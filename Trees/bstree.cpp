//BINARY SEARCH TREE

#include<iostream>
#include<stdlib.h>
using namespace std;

//class node declaration

template <class T>

class node
{
    public:
        T ele;                  //data
        node<T> *lc;            //pointer to left child
        node<T> *rc;            //pointer to right child
        
        //parameterised constructor function where in the data to be stored in the node is passed

        node(T e)
        {
            ele=e;              //data is stored in node
            lc=rc=NULL;         //assigning left and right child as null
        }

        //parameterised constructor function where in data and pointer to both left and right child is passed

        node(T e, node<T> *l, node<T> *r)
        {
            ele=e;              //data is stored in node
            lc=l;               //assigning left child
            rc=r;               //assigning right child
        }
};

//class binary search tree declaration

template <class T>

class bstree
{
    public:
        node<T> *root;
        int tsize;
        bstree();
        void size();
        void visit(node<T> *p);
        void inorder(node<T> *p);
        void ascend();
        bool find(T key);
        void insert(T key);
        void remove(T key);
};

//constructor function for binary search tree

template <class T>

bstree<T>::bstree()
{
    root=NULL;
    tsize=0;
}

//size function : outputs the number of elements in the binary search tree

template <class T>

void bstree<T>::size()
{
    cout<<"\n The size of the tree is : "<<tsize;
}

//visit function : we output the data contained in the node thus marking it as visited

template <class T>

void bstree<T>::visit(node<T> *p)
{
    cout<<p->ele<<"\t";
}

//inorder function : a node is passed and the node's inorder traversal is done

template <class T>

void bstree<T>::inorder(node<T> *p)
{
    if(p==NULL)
        return;
    inorder(p->lc);
    visit(p);
    inorder(p->rc);
}

//ascend function : the root node's inorder traversal is done in this function

template <class T>

void bstree<T>::ascend()
{
    inorder(root);
}

//find function : searches for a given key

template <class T>

bool bstree<T>::find(T key)
{
    node<T> *q=root;
    while (q!=NULL)
    {
        if(key<q->ele)
            q=q->lc;
        else if(key>q->ele)
            q=q->rc;
        else
            return true;
    }
    return false;
}

//insert function : inserts a given key if the key already already doesn't exist

template <class T>

void bstree<T>::insert(T key)
{

    //finding the position where the node containing the key is to be inserted

    node<T> *p=root, *pp=NULL;
    while(p!=NULL)
    {
        pp=p;
        if(key<p->ele)
            p=p->lc;
        else if(key>p->ele)
            p=p->rc;
        else
        {
            cout<<"\n Key already exists!";
            return;
        }
    }

    //inserting the key

    //key is to be inserted at root node position

    node<T> *q=new node<T>(key);
    if (pp==NULL)
        root=q;

    //key is inserted elsewhere

    else
    {
        if(key<pp->ele)
            pp->lc=q;
        else if(key>pp->ele)
            pp->rc=q;
    }
    tsize++;
}

//remove function : deletes a key if it is present

template <class T>

void bstree<T>::remove(T key)
{

    //finding the position of the node containing the key

    node<T> *p=root, *pp=NULL;
    while(p!=NULL && p->ele!=key)
    {
        pp=p;
        if(key<p->ele)
            p=p->lc;
        else if(key>p->ele)
            p=p->rc;
    }

    //key not found

    if(p==NULL)
        return;

    //key found ..

    //case 3 where in node to be deleted has 2 children

    if(p->lc!=NULL && p->rc!=NULL)
    {
        node<T> *s=p->lc, *ps=p;

        //getting the inorder predecessor of the node that is to be deleted

        while(s->rc)
        {
            ps=s;
            s=s->rc;
        }

        //creating a new node containing the data of the inorder predecessor that would replace the node which is to be deleted

        node<T> *q = new node<T>(s->ele,p->lc,p->rc);

        //if the node to be deleted is the root node

        if(pp==NULL)
            root=q;

        //if the node to be deleted is other than the root node

        else
        {
            if(p==pp->lc)
                pp->lc=q;
            else
                pp->rc=q;
        }
        if(ps==p)
            pp=q;
        else
            pp=ps;
            delete p;
            p=s;
    }

    //case 1 and case 2 where in the node to be deleted has atmost one children

    node<T> *c; 
    if(p->lc!=NULL)
        c=p->lc;
    else
        c=p->rc;
    
    //if the node to be deleted is the root node

    if(p==root)
        root=c;
    
    //if the node to be deleted is other than the root node

    else
    {
        if(p==pp->lc)
            pp->lc=c;
        else
            pp->rc=c;
    }
    tsize--;
    delete p;
}

//main function 

main()
{

    //creating binary search tree object which has just a single root node that points to null

    bstree<int>B;
    int choice,key;
    while(1)
    {
        cout<<"\n 1.INSERT 2.DELETE 3.SEARCH 4.OUTPUT 5.SIZE 6.EXIT";
        cout<<"\n Input your choice : ";
        cin>>choice;
        switch (choice)
        {
            case 1 : cout<<"\n Enter element to be inserted : ";
                    cin>>key;
                    B.insert(key);
                    break;
            case 2 : cout<<"\n Enter element to be deleted : ";
                    cin>>key;
                    B.remove(key);
                    break;
            case 3 : cout<<"\n Enter element to be searched : ";
                    cin>>key;
                    if(B.find(key))
                        cout<<"\n Element found!";
                    else
                        cout<<"\n Element not found!";
                    break;
            case 4 : B.ascend();
                    break;
            case 5 : B.size();
                    break;
            case 6 : exit(0);
                    break;
            default : cout<<"\n Invalid choice";
                    break;
        }
    }
}