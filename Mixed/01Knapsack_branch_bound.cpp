//performing 01 knapsack using branch and bound

#include <iostream>
#include <vector>
using namespace std;
// could have used this struct to simplify my array but....
struct items{
    char id;
    int val;
    int wgt;
};
vector<items> Items(100);

int n, W, bestProfit =0;
int wt[100], profit[100], id[100];
int taken[100], bestTaken[100];

// the bound function -  to produce the remaining upper bound
int bound(int level, int currW, int currP){
    if(currW >= W)
        return currP;
    int w = currW, p = currP;
    int i=level+1;
    while(i<n && w+wt[i] <=W){
        p += profit[i];
        w += wt[i];
        i++;
    }
    if(i<n){
        p += (W-w)*(profit[i] / wgt[i]);
    }
    return p;
}

// the actual calculation zone..
void solve(int level, int cw, int cp){
    
}

int main(){
    cout << "Enter number of Nodes and Knapsack Capacity: " ;
    cin >> n >>W;
    cout << "Enter Item Profits and Weights: " <<endl;
    for(int i=0;i<n;i++){
        cin >> profit[i] >> wt[i];
        id[i]=i;
    }
    for(int i=0;i<n;i++){
        taken[i]=0;
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if((double) (profit[i]/wt[i]) < (double)(profit[j]/wt[j])){
                swap(wt[i],wt[j]);
                swap(profit[i],profit[j]);
                swap(id[i],id[j]);
            }
        }
    }    
    solve(0, 0, 0);
    cout << "Maximum Profit: " << bestProfit << endl;
    cout << "Items Taken: ";
    for(int i=0;i<n;i++){
        if(bestTaken[i]){
            cout << id[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
