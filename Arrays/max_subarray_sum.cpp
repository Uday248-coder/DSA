// using Divide and conqueor method.
// TIME : O(N LOGN) ~~ can be done in O(N) using kadence's algorithm

#include <iomanip>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int crossSubarray(vector<int>& arr, int low, int mid, int high){
  int leftsum=-1000000,rightsum = -1000000;
  int sum=0;
  for(int i=mid; i>=low;i--){
    sum+=arr[i];
    leftsum = max(leftsum,sum);
  }
  sum=0;
  for(int i=mid+1; i<=high;i++){
    sum+=arr[i];
    rightsum = max(rightsum,sum);
  }
  return (leftsum + rightsum);
}
int maxSubarray(vector<int>&arr, int low, int high){
  if(low == high) return arr[low];
  int mid = low + (high-low)/2;
  int leftbest = maxSubarray(arr, low, mid);
  int rightbest = maxSubarray(arr, mid+1,high);
  int crossbest = crossSubarray(arr, low, mid,high);
  return max(max(leftbest, rightbest), crossbest);
}
int main(){
  int n;
  cout << "enter number of elements: "<< endl;
  cin >> n;
  vector<int> arr;
  cout << "Enter elements" << endl;
  int x;
  for(int i=0;i<n;i++){
    cin >> x;
    arr.push_back(x);
  }
  cout << "Max-Subarray-Sum == " << maxSubarray(arr,0,n-1) << endl;
}
