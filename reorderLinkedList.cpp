/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  //move is a variable to keep track if we ll cross the middle node or not.
  //if(move > (size/2) it means we havent crossed it while traversing in reverse
  //if(move == (size/2) it means we are the middle node
    void reorder(ListNode **head, ListNode *right, ListNode **left, int move, int size)
    {
        if(right == NULL)
            return;
        else
        {
            //keep calling the function for the next node of right until the base case is encountered
            reorder(&(*head),right->next,&(*left),move+1,size);
            //after the right node reaches the tail of the linked list it can now start wiping out values from it's recursion stack one by one
            //to keep track if we have reached the middle node or not
            if(move > (size/2))
            {
                //this is what was told in the first paragraph
                ListNode *temp = (*left)->next;
                (*left)->next = right;
                right->next = temp;
                *left = temp;
            }
            else if(move == (size/2))
            {
                //if we are exactly in the middle node then the next node must be NULL
                //this can be understood in more clarity after dry running the code
                right->next = NULL;
            }
        }
    }
    //to get the size of the linked list
    int getSize(ListNode *head)
    {
        ListNode *temp = head;
        int size = 0;
        while(temp != NULL)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return;
        ListNode *left = head, *right = head;
        ListNode *temp = head;
        int size = getSize(head);
       
        //not that we pass the left pointer by reference so that all the changes are reflected. This can also be done by making the left pointer as global
        reorder(&head,right,&left,0,size);
        
    }
};
