//https://www.geeksforgeeks.org/problems/middle-of-three2926/1

// brute-force approach :: 3 comparisons
class Solution {
  public:
    int middle(int a, int b, int c) {
        if(a<b)
        {
            if(a>c)
                // two comparisons done till herer
                return a;
            else if(b>c)
                // three comparisons done till here
                return c;
            else
                // three comparisons done till here
                return b;
        }
        else if(c>b) //if here then already a > b due to first check, there if a>b && c>b
            if(a<c)
                // three comparisons made so far
                return a;
            else
                // three comparisons made so far
                return c;
        else 
            return b;
    }
};


// optimal approach : 2 comparisons
class Solution {
  public:
    int middle(int a, int b, int c) {
        if(a<b){ // a<b
            if(c<a) // --> c<a<b
                return a;
            if(c>b) // --> a<b<c
                return b;
            return c; // a<c<b
        }else{ // b<a
            if(c<b) // --> c<b<a
                return b;
            if(c>a) // --> b<a<c
                return a;
            return c; // b<c<a
        }
        
    }
};
