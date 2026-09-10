//https://www.geeksforgeeks.org/problems/optimum-location-of-point-to-minimize-total-distance/1
// solved via ternary search
class Solution {
  public:
    double cost(double t, double x0, double y0, double a, double b, vector<vector<int>>& points) {

        // Find the point on the line corresponding to t
        double x = x0 - b * t;
        double y = y0 + a * t;

        double ans = 0;

        // Calculate total distance from (x,y)
        // to all given points
        for (auto &p : points) {

            double dx = x - p[0];
            double dy = y - p[1];

            ans += sqrt(dx * dx + dy * dy);
        }

        return ans;
    }
  
  
    double findOptimumCost(vector<int>& L, vector<vector<int>>& points) {
        //ternary search
        int n= points.size();
        double a = L[0], b= L[1], c=L[2];
        
        // choosing an arbitary point on line
        double x0, y0;
        
        if (b != 0) {
            // choose the point where line meets y axis..
            x0 = 0;
            y0 = -c / b;
        }
        else {
            x0 = -c / a;
            y0 = 0;
        }

        // Ternary search
        double lo = -1e6;
        double hi = 1e6;

        for (int i = 0; i < 200; i++) {

            double m1 = lo + (hi - lo) / 3.0;
            double m2 = hi - (hi - lo) / 3.0;

            if (cost(m1, x0, y0, a, b, points) < cost(m2, x0, y0, a, b, points))
                hi = m2;
            else
                lo = m1;
        }

        return cost((lo + hi) / 2.0 , x0, y0, a, b, points);
    }
};




// although this was off and wrong approach as it didnt satisfy the problem.. its still good.
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
