//https://leetcode.com/problems/two-sum/?envType=problem-list-v2&envId=array

//approach with linear searching and loop limits are optimised to reduce checks for duplicate pairs.
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n=nums.length;
        int ans[]=new int[2];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j] == target)
                {
                    ans[0]=i;
                    ans[1]=j;
                    return ans;
                }                  
            }
        }
        return ans;
    }
}


//approach using hashmaps
class Solution {
    public int[] twoSum(int[] nums, int target) {
        // now i'll try using hashmaps.
        int n=nums.length;
        HashMap<Integer, Integer> x =new HashMap<>();
        for(int i=0;i<n;i++){
            // x.put(nums[i],(x.get(nums[i]) == null)?1:x.get(nums[i]) + 1 );
            x.put(nums[i], i); // i'll store the integers and their indexes.
        }
        System.out.println(x);
        int ans[]=new int[2];
        for(int i=0;i<n;i++){
            if(x.containsKey(target - nums[i])){
                ans[0]=i;
                ans[1]=x.get((target - nums[i]));
            }
        }
        return ans;

        /*
        hashing fails for cases where duplicates are allowed to exist for an answer as here for [3,3]
        hashmap keeps the last index that is 1 and not the first index that is 0.
        */
    }
}


//using 2 pointer
class Solution {
    public int[] twoSum(int[] nums, int target) {
        // now i'll try using 2 pointer appraoch.
        int n=nums.length;
        int ans[]=new int[2];
        int extr[] = new int[n];
        for(int j=0;j<n;j++)
            extr[j]=nums[j];
        Arrays.sort(extr);
        int i=0, j=n-1;
        while(i<j){
            if(extr[i]+extr[j] > target){
                j--;
            }
            else if(extr[i]+extr[j] < target){
                i++;
            }
            else {
                for(int a=0;a<n;a++){
                    if(nums[a] == extr[i])
                        ans[0]=a;
                }
                for(int a=0;a<n;a++){
                    if(nums[a] == extr[j] && a!=ans[0])
                        ans[1]=a;
                }
                break;
            }
        }

        return ans;
    }
}
