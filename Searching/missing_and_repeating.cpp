// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
// TIme Complexity : O(N)
// Space Complexity : O(1)
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // since unsorted and arr[n] : 1-n numbders only.. 
        // to find repeating characters..  
        // what i'll do is, i'll traverse array from 0 to n, while i traverse, i'll take the element as an index by (ind -1) it 
        // and then i'll see if its previously marked negative or not.. if not that means that index is being accessed for the first time.. 
        // else if its negative, that means it was accessed before and was made negative, thereby indicating the duplicate elements arrival.
        
        int rep;
        for(int i=0;i<arr.size();i++){
            if(arr[ abs(arr[i])-1 ] < 0 ){
                rep=arr[i];
                break;
            }
            else
                arr[ abs(arr[i])-1 ] *=-1;
        }
        
        // to find the mmissing one..
        // first i'll take a variable and xor with all the elements from 1 to n except the repeating element
        // then i'll xor this result with all the elements from array..
        // except the missing onoe all other elements would cancel out their own xorss
        
        // ex -> Arr = [B, A, A]
        // Dummy = B^C {we avoid xoring the repeating element for its already duplicated in the main array}
        // when i xor -> B^C^B^A^A = (B^B) ^ C ^ (A^A) = C {since xorign with itself results in zero and xorign with zero results in itself..
        
        int xorr =1;
        for(int i=2;i<arr.size()+1;i++)
            xorr^=i; // xored with all elements from 1 to n
        
        xorr ^=abs(rep); // removing the repeating element
        for(int i=0;i<arr.size();i++){
            xorr ^=abs(arr[i]);
        }
        
        return {abs(rep), xorr};
    }
};
