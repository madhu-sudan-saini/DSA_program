class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

     ListNode* temp = head;
    int i=1;

    while(temp->next != NULL)
    {
        temp=temp->next;
        i++;
    }

    int x=i-k+1;

    ListNode* p = head;


    for(int j=1;j<k;j++)
    {
        p=p->next;
    }

    ListNode* q=head;

    for(int j=1;j<x;j++)
    {
        q=q->next;
    }

    swap(p->val , q->val);

    return head;

    }
};
