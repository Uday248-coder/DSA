//https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

//basic approach find a prefix sum of the array where each index holds the sum of elements upto that index, now on re-traversal we check;
//if the sum at any of these index is 0 (marking elements till that index sum upto 0) or if the same sum appears twice marking the difference between them two to be zero..
// the main issue came with that re--trvaersal being O(n^2) with normal checking loops but now if i use my freq technique as used below its inefficient for real large sums..
// so vani's solution of using a hashmap is the most ideal one i beleive!

// actual implementation

class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        long long sum=0; // store the running sum
        int c=0; // to store the number of count
        unordered_map<int,int> freq;
        freq[0]=1; 
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(freq.count(sum)){
                c+=freq[sum];
            }
            freq[sum]++;
        }
        return c;
    }
};





// brute force tried, failed again
class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        int count=0;
        // first we shall deal with 0's
        int l=0,r=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                l=i;
                r=i;
                while(arr[r]==0){
                    r++;
                }
                count += (r-l)*(r-l+1) /2;
                i=r;
            }
        }
        for(int i=1;i<arr.size();i++){
            arr[i]+=arr[i-1];
        }
        unordered_map<int,int> freq;
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        for(int i=0;i<freq.size();i++){
            if(freq[arr[i]] > 2){
                bool swtch=false;
                for(int j=0;j<arr.size();j++){
                    if(arr[j]==freq[i]){
                        if(!swtch){
                            l=j;
                            swtch=true;
                        }
                        else{
                            r=j;
                            count += (r-l)*(r-l+1) /2;
                            l=j;
                            swtch=false;
                        }
                    }
                }
            }
            if(freq[i] ==0){
                count++;
            }
        }
        return count;
    }
};
