//https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
// User function Template for C++
// i kind of cheated only as i dont think its optimal for rotate by n.
class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int t = arr[arr.size()-1];
        for(int i=arr.size()-1;i>=0;i--){
            arr[i] = arr[i-1];
        }
        arr[0]=t;
    }
};
