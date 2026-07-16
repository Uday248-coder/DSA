// https://www.geeksforgeeks.org/problems/common-elements1132/1
// EXPECTED TIME COMPLEXITY --> O(N)
// EXPECTED SPACE COMPLEXITY --> O(1)

// CURRENT TIME COMPLEXITY --> O(NLOGN)
// CURRENT SPACE COMPLEXITY --> O(N)



// brute force approach -- used a freq counting map to check and match the common elements freq. 
// method passed all test cases but an optimal solution of pointer methods might exist.
class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        //using auxilary space
        unordered_map<int, int> map; // O(N) SPACE
        for(int i:a) // O(N) TIME
            map[i]=1;
        for(int i:b)
            map[i] = (map[i]==1)?map[i]+1:map[i];
        for(int i:c)
            map[i] = (map[i]==2)?map[i]+1:map[i];
        
        vector<int> ans; //O(N) SPACE
        for(auto& [key,value] : map){ // O(N) TIME
            if(value==3)
                ans.push_back(key);
        }
        sort(ans.begin(), ans.end()); // O(NLOGN) TIME + O(N) SPACE
        return ans;
    }
};

/// optimal solution
// CURRENT TIME COMPLEXITY --> O(N)
// CURRENT SPACE COMPLEXITY --> O(1)
class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // three pointer approach
        int i=0, j=0,k=0;
        vector<int> ans;
        while(i<a.size() && j<b.size() && k<c.size()){
            if(a[i]==b[j] && b[j]==c[k]){ // for duplicate avoidance
                if(ans.empty() || a[i]!= ans.back()){
                    ans.push_back(a[i]);
                }
                i++;
                j++;
                k++;
            }
            else{
                if(a[i]<b[j])
                    i++;
                else if(b[j]<c[k])
                    j++;
                else
                    k++;
            }
        }
        
        return ans;
        
    }
};
