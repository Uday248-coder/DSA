//https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        // just raw thought by looking at the complexities.. 
        // do we store these elements into a temp variable.. sort that temp variable and then in a linear pass.. 
        // match the difference between the actual plave and the place in orginal arrya and store the difference as count
        // for instance.. [2,4,1,3,5] --post sorting--> [1,2,3,4,5]
        // match if 2 is in 1st pos intead of its sorted 2nd pos.. that means there is an element(which here is 1) that is smaller than 2 and at a greater index than 2.
        
        // while coding i got a better thought.. instead of sorting the temp varible
        // i can make an unordered_map of original arr where it would store the array elements and their original ind. making it easier to call back when i sort thr original array instead.
        unordered_map<int,int> map;
        for(int i=0;i<arr.size();i++){
            map[arr[i]]=i;
        }
        sort(arr.begin(),arr.end());
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(map[arr[i]] < i)
                count += i - map[arr[i]];
        }
        return count;
    }
};
