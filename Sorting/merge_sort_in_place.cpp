// TC: O(n^2)
// SC: O(1)


#include <iostream>
#include <vector>
using namespace std;

void merger(vector<int>& arr, int l, int m, int h){
    int i=l, j=m+1;
    if (arr[m] <= arr[j]) {
        return;
    }
    
    while(i<=m && j<=h){
        if(arr[i]<arr[j])
            i++;
        else{
            int temp=arr[j];
            for(int x=j;x>i;x--){
                arr[x]=arr[x-1]; 
            }
            arr[i]=temp;
            i++;
            j++;
            m++;
        }
    }
}

void mergeSort(vector<int>& arr, int l, int h){
    if(l<h){
      int m= l+ (h-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, h);
        merger(arr, l, m, h);
    }
}
int main(void){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    mergeSort(arr, 0, n-1);

    for(int i:arr)
        cout << i << " ";
    cout << endl;
    
    return 0;
}
