//https://www.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1
// this approach uses extra space.. if we have to segregate positive's and negative's in constant space then a new approach is needed right.
class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        // vector<int> nl;
        // for(int i=0;i<arr.size();i++){
        //     if(arr[i]<0){
        //         nl.push_back(arr[i]);
        //         arr.erase(arr.begin() + i);
        //         i--;
        //     }
        // }
        // for(int i:nl)
        //     arr.push_back(i);
        //the above thingy is giving tle due to erase function.
        
        vector<int> mute;
        for(int i:arr){
            if(i>=0)
                mute.push_back(i);
        }
        for(int i:arr){
            if(i<0)
                mute.push_back(i);
        }
        arr.clear();
        for(int i:mute)
            arr.push_back(i);
    }
};


// the constant space solution :: using two pointer partition approach.

vector<int> move(vector<int> &arr) {
  int l=0, r=arr.size()-1;
  while(l < r){
    while(l<r && arr[l]<0){ // ignore the negatives that are in extreme left (in their respective ends)
      l++;
    }
    // now l points to the leftmost positive element;
    while(r>l && arr[r]>0){ // sameways move past all the positive elements as they are in their respective corner
      r--;
    } //  r points to the rightmost negative number
    if(l<r){ // if still left is less than right, that means they are not in their correct position, hence swap them.
      swap(arr[l],arr[r]);
      l++;
      r--;
    }
  }
  return arr;
}
