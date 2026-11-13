// https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

// a queue approach.. the idea is still blurred but yeah it works
class Solution {
  public:
    vector<int> diagonal(Node *root) {
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            while(curr){
                if(curr->left)
                    q.push(curr->left);
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
        return ans;
    }
};

// Modified idea to be correct..
// base idea -> going right means same diagonal
// going left means a different diagonal
// so if we go to a node on rigt, we shall store it under the same key as the parent node was stored.
// but if we traverse to the left node, we shall increment the key..
class Solution {
  public:
    void fill(Node* root, int key, map<int, vector<int>>& map){ // using ordered map for sorted property.. since i need to store diagonal 0 to what ever be the number of diagonals..
        if(!root)
            return;
        map[key].push_back(root->data);
        if(root->left)
            fill(root->left, key+1, map);
        if(root->right)
            fill(root->right, key, map);
    }
    vector<int> diagonal(Node *root) {
        map<int, vector<int>> map;
        fill(root, 0, map);
        vector<int> ans;
        for(const auto&[key, val] : map){
            for(int a : val)
                ans.push_back(a);
        }
        return ans;
    }
};
