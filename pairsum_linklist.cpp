class Solution {
public:
    int pairSum(ListNode* head) {

       if(head == NULL)
       {
        return NULL;
       } 

       ListNode* temp = head;
       int n=1;
       while(temp->next != NULL)
       {
        temp = temp->next;
        n++;
       }

       ListNode* left = head;
       ListNode* right = temp;

      int maxVal = INT_MIN;

       for(int i=0;i<n/2;i++)
       {
            int sum = left->val + right->val;

            maxVal = max(maxVal,sum);

            left=left->next;

            temp=head;

            while(temp->next != right)
            {
                temp=temp->next;
            }

            right = temp ;
       }

       return maxVal;
    }
};
