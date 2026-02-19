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
    while(head != NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL";
}

Node* insertAtFirst(Node* head,int data)
{
    Node* ptr = new Node(data);
    ptr->next=head;
    head=ptr;
    return head;

}Node* insertAtNode(Node* head,Node* prenode,int data)
{
    Node* ptr=new Node(data);
    ptr->next=prenode->next;
    prenode->next=ptr;
    return head;
}

Node* insertAtIndex(Node* head,int index,int data)
{
    Node *ptr=new Node(data);
    Node* p=head;
    int i=0;
    while(i != index-1)
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

    while(p->next != NULL)
    {
        p=p->next;
    }

    ptr->next=NULL;
    p->next=ptr;
    return head;
}

Node* deleteAtFirst(Node* head)
{
    Node* ptr=head;
    head=head->next;
    delete ptr;
    return head;
}

Node* deleteAtValue(Node* head,int value)
{
    Node* p=head;
    Node* q=p->next;

    while(q->data !=value && q->next !=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    delete q;
    return head;
}

Node* deleteAtIndex(Node* head,int index)
{
    Node* p=head;
    Node* q=p->next;
    int i=0;
    while(i != index-1)
    {
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    delete q;
    return head;
}

Node* deleteAtEnd(Node* head)
{
    Node* p=head;
    Node* q=p->next;

    while(q->next !=NULL)
    {
        p=p->next;
        q=q->next;
    }

    p->next=NULL;
    return head;
}

void searchElement(Node* head,int value)
{
    int flag=0;
    while(head !=NULL)
    {
        if(head->data ==value)
        {
            flag=1;
            break;
        }
        head=head->next;
    }

    if(flag==0)
    {
        cout<<"element not found";
    }
    else
    {
        cout<<"element found";
    }
}
int main()
{
    Node* head =new Node(10);
    Node* second =new Node(20);
    Node* third =new Node(30);
    Node* fourth =new Node(40);

    head->next=second;
    second->next=third;
    third->next=fourth;



    linklistTraversal(head);
    cout<<endl;

    // head=insertAtFirst(head,5);
    // head=insertAtFirst(head,8);
    // linklistTraversal(head);


    // head=insertAtNode(head,second,12);
    // linklistTraversal(head);


    // head=insertAtIndex(head,2,25);
    // linklistTraversal(head);


    // head=insertAtEnd(head,90);
    // linklistTraversal(head);


    // head=deleteAtFirst(head);
    // linklistTraversal(head);


    //  head=deleteAtValue(head,20);
    //  linklistTraversal(head);


    // head=deleteAtValue(head,2);
    // linklistTraversal(head);


    // head=deleteAtEnd(head);
    // linklistTraversal(head);


    searchElement(head,20);
  
    return 0;
}