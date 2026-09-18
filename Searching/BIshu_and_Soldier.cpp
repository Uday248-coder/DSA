//https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/?utm_source=header&utm_medium=search&utm_campaign=he-search

//brute force - O(N^2) time.. can be optimised
/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<int> powers(N);
	for(int i=0;i<N;i++){
		cin>>powers[i];
	}
	int Q;
	cin>>Q;
	vector<int> rounds(Q);
	for(int i=0;i<Q;i++){
		cin>>rounds[i];
	}
	vector<pair<int,int>> answer;
	for(int i=0;i<Q;i++){
		int sum=0;
		int count=0;
		for(int j=0;j<N;j++){
			if(powers[j]<=rounds[i]){
				sum+=powers[j];
				count++;
			}else{
				break;
			}
		}
		answer.push_back({count,sum});
	}
	for(pair<int,int> a: answer){
		cout << a.first << " " << a.second << endl;
	}
	return 0;
}
