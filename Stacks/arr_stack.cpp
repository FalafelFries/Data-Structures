//Array implementation of STACK

#include<iostream>
#include<stdlib.h>
using namespace std;

//class declaration 

template <class T>

class st
{
    public:
        T *a;
        int top;
        int size;
        st(int inSize);
        ~st();
        bool isEmpty();
        bool isFull();
        void push();
        void pop();
        void topEle();
        void display();
};

//parameterized constructor function

template <class T>

st<T>::st(int inSize)
{
    top=-1;
    size=inSize;
    a=new T[size];
}

//destructor function

template <class T>

st<T>::~st()
{
    delete []a;
}

//isEmpty function : returns true if the stack is empty, false otherwise

template <class T>

bool st<T>::isEmpty()
{
    if(top==-1)
        return true;
    else
        return false;
}

//isFull function : returns true if the stack is full, false otherwise

template <class T>

bool st<T>::isFull()
{
    if(top==size-1)
        return true;
    else
        return false;
}

//push function : inserts element at top if the stack is not full

template <class T>

void st<T>::push()
{
    if(isFull())
        cout<<"\n STACK OVERFLOW";
    else
    {
        top++;
        T ele;
        cout<<"\n Insert element to be pushed : ";
        cin>>ele;
        a[top]=ele;
        cout<<"\n Success!";
    }
}

//pop function : deletes and returns element at top if the stack is not empty

template <class T>

void st<T>::pop()

{
    if(isEmpty())
        cout<<"\n STACK UNDERFLOW";
    else
    {
        T ele=a[top];
        top--;
        cout<<"\n Popped element is : "<<ele;
        cout<<"\n Success!";
    }
}

//topEle function : returns the top element of the stack if the stack is not empty

template <class T>

void st<T>::topEle()

{
    if(isEmpty())
        cout<<"\n STACK UNDERFLOW";
    else
        cout<<"\n The top element is : "<<a[top]<<endl;
}

//display function : outputs the elements in the stack

template <class T>

void st<T>::display()

{
    if(isEmpty())
        cout<<"\n STACK UNDERFLOW";
    else
    {
        cout<<"\n The elements of the stack are : \n";
        for(int i=top;i>=0;i--)
            cout<<"\t"<<a[i];
    }
}

//main function 

main()
{
    //declaring stack object
    st<int>S(5);
    int choice;
    while(1)
    {
        cout<<"\n1.PUSH 2.POP 3.GET TOP ELEMENT 4.OUTPUT 5.EXIT";
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
