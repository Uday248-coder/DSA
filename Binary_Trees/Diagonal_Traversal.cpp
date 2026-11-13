// https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1





// wrong attempt
class Solution {
  public:
    void fill(Node* root, int key,unordered_map<int, vector<int>>& map){
        if(!root)
            return;
        map[key].push_back(root->data);
        if(root->left)
            fill(root->left, key-1, map);
        if(root->right)
            fill(root->right, key+1, map);
    }
    vector<int> diagonal(Node *root) {
        unordered_map<int, vector<int>> map;
        fill(root, 0, map);
        int mini=0;
        for(const auto&[key, val] : map){
            if(key < mini)
                mini = key;
        }
        vector<int> ans;
        for(int i=0;i>=mini ; i--){
            for(const auto&[key, val] : map){
                if(key >= i){
                    ans.push_back(map[key][0]);
                    map[key].erase(map[key].begin());
                }
            }
        }
        return ans;
    }
};
