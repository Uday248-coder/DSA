//https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1

// TC : O(N)
// SC : O(N)

/* Structure of Binary Tree Node
class Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> ans;
        vector<vector<int>> level;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> curr;
            for(int i=0;i<size;i++){
                Node* x = q.front();
                q.pop();
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
                curr.push_back(x->data);
            }
            level.push_back(curr);
        }
        
        for(int i=0;i<level.size();i++){
            if(i%2 == 0){
                for(int j=0;j<level[i].size();j++){
                    ans.push_back(level[i][j]);
                }   
            }else{
                for(int j=level[i].size()-1;j>=0;j--){
                    ans.push_back(level[i][j]);
                }
            }
        }
        return ans;
    }
};
