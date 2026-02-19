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
bool hascycle(Node* head)
{
    Node* slow=head;
    Node* fast=head;

    while(fast !=NULL  && fast->next !=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;

            if(fast==slow)
            {
                return true;
            }
        }
    return false;
}

int main()
{
    Node* head=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    Node* fourth=new Node(40);
    Node* fifth=new Node(50);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    // fifth->next=third;  //cycle is present
    fourth->next=fifth;    //cycle is not present


    if(hascycle(head))
        cout << "Cycle is Present";
    else
        cout << "Cycle is NOT Present";

    return 0;

    return 0;
}