// https://leetcode.com/problems/longest-palindromic-substring/
// basically we take each index, we expand on it on left and right if we have sufficient space on either side and check if the left or right characters are same(for palindrome)..
// its like expanding on each index as we find our palindrome condition being met, we do that and store the length of the palindrome found and chekc if its the maximum of all the palindromes we found so far...

int expand(String s, int l, int r){
  while(l>=0 && r<s.length() && s.charAt(l) == s.charAt(r)){
    l--;
    r++;
  }
  return (r-l-1);
}

int longest_palindrome(String s){
  if(s.length()<1 || s=="") return "";
  int start =0, end=0;
  for(int i=0;i<s.length();i++){
    int len1 = expand(s,i,i);
    int len2 = expand(s,i,i+1);
    int len = Math.max(len1,len2);
    if(len > end-start){
      start = i - (len-1)/2;
      end = i + len/2;
    }
  }
  return s.substring(start,end+1);
}
