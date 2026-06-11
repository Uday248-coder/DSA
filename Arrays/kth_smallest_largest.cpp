//https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
// this is the kth smallest one

// using max_heap and sotring only k elements
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]); // pushes the element into stack from array.
            if(i>=k){ // when the kth limit is filled
                pq.pop(); // pops the largest element in the pq, preserving elements added so far
            }
        }
        return pq.top();    // returns the largest stored so far    
    }
};

/// so what did we do here.
// we would only take k spaces in pq.
// now we add the first k elements into pq, they automatically are rearranged and the largest of them is at the top.
// here on as we push more elements, we remove the top (the largest of the k+1 in pq), we do this until we have traversed all the elements in the arr..
// in the end the top holds the kth smallest element.
/* ex -  arr-> 2,6,3,5,1,4 k=2
          ->> pq = 6,2
          ->> pq = 6,3,2 --> 3,2
          ->> pq = 5,3,2 --> 3,2
          ->> pq = 3,2,1 --> 2,1
          ->> pq = 4,2,1 --> 2,1
          --> pq = 2 , 1 --> 2 is our ans.
*/
