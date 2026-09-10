//https://www.geeksforgeeks.org/problems/optimum-location-of-point-to-minimize-total-distance/1


// it passed the public test case on first compile and test check!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// took the formula to find th foot of perpendicular from google but the rest entire logic is mineee, dont know why i explicitly said it like that!!!!!!!!! wopwooweeowoiowowoowowoowwowoowoow
class Solution {
  public:
    double findOptimumCost(vector<int>& L, vector<vector<int>>& points) {
        //my raw thoughst so far.. no maths applied.. i am just going with raw intuition here so far..
        // initial thought, find the intercept point of the foot of perpendicular of each point with respect to the main line and then find the mean point of those points..
        // let me first find the foot of perperndicular of each point and store it.
        int n = points.size();
        vector<double> x;
        vector<double> y;
        double deno = pow(L[0],2) + pow(L[1],2);
        
        double sum_x=0;
        double sum_y=0;
        
        for(int i=0;i<n;i++){   
            sum_x +=points[i][0] - ( (L[0] * (L[0]*points[i][0] + L[1]*points[i][1] + L[2])) / deno ) ;
            sum_y +=points[i][1] - ( (L[1] * (L[0]*points[i][0] + L[1]*points[i][1] + L[2])) / deno ) ;
            x.push_back( points[i][0] - ( (L[0] * (L[0]*points[i][0] + L[1]*points[i][1] + L[2])) / deno ));
            y.push_back( points[i][1] - ( (L[1] * (L[0]*points[i][0] + L[1]*points[i][1] + L[2])) / deno ));
        }
        int opt_x = (int) (sum_x / n);   
        int opt_y = (int) (sum_y / n);   
        
        double dis=0;
        for(int i=0;i<n;i++){
            dis += pow( pow(opt_x - points[i][0] , 2) + pow(opt_y - points[i][1] , 2) , 0.5);
        }
        return dis;
    }
};
