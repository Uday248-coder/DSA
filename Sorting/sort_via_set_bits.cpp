//https://www.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1
// Expected TC: O(N LogN)
// Expected SC: O(1)

//// BRUTE FORCE APPROACH ONLY DONE SO FARRR!
// TC: O(N)
// SC: O(N^2)
class Solution {
  public:
    int find_count(int i){
        int cnt=0;
        while(i>1){
            cnt += i%2;
            i/=2;
        }
        if(i==1)
            cnt++;
        return cnt;
    }
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // brute force with extra space
        std::map<int, vector<int>, greater<int>> mapped;
        for(int i=0;i<arr.size();i++){
            int bitcount = find_count(arr[i]);
            mapped[bitcount].push_back(arr[i]);
        }
        vector<int> answer;
        for(const auto& [key, val] : mapped ){
            for(int i: val)
                answer.push_back(i);
        }
        return answer;
    }
};
