class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if(head == NULL || head->next == NULL)
        {
            return NULL;
        }
       ListNode* temp =head;
       int n=0;

        while(temp != NULL)
        {
            temp=temp->next;
            n++;
        }

        int mid=n/2;


        ListNode* p=head;
        ListNode* q=p->next;
        int i=0;

        while(i != mid-1)
        {
            p=p->next;
            q=q->next;
            i++;
        }

        p->next=q->next;
        delete q;

        return head;

    }
};
