//https://leetcode.com/problems/cousins-in-binary-tree/

// a wrong attempt

class Solution {
public:
    int height(TreeNode* root, int target){
        if(!root)
            return -1;
        if(root->val == target){
            return 1;
        }
        return 1 + max(height(root->left, target), height(root->right,target));
    }
    bool notsameparent(TreeNode* root, int x, int y){
        if(!root || !root->left || !root->right)
            return true;
        if((root->left->val == x) && (root->right->val == y)){
            return false;
        }
        return ( notsameparent(root->left, x, y) && notsameparent(root->right, x, y) );
    }
    bool isCousins(TreeNode* root, int x, int y) {
        cout << "x: " << height(root, x) << endl;
        cout << "y: " << height(root, y) << endl;
        if(height(root, x) == height(root, y)){
            return (notsameparent(root, x, y)); 
        }
        return false;
    }
};
