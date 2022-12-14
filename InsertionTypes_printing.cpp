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
 };
 void InsertAtHead(node* &head,int d)
 {
    //new node create
    node* temp=new node(d);
    temp->next=head;
    head=temp;

 }
 //traverse a linked list
 void print(node* &head)
 {
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
 }
 void InsertAtTail(node* &tail,int d)
 {
    //new node create
    node* temp=new node(d);
    tail->next=temp;
    tail=tail->next;

 }
 void InsertAtPosition(node* &tail,node* &head,int position,int d)
 {
    if(position==1)
    {
        InsertAtHead(head,d);return;
    }
    

    node*temp= head;// we use temp to traverse in LL
    int count=1;
    while(count<position-1)
    {
        temp=temp->next;
        count++;
    }
    //insert at last node check
    if(temp->next==NULL)
    {
        InsertAtTail(tail,d);
        return ;
    }
    //creating the node to be inserted with data d
    node* newNode=new node(d);
    newNode->next=temp->next;
    temp->next=newNode;

 }
 int main()
 {
    //creating a new node
    node* node1=new node(10);//node class object
    cout<<"printing default values"<<endl;
    cout<<node1->data<<endl;
    // for object we use . and for pointer we use ->
    cout<<node1->next<<endl;

    //Singly Linked List
    
    //head pointed to node1
    node* head=node1;
    node* tail=node1;
    print(head);
    InsertAtHead(head,12);
    print(head);
    InsertAtTail(tail,15);
    print(tail);

    InsertAtPosition(tail,head,2,125);
    print(head);
    cout<<"head 's data "<<head->data<<endl;
    cout<<"tail 's data "<<tail->data<<endl;
    return 0;
 }
 