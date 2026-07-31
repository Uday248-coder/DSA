//https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1
// TIME : O(N) - iteration through entire arrays
// SPACE : O(N) -took extra vectors pos and negative to store positive and negative elements
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        vector<int> pos,neg;
        int n=arr.size();
        for(auto i:arr){
            if(i>=0)
                pos.push_back(i);
            else
                neg.push_back(i);
        }
        for(int i=0; i<pos.size() && i<neg.size() ; i++){
            arr[2*i] = pos[i];
            arr[2*i + 1] = neg[i];
        }
        if(pos.size()>neg.size()){
            int index = 2*neg.size();
            for(int i=neg.size();i<pos.size();i++){
                arr[index] = pos[i];
                index++;
            }    
        }else{
            int index = 2*pos.size();
            for(int i=pos.size();i<neg.size();i++){
                arr[index] = neg[i];
                index++;
            }    
        }
    }
};
