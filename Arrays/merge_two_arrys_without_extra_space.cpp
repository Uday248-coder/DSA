// https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

// TC : O()
// SC : O(1)

// given two sorted arrays a and b where a should hold the first sorted elements from a+b and b to hold the later half.. i'll use two pointer method for checking if the element from b is present in a or if its the largest.. kinda thign/


class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int pa=0, pb=0; // pointer of a and b respectively
        while(pb<b.size()){
            if(a[pa]>b[pb]){
                a[pa]=a[pa]^b[pb];
                b[pb]=a[pa]^b[pb];
                a[pa]=a[pa]^b[pb];
                // pb=(pb+1<b.size())?pb+1:pb;
            }
            pa++;
            if(pa>a.size()){
                pb++;
                pa=0;
            }
        }
        for(pb=0;pb<b.size()-1;pb++){
            for(pa=pb+1;pa<b.size();pa++){
                if(b[pa]<=b[pb]){
                    b[pa]=b[pa]^b[pb];
                    b[pb]=b[pa]^b[pb];
                    b[pa]=b[pa]^b[pb];
                }
            }
        }
    }
};
