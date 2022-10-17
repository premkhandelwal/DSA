//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL, right = NULL;
    }
};
class Solution{
    public:
    Node* constructTree(Node* node,  int data, Node* &succ ){
        if(node == NULL){
            return node = new Node(data);
        }
        if(data < node -> data){
            succ = node;
            node -> left = constructTree(node->left, data, succ);
        }
        else {
            node -> right = constructTree(node->right, data, succ);
        }
        return node;
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        Node* root = NULL;
        vector<int> ans;
        for(int i = n -1; i >= 0; i--){
            Node* nextGreaterNode = NULL;
            root = constructTree(root, arr[i], nextGreaterNode );
            if(nextGreaterNode){
                arr[i] = nextGreaterNode->data;
            }else{
                arr[i] = -1;
            }
        }
        return arr;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends
