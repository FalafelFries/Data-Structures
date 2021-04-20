//DOUBLY LINKED LIST

#include<iostream>
#include<stdlib.h>
using namespace std;

//class node declaration

template <class T>

class node
{
    public:
        T data;
        node<T> *prev;
        node<T> *next;
};

//class doubly linked list declaration

template <class T>

class dl
{
    public:
        node<T> *front;
        node<T> *last;
        int lsize;
        dl();
        ~dl();
        bool isEmpty();
        void size();
        void insert(int index, T ele);
        void remove(int index);
        int getIndex(T ele);
        T getEle(int index);
        void display();
};

//constructor function

template <class T>

dl<T>::dl()
{
    front=last=NULL;
    lsize=0;
}

//destructor function

template <class T>

dl<T>::~dl()
{
    node<T> *temp=front;
    while(temp!=NULL)
    {
        front=front->next;
        delete temp;
        temp=front;
    }
}

//isEmpty function : returns true if the list is empty, false otherwise

template <class T>

bool dl<T>::isEmpty()
{
    if(lsize==0)
        return true;
    else
        return false;
}

//we don't have an isFull function since we're assuming that we won't be utilising all the available heap memory

//size function : outputs the list size

template <class T>

void dl<T>::size()
{
    if(isEmpty())
        cout<<"\n LIST EMPTY!";
    else
        cout<<"\n Size of the list is : "<<lsize;
}

//NOTE : INDEXING STARTS FROM 0

//insert function : inserts given element at a given index

template <class T>

void dl<T>::insert(int index, T ele)
{
    if(index<0||index>lsize)
        cout<<"\n Invalid index";
    else
    {
        node<T> *temp = new node<T>;
        temp->data=ele;

        //if the list is empty, i.e, the given node is the first node of the list

        if(isEmpty())
        {
            last=front=temp;
            temp->next=temp->prev=NULL;
        }

        //inserting node at first position

        else if(index==0)
        {
            temp->prev=NULL;
            temp->next=front;
            front->prev=temp;
            front=temp;
        }

        //inserting at last position 

        else if(index==lsize)
        {
            temp->next=NULL;
            last->next=temp;
            temp->prev=last;
            last=temp;
        }

        //inserting elsewhere

        else
        {
            
            node<T> *p = new node<T>;
            p=front;
            for(int i=0;i<index-1;i++)
                p=p->next;
            temp->next=p->next;
            p->next->prev=temp;
            p->next=temp;
            temp->prev=p;
        }
        lsize++;
        cout<<"\n Success!";
    }
}

//NOTE : INDEXING STARTS FROM 0

//remove function : removes and outputs the element to be deleted at a given index

template <class T>

void dl<T>::remove(int index)
{

    //if list is empty

    if(isEmpty())
        cout<<"\n LIST EMPTY!";
    else
    {
        if(index<0||index>=lsize)
            cout<<"\n Invalid index";
        else
        {
            node<T> *p=front;

            //if the list contains only one node and we are to delete that node

            if(lsize==1)
        {
            cout<<"\n Deleted element is : "<<p->data;
            delete p;
            front=last=NULL;
        }

        //deleting first node

        else if(index==0)
        {
            cout<<"\n Deleted element is : "<<p->data;
            front=p->next;
            front->prev=NULL;
            delete p;
        }

        //deleting last node

        else if(index==lsize-1)
        {
            p=last;
            cout<<"\n Deleted element is : "<<p->data;
            last=p->prev;
            last->next=NULL;
            delete p;
        }

        //deleting elsewhere

        else
        {
            for(int i=0;i<index;i++)
                p=p->next;
            p->prev->next=p->next;
            p->next->prev=p->prev;
            cout<<"\n Deleted element is : "<<p->data;
            delete p;
        }
            lsize--;
            cout<<"\n Success!";
        }
    }
}

//NOTE : INDEXING STARTS FROM 0

//getIndex function : returns index of given element

template <class T>

int dl<T>::getIndex(T ele)
{
    node<T> *temp=front;
    for(int i=0;i<lsize;i++)
    {
        if(temp->data==ele)
            return i;
        temp=temp->next;
    }
    return -1;
}

//NOTE : INDEXING STARTS FROM 0

//getEle function : returns element at given index

template <class T>

T dl<T>::getEle(int index)
{
    if(index<0||index>lsize-1)
        throw index;
    else
    {
        node<T> *temp=front;
        for(int i=0;i<index;i++)
            temp=temp->next;
        return temp->data;
    }
}

//display function : outputs elements in the list

template <class T>

void dl<T>::display()
{
    if(isEmpty())
        cout<<"\n LIST EMPTY!";
    else
    {
        node<T> *temp=front;
        cout<<"\n The elements are : \n";
        for(int i=0;i<lsize;i++)
        {
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
    }
}

//main function

main()
{
    //declaring singly linked list object
    dl<int>D;
    int choice, index, x, res;
    while(1)
    {
        cout<<"\n1.INSERT 2.REMOVE 3.GET ELEMENT 4.GET INDEX 5.SIZE 6.OUTPUT 7.EXIT";
        cout<<"\n Input your choice : ";
        cin>>choice;
        switch (choice)
        {
            //NOTE : INDEXING STARTS FROM 0

            case 1 : cout<<"\n Enter index at which you want to insert : ";
                        cin>>index;
                        cout<<"\n Enter element : ";
                        cin>>x;
                        D.insert(index, x);
                        break;
            case 2 : cout<<"\n Enter index at which you want to delete : ";
                        cin>>index;
                        D.remove(index);
                        break;
            case 3 :    try
                        {
                            cout<<"\n Enter index whose element you want to access : ";
                            cin>>index;
                            cout<<"\n The element at index "<<index<<" is : "<<D.getEle(index);
                        }
                        catch(int index)
                        {
                            cout<<"\n Invalid index";
                        }
                        break;
            case 4 : cout<<"\n Enter element whose index you want to know : ";
                        cin>>x;
                        res=D.getIndex(x);
                        if(res==-1)
                            cout<<"\n Element not found";
                        else
                            cout<<"\n Index of "<<x<<" is : "<<res;
                        break;
            case 5 : D.size();
                        break;
            case 6 : D.display();
                        break;
            case 7 : exit(0);
                        break;
            default : cout<<"\n Invalid choice";
                        break;
        }
    }
}