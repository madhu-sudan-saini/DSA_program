#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void linklistTraversal(Node* head)
{
    Node* p = head;
    while(p != NULL)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << "NULL" << endl;
}

Node* insertAtFirst(Node* head, int data)
{
    Node* ptr = new Node(data);

    ptr->next = head;
    if(head != NULL)
        head->prev = ptr;

    head = ptr;
    return head;
}

Node* insertAtIndex(Node* head, int index, int data)
{
    Node* ptr = new Node(data);
    Node* p = head;
    int i = 0;

    while(i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    ptr->prev = p;

    if(p->next != NULL)
        p->next->prev = ptr;

    p->next = ptr;

    return head;
}

Node* insertAtEnd(Node* head, int data)
{
    Node* ptr = new Node(data);

    if(head == NULL)
        return ptr;

    Node* p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->prev = p;

    return head;
}

Node* insertAtNode(Node* head, Node* preNode, int data)
{
    Node* ptr = new Node(data);

    ptr->next = preNode->next;
    ptr->prev = preNode;

    if(preNode->next != NULL)
        preNode->next->prev = ptr;

    preNode->next = ptr;

    return head;
}

Node* deleteAtFirst(Node* head)
{
    if(head == NULL)
        return NULL;

    Node* p = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    delete p;
    return head;
}

Node* deleteAtIndex(Node* head, int index)
{
    Node* p = head;
    int i = 0;

    while(i != index)
    {
        p = p->next;
        i++;
    }

    p->prev->next = p->next;
    if(p->next != NULL)
        p->next->prev = p->prev;

    delete p;
    return head;
}

Node* deleteAtValue(Node* head, int value)
{
    Node* p = head;
 

    while(p !=NULL &&  p->data !=value)
    {
        p = p->next;
    }

    p->prev->next = p->next;
    if(p->next != NULL)
        p->next->prev = p->prev;

    delete p;
    return head;
}

Node* deleteAtEnd(Node* head, int value)
{
    Node* p = head;
    
    while (p->next !=NULL)
    {
        p=p->next;
    }

    p->prev->next=NULL;
    
    delete p;
    return head;
}

void seachElement(Node* head,int val)
{
    while(head !=NULL)
    {
        if(head->data==val)
        {
            cout<<"element found";
            return;
        }

        head=head->next;
    }
    cout<<"element not found";
}
int main()
{
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    // Linking nodes (IMPORTANT for DLL)
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    linklistTraversal(head);

    // head = insertAtFirst(head, 5);
    // linklistTraversal(head);

    // head = insertAtIndex(head, 2, 25);
    // linklistTraversal(head);

    // head = insertAtNode(head, second, 22);
    // linklistTraversal(head);

    // head = insertAtEnd(head, 50);
    // linklistTraversal(head);

    // head = deleteAtFirst(head);
    // linklistTraversal(head);

    // head = deleteAtIndex(head, 2);
    // linklistTraversal(head);

    // head = deleteAtValue(head, 20);
    // linklistTraversal(head);

    // head = deleteAtEnd(head, 20);
    // linklistTraversal(head);

    seachElement(head,40);




    return 0;
}
