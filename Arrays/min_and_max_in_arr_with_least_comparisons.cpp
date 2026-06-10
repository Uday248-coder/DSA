// finding the minimuma nd maximum elements of an array with least comparisons

#include <iostream>
#include <vector>

using namespace std;
int main(void){
  vector<int> arr = {1,2,3,4,5,6,7};
  int mini=arr[0], maxi=arr[0];
  
  //basic single traversal method.
  for(int i:arr){
    if(mini>i)
        mini=i;
    if(maxi<i)
        maxi=i;
  }

  //more optimal approach
  // the approach is basically we will compare the elements in pairs of 2. 
  // now earlier for each element we used to compare whether its greater than maxi or smaller than mini right? -> thats 2 comparisons per element hence total comparisons = 2*n
  // here we first compare between the pair selected to check which is grater amongst the two, then only compare the greter among the two with maxi and the later with mini --> thereby we have only 3 comparisons per 2 elements.
  // making the total count to be -> 3*(n)/2
  for(int i=0;i<n-1;i+=2){
    if(arr[i] < arr[i+1])
      if(arr[i] < mini)
          mini = arr[i]
      if(arr[i+1] > maxi)
          maxi = arr[i+1];
    else
      if(arr[i+1] < mini)
          mini = arr[i+1]
      if(arr[i] > maxi)
          maxi = arr[i];
  }
  
  
  
}
