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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode();
        ListNode* temp = dummyNode;
        int carry = 0;
        while(l1!=NULL && l2!=NULL){
            temp -> next = l1;
            int currVal = (l1 -> val + l2->val + carry);
            carry = 0;
            if(currVal > 9){
                cout << temp -> next->val << endl;
                int rem =  currVal % 10;
                carry = currVal / 10;
                currVal = rem;
            }
            temp -> next -> val = currVal;
            l1 = l1->next;
            l2 = l2->next; 
            temp = temp->next;
        }
        while(l1 != NULL){
            temp -> next = l1;
            int currVal = (l1 -> val + carry);
            carry = 0;
            if(currVal > 9){
                cout << temp -> next->val << endl;
                int rem =  currVal % 10;
                carry = currVal / 10;
                currVal = rem;
            }
            temp -> next -> val = currVal;
            l1 = l1->next;
            temp = temp->next;
        }
        while(l2 != NULL){
            temp -> next = l2;
            int currVal = (l2 -> val + carry);
            carry = 0;
            if(currVal > 9){
                cout << temp -> next->val << endl;
                int rem =  currVal % 10;
                carry = currVal / 10;
                currVal = rem;
            }
            temp -> next -> val = currVal;
            l2 = l2->next;
            temp = temp->next;
        }
        if(carry){
            ListNode* carryNode =new ListNode();
            carryNode->val = carry;
            temp->next = carryNode; 
        }
        return dummyNode->next;
    }
};



--------------------------------------------------------------------------------------------------------------------------------------
  
  
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode();
        ListNode* temp = dummyNode;
        int carry = 0;
        while(l1!=NULL || l2!=NULL || carry){
            // temp -> next = l1;
            int currVal = ((l1 ? l1 -> val : 0) + (l2 ? l2->val : 0) + carry);
            int rem =  currVal % 10;
            carry = currVal / 10;
            temp -> next = new ListNode(rem);
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2; 
            temp = temp->next;
        }
        return dummyNode->next;
    }
};
