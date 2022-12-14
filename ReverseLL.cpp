#include<bits/stdc++.h>
using namespace std;
//Approach 1: Iterative
 class node//node class created
 {
    public:
    int data;//data
    node *next;//address ,here next is pointer to store address

    node(int data)//constructor default
    {
        this->data=data;
        this->next=NULL;
    }
 };
 //Approach 2:Recursive
 node* reverseLinkedList(node *head)
{
    if(head==NULL||head->next==NULL)
        return head;
    else
    {
        //get the new head before changes
        node* ptr=reverseLinkedList(head->next);
        //reverse the link
        (head->next)->next=head;
        head->next=NULL;
        //return new head
        return ptr;
    }
}

