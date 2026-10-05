//https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void){
  string x;
  cin>> x;
  unordered_map<char, int> map;
  for(char c:x)
    map[c]++;
  for(const auto& [key, val] : map){
      if(val >1)
        cout << key << " " ;
    }
  return 0;
}
