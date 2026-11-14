//https://leetcode.com/problems/maximum-width-of-binary-tree/

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
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans =0;
        if(!root)
            return ans;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int s = q.size();
            long first = q.front().second;
            long long last = 0;
            for(int i=0;i<s;i++){
                auto [node, ind] = q.front();
                q.pop();
                ind -=first ; 
                last = ind;
                if(node -> left){
                    q.push({node->left, 2*ind +1});
                }
                if(node -> right){
                    q.push({node->right, 2*ind +2});
                }
            }
            ans = max(ans,(int)last+1);
        }
        return ans;
    }
};
