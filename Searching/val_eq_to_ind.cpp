//https://www.geeksforgeeks.org/problems/value-equal-to-index-value1330/1
class Solution {
  public:
    vector<int> valEqualToPos(vector<int>& arr) {
        // code here
        vector<int> answer;
        for(int i=0;i<arr.size();i++){
            if((i+1) == arr[i])
                answer.push_back((i+1));
        }
        return answer;
    }
};
