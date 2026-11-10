//https://practice.geeksforgeeks.org/problems/level-order-traversal/1

// TC : O(N)
// SC : O(N)
/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        // if(!root)
        //     return vector<int>();
        // if(!root->left && !root->right)
        //     return vector<int>(root->data);
        // vector<int> left,right;
        // if(root->left)
        //     left = levelOrder(root->left);
        // if(root->right)
        //     right = levelOrder(root->right);
        // left.insert(left.end(), right.begin(),right.end());
        // return left;
        vector<int> ans;
        queue<Node*> t;
        t.push(root);
        while(!t.empty()){
            Node* x = t.front();
            if(x->left)
                t.push(x->left);
            if(x->right)
                t.push(x->right);
            ans.push_back(x->data);
            t.pop();
        }
        return ans;
    }
};
