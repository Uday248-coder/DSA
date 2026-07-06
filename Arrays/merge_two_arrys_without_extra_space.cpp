// https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

// TC : O()
// SC : O(1)

// given two sorted arrays a and b where a should hold the first sorted elements from a+b and b to hold the later half.. i'll use two pointer method for checking if the element from b is present in a or if its the largest.. kinda thign/

class Solution {
	public:
	void mergeArrays(vector<int>& a, vector<int>& b) {
		// have to use gap method from shell sort
		
		int gap = ((b.size() + a.size())/2) + (b.size() + a.size())%2 ;
		while (gap>0) {
			int l = 0, r = gap ;
			bool flip_l = false; // will be used to switch the pointer use of l from a to b..
			bool flip_r = false;
			if (r >= a.size()) {
				r -= a.size();
				flip_r = true ; // r will point inside the second array.
			}
// 			cout << "  GAP  " << gap << endl;
			while (true) {
			    if(flip_r && r>=b.size())
				    break;
				if (flip_l && flip_r) { // both true :: l and r both point inside array b
					if (b[l]>b[r])
						swap(b[l], b[r]);
					l++;
					r++;
				}
				else if (!flip_l && flip_r) // l points to 'a' while r points inside 'b'
					{
					if (a[l]>b[r])
						swap(a[l], b[r]);
					l++;
					r++;
					if (l >= a.size()) {
						l -= a.size();
						flip_l = true;
					}
				}
				else if (!flip_l && !flip_r) { // both point inside 'a'
					if (a[l]>a[r])
						swap(a[l], a[r]);
					l++;
					r++;
					if (l >= a.size()) {
						l -= a.size();
						flip_l = true;
					}
					if (r >= a.size()) {
						r -= a.size();
						flip_r = true;
					}
				}
				
				
			}
			if(gap==1)
			    break;
			gap = gap/2 + gap%2;
		}
	}
};

};
