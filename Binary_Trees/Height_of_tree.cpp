//https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

// TC : O(N)
// SC : O(N)

/* Structrue of Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int height(Node* root) {
        if(!root){
            return -1;
        }
        return 1 + max(height(root->left), height(root->right));
    }
};
