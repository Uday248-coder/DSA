// reversing an array
// final 450..

#include <iodtream>
#include <vector>
using namespace std;

int main(void){
  vecotr<int> arr = {1,2,3,4,5,6};
  int temp, n=arr.size();
  for(int i=0;i<(int)(n/2);i++){
    temp = arr[i];
    arr[i]= arr[n-i-1];
    arr[n-i-1] = temp;
  }
}
