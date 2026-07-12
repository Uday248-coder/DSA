//https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

// TC: O(nlogn) sorting.. 
// SC: O(1) + O(N){auxilary space}
class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        //brute force
        //sorting it and taking the packets from 0 to m-1th index.. 
        sort(a.begin(),a.end());
        int mini=abs(a[0]-a[a.size()-1]);
        // for(int i:a)
            // cout << i << "  " ;
        // cout << endl;
        for(int i=0;i<a.size()-m+1;i++){
            // cout << "MINI " << mini << " A[i+m-1] - A[i]"<<a[i+m-1] <<"   "<<a[i]<< endl;
            mini = min(mini, abs(a[i] - a[i+m-1]));
        }
        return mini;
    }
};
