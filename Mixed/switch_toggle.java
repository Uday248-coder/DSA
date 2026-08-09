/*You are given N switches all initially in the OFF (0) state.You need to
perform Q toggle operations.

In each operation, you are given an integer i (1-based index).

For every operation, you must toggle all switches whose positions are
multiples of i.

Toggling means:

. If a switch is OFF (0) - it becomes ON (1)
. If a switch is ON (1) - it becomes OFF (0)

After performing all Q operations print the final state of all switches.
*/
import java.util.*;
class Toggle_Switch {
    
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter Number of Switchs(N): ");
        int N=sc.nextInt();
        int[] switchs=new int[N];
        System.out.print("Enter Number of Operations to perform: ");
        int Q=sc.nextInt();
        System.out.println("Initial State of Switchs: ");
        for(int i=0;i<N;i++){
            System.out.print("   "+switchs[i]);
        }
        System.out.println();
        for(int i=0;i<Q;i++){
            System.out.print("Enter Integer(i) for Operation "+i+"::");
            int k=sc.nextInt();
            for(int j=1;j*k<N;j++){
                if(switchs[(j*k)-1] ==1 ){
                    switchs[(j*k)-1]=0;
                }
                else{
                    switchs[(j*k)-1]=1;
                }
            }
        }
        System.out.println("The State of Switches:");
        for(int i=0;i<N;i++){
            System.out.print("   "+switchs[i]);
        } 
    }
}
