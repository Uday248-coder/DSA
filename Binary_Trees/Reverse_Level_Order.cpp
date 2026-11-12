//https://www.geeksforgeeks.org/problems/reverse-level-order-traversal/1


// this one was learned and implemented.. here i am first extracting the nodes level by level and storing as a joint level as well.. then only i am working it out from last to first level ... as required
class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        vector<int> ans;
        vector<vector<int>> bylevel;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> curr;
            for(int i=0;i<size;i++){
                Node* x = q.front();
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
                curr.push_back(x->data);
                q.pop();
            }
            bylevel.push_back(curr);
        }
        for(int i=bylevel.size()-1 ; i>=0; i--){
            for(int a : bylevel[i]){
                ans.push_back(a);
            }
        }
        return ans;
    }
};


// I purely Lucked Out on this one
// for i thought my logic was weak
// here i was thought i'll take the elements in queue in the way you extract them in level order traversal
// then i'll push them into a stack so that i can tae advantage of the last-in-first-out principle to help me with getting the reverse order
// then while analysing my wrong public test case attempt, i just tweaked the position of discovering the left and right node's storing in the stack and it somehow solved it!!!!!!

/* Structure of Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right; 
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        vector<int> ans;
        queue<Node*> t;
        t.push(root);
        stack<Node*> l;
        while(!t.empty()){
            Node* x = t.front();
            l.push(x);
            t.pop();
            if(x->right)
                t.push(x->right);
            if(x->left)
                t.push(x->left);
        }
        while(!l.empty()){
            ans.push_back((l.top())->data);
            l.pop();
        }
        return ans;
    }
};
