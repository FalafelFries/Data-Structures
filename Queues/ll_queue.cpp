//Linked list implementation of QUEUE

#include<iostream>
#include<stdlib.h>
using namespace std;

//class node declaration

template <class T>

class node
{
    public:
        T data;
        node<T> *next;
};

//class queue declaration

template <class T>

class q
{
    public:
        node<T> *front, *rear;
        q();
        ~q();
        bool isEmpty();
        void enqueue();
        void dequeue();
        void atFront();
        void atRear();
        void display();
};

//constructor function

template <class T>

q<T>::q()
{
    front=rear=NULL;
}

//destructor function

template <class T>

q<T>::~q()
{
    node<T> *temp = front;
    while(temp!=NULL)
    {    
        front=temp->next;
        delete temp;
        temp=front;
    }
}

//isEmpty function : returns true if the queue is empty, false otherwise

template <class T>

bool q<T>::isEmpty()
{
    if(front==NULL)
        return true;
    else
        return false;
}

//we don't have an isFull function since we're assuming that we won't be utilising all the available heap memory

//enqueue function : inserts an element at the rear end of the queue if the queue is not full

template <class T>

void q<T>::enqueue()
{
        node<T> *temp=new node<T>;
        T ele;
        cout<<"\n Enter element to be enqueued : ";
        cin>>ele;
        temp->data=ele;
        if(isEmpty())
        {
            temp->next=NULL;
            front=rear=temp;
        }
        else
        {
            temp->next=NULL;
            rear->next=temp;
            rear=temp;
        }
        cout<<"\n Success!";
}

//dequeue function : removes and returns the element at the front end of the queue if the queue is not empty

template <class T>

void q<T>::dequeue()
{
    if(isEmpty())
        cout<<"\n QUEUE EMPTY";
    else
    {
        node<T> *temp=new node<T>;
        temp=front;
        if(front==rear)
            {
                cout<<"\n Dequeued element is : "<<front->data;
                front=rear=NULL;
            }
        else
            {
                front=temp->next;
                cout<<"\n Dequeued element is : "<<temp->data;
                delete temp;
            }
        cout<<"\n Success!";
    }
}

//atFront function : returns the element at the front end of the queue if the queue is not empty

template <class T>

void q<T>::atFront()
{
    if(isEmpty())
        cout<<"\n QUEUE EMPTY";
    else
        cout<<"\n Element at front end is : "<<front->data;
}

//atRear function : returns the element at the rear end of the queue if the queue is not empty

template <class T>

void q<T>::atRear()
{
    if(isEmpty())
        cout<<"\n QUEUE EMPTY";
    else
        cout<<"\n Element at rear end is : "<<rear->data<<endl;
}

//display function : outputs the elements in the queue

template <class T>

void q<T>::display()
{
    if(isEmpty())
        cout<<"\n QUEUE EMPTY";
    else
    {
        node<T> *temp=new node<T>;
        temp=front;
        cout<<"\n The elements in the queue are: \n";
        while(temp!=NULL)
        {
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
    }
}

//main function

main()
{
    //declaring queue object
    q<int>Q;
    int choice;
    while(1)
    {
        cout<<"\n1.ENQUEUE 2.DEQUEUE 3.AT FRONT 4.AT REAR 5.OUTPUT 6.EXIT";
        cout<<"\n Input your choice : ";
        cin>>choice;
        switch (choice)
        {
            case 1 : Q.enqueue();
                        break;
            case 2 : Q.dequeue();
                        break;
            case 3 : Q.atFront();
                        break;
            case 4 : Q.atRear();
                        break;
            case 5 : Q.display();
                        break;
            case 6 : exit(0);
                        break;
            default : cout<<"\n Invalid choice";
                        break;
        }
    }
}