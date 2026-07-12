//https://www.geeksforgeeks.org/problems/find-the-median0527/1

class Solution {
  public:
    double findMedian(vector<int> &arr) {
        // code here.
        sort(arr.begin(), arr.end());
        int N = arr.size();
        if(N%2 == 0){
            return (arr[(N/2)-1] + arr[(int)(N/2)])/2.0 ;
        }
        else
            return arr[((N+1)/2)-1];
    }
};
