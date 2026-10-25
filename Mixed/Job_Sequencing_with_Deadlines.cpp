// Branch and Bound Method Used for enacting Job Sequencing with Deadlines

#include <iostream>
#include <vector>
using namespace std;
struct Jobs{
    char id;
    int deadline, profit;
};
int n,maxDeadline, bestProfit=0;
Jobs job[100];
int slot[100], bestslots[100];

bool canplace(int level){
    // if we can fit this job within max deadline, then we place it here itself
    for(int i=job[level].deadline; i>=1; i--){
        if(slot[i]==-1){
            slot[i]=level;
            return true;
        }
    }
    return false;
}

int bound(int level, int profit){
    int b=profit;
    for(int i=level;i<n;i++){
        b += job[i].profit;
    }
    return b;
}

void solve(int level, int cp){
    if(level==n){
        if(cp > bestProfit){
            for(int i=0;i<=maxDeadline;i++){
                bestslots[i]=slot[i];
            }
            bestProfit=cp;
        }
        return;
    }
    if(bound(level, cp) <= bestProfit)
        return;
    if(canplace(level)){
        solve(level+1, cp + job[level].profit);
        for(int i=1; i<=maxDeadline;i++){
            // since the job could be placed in out given schedule, we are finding in which slot was it placed and removing it..{the backtracking stage.}
            if(slot[i] == level){
                slot[i]=-1;
                break;
            }
        }
    }
    // for the branch where this job would not have been selected.
    solve(level+1, cp);
}

int main(){
    cout << "Enter Number of Jobs: " ;
    cin >> n;
    cout << "Enter Job Profits and deadlines: "<<endl;
    for(int i=0;i<n;i++){
        cin >> job[i].profit >> job[i].deadline;
        job[i].id = (char)('A' + i);
        maxDeadline = max(maxDeadline, job[i].deadline);
    }
    for(int i=0;i<100;i++){
        slot[i]=-1;
        bestslots[i]=-1;
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
    for(int i=1;i<=maxDeadline;i++){
        if(bestslots[i]!=-1){
            cout << job[bestslots[i]].id << " ";
        }
    }
    cout << endl;
    return 0;
}
