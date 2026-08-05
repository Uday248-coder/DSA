// https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

//brute approach
// approach store the element in a map. if an element's additive inverse or its positive/negative is present as a key then store it as an array else move on.
class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        unordered_map<int,bool> map;
        int z_cnt=0; // to exceptioanlly handle zero count..
        for(int i:arr){
            map[i]=true;
            if(i==0)
                z_cnt++;
        }
        vector<vector<int>> answer;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>0 && map[-1*arr[i]]==true){
                answer.push_back({-1*arr[i],arr[i]});
                map[-1*arr[i]]=false; //to avoid duplicates.
            }
        }
        if(z_cnt>=2)
            answer.push_back({0,0});
        sort(answer.begin(),answer.end());
        return answer;
    }
};

/// using set..

class Solution {
	public:
	vector<vector<int>> getPairs(vector<int>& arr) {
		unordered_set<int> s(arr.begin(), arr.end());
		vector<vector<int>> ans;
		for (int x : s) {
			if (x > 0 && s.count(-x))
				ans.push_back({-x, x});
		}
		
		if (count(arr.begin(), arr.end(), 0) >= 2)
			ans.push_back({0, 0});
		sort(ans.begin(),ans.end());
		return ans;
	}
};
