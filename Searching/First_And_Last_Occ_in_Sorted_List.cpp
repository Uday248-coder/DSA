//https://www.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
// Time Complexity : O(LogN)
// Space Complexity : O(1)
class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        // i think of using binary search to find that element first. if not present then -1 else.. i'll store the location and then spread outwards to get the first and last.
        int found=-1;
        int low = 0, high = arr.size()-1;
        while(low<=high){
            int mid=low + (high-low)/2;
            if(arr[mid] == x)
            {
                found = mid;
                break;
            }
            else if(arr[mid]<x)
                low=mid+1;
            else
                high=mid-1;
        }
        if(found==-1)
        {
            return {-1,-1};
        }
        else{
            int frs=found, lst=found;
            while(arr[frs-1]==arr[frs] && frs-1>=0)
                frs--;
            while(arr[lst+1]==arr[lst] && lst+1 <arr.size())
                lst++;
            return {frs,lst};
        }
    }
};
