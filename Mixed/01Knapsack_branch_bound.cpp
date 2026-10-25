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

int n, W, bestProfit =0; // n -  number of nodes, W - Knapsack Capacity, bestProfit - the best Profit found so far
int wt[100], profit[100], id[100]; // item values
int taken[100], bestTaken[100]; // which all items are taken

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
        p += (W-w)*(profit[i] / wt[i]);
    }
    return p;
}

// the actual calculation zone..
void solve(int level, int cw, int cp){
    if(level == n){
        if(cp>bestProfit){
            for(int i=0;i<n;i++){
                besttaken[i]=taken[i];
            }
            bestProfit = cp;
        }
        return;
    }
    if(cw + wt[level] <=W){
        taken[level] = 1;
        int nw = cw + wt[level];
        int np = cp + profit[level];
        if(np > bestProfit){
            for(int i=0;i<n;i++){
                besttaken[i]=taken[i];
            }
            bestProfit = np;
        }
        if(bound(level, nw, np) > bestProfit){
            solve(level+1, nw, np);
            taken[level]=0;
        }
        if(bound(level, cw, cp) > bestProfit){
            solve(level+1, cw, cp);
        }
    }
}

int main(){
    cout << "Enter number of Nodes and the Knapsack Capacity: " ;
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
    solve(0, 0, 0); // start at level=0 or first node with intial weights and profit as 0
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
