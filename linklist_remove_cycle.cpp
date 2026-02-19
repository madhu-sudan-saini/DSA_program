#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;


    Node(int value)
    {
        data=value;
        next=NULL;
    }
};
//check cycle
Node* detectCycle(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    bool iscycle=false;

    while(fast !=NULL  && fast->next !=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow)
        {
            iscycle=true;
            break;
        }
    }

    if(!iscycle) //cycle nhi h
    {
        return NULL;
    }

    //cycle h to
    slow=head;
    Node* prev=NULL; //fast ka previos data store ke liye
    while (slow != fast)
    {
        prev=fast;
        slow=slow->next;
        fast=fast->next;
    }

    prev->next=NULL; //cycle remove
    return fast; //return slow; koi ak
}

void traversal(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL";
}
int main()
{
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third;   // 🔁 cycle

    Node* start= detectCycle(head);

    if(start != NULL)
    {
        cout<<"cycle found at node :"<<start->data<<endl;
    }
    else
    {
        cout<<"cycle not found";
    }

    traversal(head);

    return 0;
}