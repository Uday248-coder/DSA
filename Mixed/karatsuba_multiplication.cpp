// Karatsuba Multiplication using Divide and Conquer.
// Reduces recursive multiplications from 4 to 3.

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int digits(long long a){
  if(a==0)
      return 1;
  int cnt=0;
  while(a>0){
    cnt++;
    a/=10;
  }
  return cnt;
}

long long karatsuba(long long x, long long y){
  if(x<10 || y<10)
      return x*y;
  int n = max(digits(x),digits(y));
  int half = n/2;
  int power = pow(10,half);
  long long a = x/power;
  long long b = x%power;
  long long c = y/power;
  long long d = y%power;
  long long ac = karatsuba(a,c);
  long long bd = karatsuba(b,d);
  long long ad_bc = karatsuba(a+b,c+d) - ac - bd;
  return ac*power*power + ad_bc*power + bd;
}
