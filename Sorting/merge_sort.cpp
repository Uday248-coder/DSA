#include <iostream>
void mergeArray(vector<int>& a, int l, int m, int h){
    vector<int> temp;
    int i=l, j=m+1;
    while(i<=m && j<=h){
        if(a[i]<=a[j])
            temp.push_back(a[i++]);
        else
            temp.push_back(a[j++]);
    }
    while(i<=m)
        temp.push_back(a[i++]);
    while(j<=m)
        temp.push_back(a[j++]);
    
    for(int k=0;k<temp.size();k++)
        a[l+k] = temp[k];
}
void mergeSort(vector<int>& arr, int l, int h){
    if( l >=h )
    return;
    int mid = l + (h-l)/2 ;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,h);
    mergeArray(arr,l,mid,h);
}


int main() {

    return 0;
}
