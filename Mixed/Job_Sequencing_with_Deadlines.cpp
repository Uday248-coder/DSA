// Branch and Bound Method Used for enacting Job Sequencing with Deadlines
// INCOMPLETE
#include <iostream>
#include <vector>
using namespace std;
struct Jobs{
  int id, deadline, profit;
};
int n,bestProfit=0;
Jobs job[100];
int slot[100], bestslots[100];

// have to update this bound function to be better, it is missing so so much
int bound(int level, int profit){
    int b=profit;
    for(int i=level;i<n;i++){
        b += job[i].profit;
    }
    return b;
}


void solve(int level, int cp){
    if(cp > bestProfit){
        for(int i=0;i<n;i++){
            bestslots[i]=slot[i];
        }
        bestProfit=cp;
        return;
    }
    
    
}

int main(){
    cout << "Enter Number of Jobs: " ;
    cin >> n;
    int maxDeadline;
    cout << "Enter Job Profits and deadlines: "<<endl;
    for(int i=0;i<n;i++){
        cin >> job[i].profit >> job[i].deadline;
        job[i].id = i;
        maxDeadline = max(maxDeadline, job[i].deadline);
    }
    
    // sorting based on maximum profit first
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(job[i].profit < job[j].profit){
                Jobs temp = job[i];
                job[i]=job[j];
                job[j] = temp;
            }
        }
    }

    solve(0,0);
    cout << "Maximum Profit: " << bestProfit << endl;
    for(int i=0;i<n;i++){
        if(bestslots[i]){
            cout << job[i].id << " ";
        }
    }
    cout << endl;
    return 0;
}
