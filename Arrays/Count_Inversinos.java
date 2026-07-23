//https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

// EXPECTED TIME COMPLEXITIES : O(N LOGN)
// EXPECTED SPACE COMPLEXITIES : O(N)
// we'll apply merge sort and manually increment on counts.

class Solution {
	
	int count = 0;
	void mergeSort(int[] arr, int low, int high) {
		if (low >= high)
			return;
		int mid = low + (high - low)/2 ;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
	
	void merge(int[] arr, int low, int mid, int high) {
		int[] temp = new int[high - low + 1];
		int l = low;
		int r = mid + 1;
		int k = 0;
		while (l <= mid && r <= high) {
			if (arr[l] <= arr[r]) {
				temp[k++] = arr[l];
				l++;
			} else {
				temp[k++] = arr[r];
				count += (mid - l + 1);
				r++;
			}
		}
		while (l <= mid) {
			temp[k++] = arr[l++];
		}
		while (r <= high) {
			temp[k++] = arr[r++];
		}
		for (int i = low; i<=high; i++) {
			arr[i] = temp[i - low];
		}
	}
	
	public int inversionCount(int arr[]) {
	    count=0;
		mergeSort(arr,0,arr.length-1);
		return count;
	}
}
