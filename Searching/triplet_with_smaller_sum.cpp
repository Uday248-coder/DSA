//https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

// TC : O(N^2)
// SC : O(1)

// brute force --  tried 2-pointer over a fixed .. 
class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        int count = 0;
        for(int i=0;i<arr.size();i++){
            int l=i+1;
            int r=arr.size()-1;
            while(l<r){
                int curr= arr[i]+arr[l]+arr[r];
                if(curr < sum){
                    // cout <<  arr[i] << " " << arr[l] <<" "<<arr[r] << endl;
                    count++;
                    // l++;
                    r--;
                }else if(curr > sum){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return count;
    }
};

// brute-force 2 || didnt work for test cases.. can't identify the problem yet..
class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        int count =0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                int x=j+1;
                while(arr[i]+arr[j]+arr[x] < sum && x<arr.size()){
                    // cout << arr[i] << " " << arr[j] << " " <<  arr[x] << endl;
                    count++;
                    x++;
                }
            }
        }
        return count;
    }
};
