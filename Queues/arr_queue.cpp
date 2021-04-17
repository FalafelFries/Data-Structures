//Array implementation of QUEUE

#include<iostream>
#include<stdlib.h>
using namespace std;

//class declaration

template <class T>

class q
{
    public:
        int front, rear;
        T *a;
        int size;
        q(int inSize);
        ~q();
        bool isEmpty();
        bool isFull();
        void enqueue();
        void dequeue();
        void atFront();
        void atRear();
        void display();
};

//parameterized constructor function

template <class T>

q<T>::q(int inSize)
{
    size=inSize;
    front=0;
    rear=-1;
    a=new T[size];
}

//destructor function

template <class T>

q<T>::~q()
{
    delete []a;
}

//isEmpty function : returns true if the queue is empty, false otherwise

template <class T>

bool q<T>::isEmpty()
{
    if((front==0&&rear==-1)||(front==rear+1))
        return true;
    else
        return false;
}

//isFull function : returns true if the queue is full, false otherwise

template <class T>

bool q<T>::isFull()
{
    if(rear==size-1)
        return true;
    else
        return false;
}

//enqueue function : inserts an element at the rear end of the queue if the queue is not full

template <class T>

void q<T>::enqueue()
{
    if(isFull())
        cout<<"\n QUEUE FULL";
    else
    {
        T ele;
        cout<<"\n Enter element to be enqueued : ";
        cin>>ele;
        rear++;
        a[rear]=ele;
        cout<<"\n Success!";
    }
}

//enqueue function : removes an element from the front end of the queue if the queue is not empty

template <class T>

void q<T>::dequeue()
{
    if(isEmpty())
        cout<<"\n QUEUE EMPTY";
    else
    {
        cout<<"\n Dequeued element is : "<<a[front];
        front++;
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
        cout<<"\n Element at front end is : "<<a[front];
}

//atRear function : returns the element at the rear end of the queue if the queue is not empty

template <class T>

void q<T>::atRear()
{
    if(isEmpty())
        cout<<"\n QUEUE EMPTY";
    else
        cout<<"\n Element at rear end is : "<<a[rear];
}

//display function : outputs the elements in the queue

template <class T>

void q<T>::display()
{
    if(isEmpty())
        cout<<"\n QUEUE EMPTY";
    else
        {
            cout<<"\n The elements in the queue are: \n";
            for(int i=front;i<=rear;i++)
                cout<<a[i]<<"\t";
        }
}

//main function 

main()
{
    //declaring queue object
    q<int>Q(5);
    int choice;
    while(1)
    {
        cout<<"\n1.ENQUEUE 2.DEQUEUE 3.AT FRONT 4.AT REAR 5.OUTPUT 6.EXIT\n";
        cout<<"\n input your choice : ";
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