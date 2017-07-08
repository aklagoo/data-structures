#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node* next;
};

struct node *ptr, *base;

//Functions
void add(int el);
void print();

int main()
{
    //Declaration
    int input;

    //Creating node
    ptr=(node*)malloc(sizeof(node));
    ptr->next=NULL;
    base=ptr;

    //Add elements
    add(5);
    add(6);
    add(7);

    //Output
    print();

    return 0;
}

void add(int el)
{
    struct node *temp;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    temp=(node*)malloc(sizeof(node));
    ptr->next=temp;
    ptr=temp;
    ptr->data=el;
    ptr->next=NULL;
    ptr=base;
}

void print()
{
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
        cout<<(ptr->data)<<endl;
    }
}
