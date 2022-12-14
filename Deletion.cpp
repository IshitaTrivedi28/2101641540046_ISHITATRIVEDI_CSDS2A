 #include<iostream>
 using namespace std;

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
    //destructor
    ~node()
    {
        int value=this->data;
        //memory free
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data"<<value<<endl;
    }
 };
 //delete at position
 void Delete_position(int position,node* &head)
 {
    //deleting first node or start node
    if(position==1)
    {
        node*temp=head;
        head=head->next;
        //memory free start node
        temp->next=NULL;//as destructor code written like that
        delete temp;
    }
    else//deleting middle or last node
    {
        node* prev=NULL;
        node* curr=head;
        int count=1;
        while(count<position)
        {
            prev=curr;
            curr=curr->next;//curr = current
            count++;
        }
        prev->next=curr->next;
        curr->next=NULL;//destructr code written like that
        delete curr;


    }
 }
 void InsertAtHead(node* &head,int d)
 {
    //new node create
    node* temp=new node(d);
    temp->next=head;
    head=temp;

 }
  void print(node* &head)
 {
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
 }
  int main()
 {
    //creating a new node
    node* node1=new node(10);//node class object
    //Singly Linked List
    
    //head pointed to node1
    node* head=node1;
    node* tail=node1;
   
    InsertAtHead(head,12);
    InsertAtHead(head,15);
    InsertAtHead(head,4);
    InsertAtHead(head,1);
    Delete_position(1,head);
    print(head);
    return 0;
 }
 