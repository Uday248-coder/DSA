//https://www.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1
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
