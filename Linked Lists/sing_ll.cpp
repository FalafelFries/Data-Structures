#include<iostream>
#include<stdlib.h>
using namespace std;

template<class t>
class node
{
    public:
        t data;
        node<t> *next;
};

template<class t>
class ll
{
    public:
        node<t> *f;
        int lsize;
        ll();
        ~ll();
        bool empty();
        void size();
        void insert();
        void remove();
        void getindex();
        void getele();
        void display();
};

template<class t>
ll<t>::ll()
{
    f=NULL;
    lsize=0;
}

template<class t>
ll<t>::~ll()
{
    node<t> *temp = f;
    while(temp!=NULL)
    {    
        f=temp->next;
        delete temp;
        temp=f;
    }
}

template<class t>
bool ll<t>::empty()
{
    if(lsize==0)
        return true;
    else
        return false;
}

template<class t>
void ll<t>::size()
{
    if(empty())
        cout<<"\n list is empty \n";
    else
        cout<<"\n the size of the list is : "<<lsize<<endl;
}

template<class t>
void ll<t>::insert()
{
    int index;
    cout<<"\n enter index : ";
    cin>>index;
    if(index<0||index>lsize)
        cout<<"\n invalid index \n";
    else
    {
        t ele;
        cout<<"\n enter element : ";
        cin>>ele;
        node<t> *temp = new node<t>;
        temp->data=ele;
        if(index==0)
        {
            temp->next=f;
            f=temp;
        }
        else
        {
            node<t> *p=f;
            for(int i=0;i<index-1;i++)
                p=p->next;
            temp->next=p->next;
            p->next=temp;
        }
        lsize++;
        cout<<"\n success \n";
    }
}

template<class t>
void ll<t>::remove()
{
    if(empty())
        cout<<"\n list empty \n";
    else
    {
        int index;
    cout<<"\n enter index at which you want to delete : ";
    cin>>index;
    if(index<0||index>=lsize)
        cout<<"\n invalid index \n";
    else
    {
        node<t> *p=f;
        if(index==0)
        {
            f=f->next;
            cout<<"\n the deleted element is : "<<p->data<<endl;
            delete p;
        }
        else
        {
            node<t> *q;
            for(int i=0;i<index-1;i++)
                p=p->next;
            q=p->next;
            p->next=q->next;
            cout<<"\n the deleted element is : "<<q->data<<endl;
            delete q;
        }
        lsize--;
        cout<<"\n success \n";
    }
    }

}

template<class t>
void ll<t>::getindex()
{
    int ele;
    int v=0;
    cout<<"\n enter element whose index is to be found : ";
    cin>>ele;
    node<t> *temp=f;
    for(int i=0;i<lsize;i++)
    {
        if(temp->data==ele)
        {
            cout<<"\n element is at index : "<<i<<endl;
            break;
        }
        else
        {
            temp=temp->next;
            v++;
        }
    }
    if(v==lsize)
        cout<<"\n element not found \n";
}

template<class t>
void ll<t>::getele()
{
    int index;
    cout<<"\n enter index whose element is to be found : ";
    cin>>index;
    if(index<0||index>lsize-1)
        cout<<"\n invalid index \n";
    else
    {
        node<t> *temp=f;
        for(int i=0;i<index;i++)
            temp=temp->next;
        cout<<"\n element is : "<<temp->data<<endl;
    }
}

template<class t>
void ll<t>::display()
{
    if(empty())
        cout<<"\n list is empty \n";
    else
    {
        node<t> *temp = f;
        cout<<"\n the elements are : \n";
        while(temp!=NULL)
        {
            cout<<temp->data<<"\t";
            temp=temp->next;//posh.
        }
    }
}

main()
{
    ll<int>c;
    int choice;
    while(1)
    {
        cout<<"\n1.INSERT 2.REMOVE 3.GET ELEMENT 4.GET INDEX 5.SIZE 6.OUTPUT 7.EXIT\n";
        cout<<"\n input your choice : ";
        cin>>choice;
        switch (choice)
        {
            case 1 : c.insert();
                        break;
            case 2 : c.remove();
                        break;
            case 3 : c.getele();
                        break;
            case 4 : c.getindex();
                        break;
            case 5 : c.size();
                        break;
            case 6 : c.display();
                        break;
            case 7 : exit(0);
                        break;
            default : cout<<"\n invalid choice \n";
                        break;
        }
    }
}