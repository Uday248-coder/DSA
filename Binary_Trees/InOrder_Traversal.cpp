//https://leetcode.com/problems/binary-tree-inorder-traversal/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


// Un-optimal Way
// TC : O(N^2)
// SC : O(N)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> right; // currently this is initialised to be empty
        if(!root){
            return right; // if the root be null, return an empty list
        }
        vector<int> left= inorderTraversal(root->left); // this will return the left sub-tree as a list
        left.push_back(root->val); // we'll process our root node
        right= inorderTraversal(root->right); // get the right sub-tree as a list
        left.insert(left.end(),right.begin(),right.end()); // concatenating all the results into onr big list.
        return left;
    }
};



// Optimal Way
// TC : O(N)
// SC : O(N)

class Solution {
public:
    void solve(TreeNode* root, vector<int>& ans){
        if(!root)
            return;
        solve(root->left, ans);
        ans.push_back(root->val);
        solve(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};
