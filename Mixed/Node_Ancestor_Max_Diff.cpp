// https://www.geeksforgeeks.org/problems/maximum-difference-between-node-and-its-ancestor/1
// Must revisit
class Solution {
    int max_diff = INT_MIN;

    int helper(Node* root) {
        if (!root) return INT_MAX;
        
        if (!root->left && !root->right) return root->data;

        int min_left = helper(root->left);
        int min_right = helper(root->right);

        int min_child = min(min_left, min_right);

        max_diff = max(max_diff, root->data - min_child);

        return min(root->data, min_child);
    }

  public:
    int maxDiff(Node* root) {
        max_diff = INT_MIN;
        helper(root);
        return max_diff;
    }
};
