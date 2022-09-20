//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        Node* forward = head;
        Node* curr = head;
        Node* prev = NULL;
        int i = 0;
        while(i != k - 1){
            forward = forward -> next;
            curr-> next = prev;
            prev = curr;
            curr = forward;
            i++;
        }
        Node* forward1 = forward;
        Node* curr1 = prev;
        Node* prev1 = NULL;
        while(forward1 != NULL){
            forward1 = forward1 -> next;
            curr1-> next = prev1;
            prev1 = curr1;
            curr1 = forward1;
        }
        Node* forward2 = head;
        Node* curr2 = head;
        Node* prev2 = NULL;
        while(forward2 != NULL){
            forward2 = forward2 -> next;
            curr2-> next = prev2;
            prev2 = curr2;
            curr2 = forward2;
        }
        return curr2;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        if(!head || !head -> next || k==0){
            return head;
        }
        Node* temp = head;
        int len = 1;
        while(temp -> next != NULL){
            temp = temp -> next;
            len++;
        }
        temp-> next = head;
        k = k % len;
        // k = len - k;
        while(k > 0){
            temp = temp->next;
            k--;
        }
        head = temp->next;
        temp-> next = NULL;
        return head;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends
