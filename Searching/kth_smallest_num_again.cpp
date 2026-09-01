//https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/kth-smallest-number-again-2/?purpose=login&source=problem-page&update=google

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>>t;
	while(t>0){
		int n,q;
		cin >> n >> q;
		vector<pair<long long, long long>> range(n);
		for(int i=0;i<n;i++){
			cin >> range[i].first >> range[i].second;
		}
		sort(range.begin(),range.end());
		vector<pair<long long, long long>> merged;
		for(const auto& r: range){
			if(merged.empty() || merged.back().second < r.first){
				merged.push_back(r);
			}else{
				merged.back().second = max(merged.back().second, r.second);
			}
		}

		while(q--){
			long long k;
			cin >> k;
			long long ans=-1;
			for(const auto& interval: merged){
				long long count = interval.second - interval.first +1;
				if(k<=count){
					ans = interval.first + k-1;
					break;
				}
				k-=count;
			}
			cout << ans << endl;
		}
		t--;
	}
	return 0;
}
