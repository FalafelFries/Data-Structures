//LINEAR SEARCH

#include<iostream>
#include<stdlib.h>
using namespace std;

//read function : reads elements input by the user

template <typename T>

void read(T A[], int s)
{
    for(int i=0;i<s;i++)
    {
        cout<<"\n Enter element : ";
        cin>>A[i];
    }
}

//display function : displays elements in the array

template <typename T>

void display(T A[], int s)
{
    for(int i=0;i<s;i++)
    {
        cout<<A[i]<<"\t";
    }
}

//search function : performs linear search on the given array

template <typename T>

int search(T A[], int s, T k)
{
    for(int i=0;i<s;i++)
    {
        if(A[i]==k)
            return i;
    }
    return -1;
}


//main function

main()
{
    int n, key, res;

    //getting size from the user

    cout<<"\n Enter size of the array : ";
    cin>>n;

    //declaring array of given size
    //can change datatype of the array by changing 'int' in your code

    int A[n];

    //entering elements

    cout<<"\n Enter elements of the array : ";
    read(A, n);

    //printing array

    cout<<"\n The elements in the array are : ";
    display(A,n);

    //getting key element from user

    cout<<"\n Enter key element : ";
    cin>>key;

    //searching for the element in the array
    
    res=search(A, n, key);
    if(res==-1)
        cout<<"\n Element not found";
    else
        cout<<"\n "<<key<<" found at index "<<res;
}