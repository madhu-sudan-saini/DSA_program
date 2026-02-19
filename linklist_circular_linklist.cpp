#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

void linklistTraversal(Node* head)
{
    Node* ptr=head;
    do
    {
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }while (ptr !=head);

}

Node* insertAtFirst(Node* head,int data)
{
    Node* ptr=new Node(data);
    Node* p=head->next;

    while(p->next !=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;

    return head;
}

Node* insertAtNode(Node* head,Node* preNode,int data)
{
    Node* ptr=new Node(data);
    
    ptr->next=preNode->next;
    preNode->next=ptr;

    return head;
}

Node* insertAtIndex(Node* head,int index,int data)
{
    Node* ptr=new Node(data);
    Node* p=head;
    int i=0;

    while(i !=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;

    return head;
}

Node* insertAtEnd(Node* head,int data)
{
    Node* ptr=new Node(data);
    Node* p=head;
   
    while(p->next !=head )
    {
        p=p->next;
    }
    ptr->next=p->next;
    p->next=ptr;

    return head;
}

Node* deleteAtFirst(Node* head)
{
    Node* p = head;
    while(p->next != head)
        p = p->next;

    Node* ptr = head;
    p->next = head->next;
    head = head->next;
    delete ptr;
    return head;
}

Node* deleteAtIndex(Node* head,int index)
{
    Node* p=head;
    Node* q=p->next;
    int i=0;

    while (i !=index-1)
    {
       p=p->next;
       i++;
    }

    p->next=q->next;
    delete q;
    return head;
}

Node* deleteAtvalue(Node* head,int value)
{
    Node* p=head;
    Node* q=p->next;

    while(q->data !=value && q->next !=head)
    {
        p=p->next;
        q=q->next;
    }

    p->next=q->next;

    delete q;
    return head;
}

Node* deleteAtEnd(Node* head)
{
    Node* p=head;
    Node* q=p->next;

    while(q->next != head)
    {
        p=p->next;
        q=q->next;
    }

    p->next=q->next;

    delete q;
    return head;
}

void searchElement(Node* head,int value)
{
    Node* p=head;
    while (p->next != head)
    {
        if(p->data ==value)
        {
            cout<<"element is found";
            return;
        }
        p=p->next;
    }

    cout<<"element is not found";
    
}
int main()
{
    Node* head=new Node(10);
    Node* second=new Node(20);
    Node* third =new Node(30);
    Node* fourth = new Node(40);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=head;

    linklistTraversal(head);
    cout<<endl;

    // head=insertAtFirst(head,50);
    // linklistTraversal(head);

    // head=insertAtNode(head,second,45);
    // linklistTraversal(head);

    // head=insertAtIndex(head,3,45);
    // linklistTraversal(head);

    // head=insertAtEnd(head,45);
    // linklistTraversal(head);

    // head=deleteAtFirst(head);
    // linklistTraversal(head);

    // head=deleteAtvalue(head,30);
    // linklistTraversal(head);

    // head=deleteAtEnd(head);
    // linklistTraversal(head);

    searchElement(head,10);

    return 0;

}