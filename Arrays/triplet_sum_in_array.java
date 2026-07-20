//https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

// EXPECTED COMPLEXITIES::
// TIME -- O(N^2)
// SPACE -- O(1)

// SORTING USING GAP METHOD FROM SHELL SORT AND THEN USING NESTED LOOP APPROACH TO FIND THAT TRIPLET.
class Solution {
	public boolean hasTripletSum(int arr[], int target) {
		// sorting array using gap method from shell sort.
		for (int gap = arr.length/2; gap>0; gap /= 2) {
			for (int i = gap; i<arr.length; i++) {
				int temp = arr[i];
				int j;
				for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
					arr[j] = arr[j - gap];
				}
				arr[j] = temp;
			}
		}
		
		for (int i = 0; i<arr.length - 2; i++) { // fixing one element at a time and then using two pointer approach to find the triplets that sum up to target.
			int j = i + 1;
			int k = arr.length - 1;
			while (j<k) {
				int sum = arr[i] + arr[j] + arr[k];
				if (sum == target)
					return true;
				else if (sum<target)
					j++; // since its moving from the lower values to higher values (left to right)
				else
					k--;
			}
		}
		return false;
	}
	
}
