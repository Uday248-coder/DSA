#include <iostream>
int partitionArray(vector<int>& a, int l, int h){
    int pivot = a[h];
    int i= l-1;
    for(int j=l;j<h;j++){
        if(a[j]<=pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1], a[h]);
    return i+1;
}
void quicksort(vector<int>& a, int low, int high){
    if(low>=high) return;
    int p = partitionArray(a,low,high);
    quicksort(a,low,p-1);
    quicksort(a,p+1,high);
}

int main() {

    return 0;
}
