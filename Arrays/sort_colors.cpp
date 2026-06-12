//https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
//https://leetcode.com/problems/sort-colors/

// raw approach
class Solution {
  public:
    void sort012(vector<int>& arr) {
         int a=0,b=0,c=0;
        for(int i:arr){
            if(i==0)
                a++;
            if(i==1)
                b++;
            if(i==2)
                c++;
        }
        int i=0;
        while(a!=0)
        {
            arr[i++]=0;
            a--;
        }  
        while(b!=0)
        {
            arr[i++]=1;
            b--;
        }  
        while(c!=0)
        {
            arr[i++]=2;
            c--;
        }
        // for(int i:arr)  
        //     cout << i << " - - -" << endl;
    }
};
