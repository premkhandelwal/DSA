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


------------------------------------------------------------------------------------------------------------------------------------------------
//     https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1?page=1&status[]=unsolved&sortBy=submissions
    //{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    static Node* reverseList(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = head;
    while(forward != NULL){
        forward = forward -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverseList(first);
        second = reverseList(second);
        Node* temp = new Node(0);
        Node* ans = temp;
        // Node* ans = new Node(0);
        int carry = 0;
        while(first != NULL || second != NULL || carry){
            int sum = (first ? first -> data : 0) + (second ? second -> data : 0) + carry;
            int rem = sum % 10;
            carry = sum / 10; 
            ans -> next = new Node(rem); 
            first = first != NULL ? first -> next : first;
            second = second != NULL ? second -> next : second;
            ans = ans -> next;
        }
        temp = reverseList(temp -> next);
        return temp;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
