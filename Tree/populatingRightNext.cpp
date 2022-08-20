// -------------------------------------------------------------------------Not Working ---------------------------------------------------------------------
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q = {};
        Node* prev = NULL;
        vector<Node*> ans = {};
        q.push(root);
        // ans.push_back(root);
                // ans.push_back(root);
        // q.push(NULL);
        if(root == NULL){
            return NULL;
        }
        while(!q.empty()){
            Node* ele = q.front();
            ans.push_back(ele);
            
            // cout << ele -> val << endl;
            // q.pop();
            if(ele -> left != NULL && ele -> right != NULL){
                prev = ele;
                q.push(ele->left);
                q.push(ele->right);
                // ele -> left -> next = ele -> right;
                // prev -> next = ele;
                // prev = NULL;
            }
            
            ans.push_back(root);
            // q.push(NULL);
            
            
        } 
        return ans[0];
    }
};

---------------------------------------------------------------------------------------------------------------------------------------------------------------
  
