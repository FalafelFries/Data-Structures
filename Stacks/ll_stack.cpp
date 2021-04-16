//Linked list implementation of STACK

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

//class stack declaration

template <class T>

class st
{
    public:
        node<T> *top;
        st();
        ~st();
        bool isEmpty();
        void push();
        void pop();
        void topEle();
        void display();
};

//constructor function

template <class T>

st<T>::st()
{
    top=NULL;
}

//destructor function

template <class T>

st<T>::~st()
{
    node<T> *temp;
    temp=top;
    while(temp!=NULL)
        {
            temp->next=top;
            delete temp;
            temp=top;
        }
}

//isEmpty function : returns true if the stack is empty, false otherwise

template <class T>

bool st<T>::isEmpty()
{
    if(top==NULL)
        return true;
    else
        return false;
}

//we don't have an isFull function since we're assuming that we won't be utilising all the available heap memory. Hence, there would be no stack overflow error

//push function : inserts element at top if the stack is not full

template <class T>

void st<T>::push()
{
    
        T ele;
        cout<<"\n Insert element to be pushed : ";
        cin>>ele;
        node<T> *temp=new node<T>;
        temp->data=ele;
        temp->next=top;
        top=temp;
        cout<<"\n Success!";
}

//pop function : deletes and returns element at top if the stack is not empty

template <class T>

void st<T>::pop()
{
    if(top==NULL)
        cout<<"\n STACK UNDERFLOW";
    else
    {
        T ele;
        ele=top->data;
        node<T> *temp=new node<T>;
        temp=top;
        top=temp->next;
        cout<<"\n Popped element is : "<<ele;
        delete temp;
        cout<<"\n Success!";
    }
}

//topEle function : returns the top element of the stack if the stack is not empty

template <class T>

void st<T>::topEle()
{
    if(top==NULL)
        cout<<"\n STACK UNDERFLOW";
    else
        cout<<"\n The top element is : "<<top->data;
}

//display function : outputs the elements in the stack

template <class T>

void st<T>::display()
{
    if(top==NULL)
        cout<<"\n STACK UNDERFLOW";
    else
        {
            node<T> *temp=new node<T>;
            temp=top;
            cout<<"\n The elements in the stack are : \n";
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
    //declaring stack object
    st<int>S;
    int choice;
    while(1)
    {
        cout<<"\n 1.PUSH 2.POP 3.GET TOP ELEMENT 4.OUTPUT 5.EXIT";
        cout<<"\n Input your choice : ";
        cin>>choice;
        switch (choice)
        {
            case 1 : S.push();
                        break;
            case 2 : S.pop();
                        break;
            case 3 : S.topEle();
                        break;
            case 4 : S.display();
                        break;
            case 5 : exit(0);
                        break;
            default : cout<<"\n Invalid choice";
                        break;
        }
    }
}