//https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int i=0,j=0;
        int last=0;
        if(k == a.size()+b.size())
            return max(a[a.size()-1],b[b.size()-1]);
        for(int m=0;m<k;m++){
            if((i<a.size()) && ((j>=b.size())||(a[i]<=b[j]))){
                last = a[i];
                i++;
            }else{
                last=b[j];
                j++;
            }
        }
        return last;
    }
};
