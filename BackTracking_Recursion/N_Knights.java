// My intent was to make it such that we give it a board size, we tell him how many horses(knights) we want in the board and it should tell us all the possible combinations 
// in which those 'n' knights can be present on the board.

// currently works slightly, but is stick to the topmost row only, like try for board size =4 and num of knights as 1
// the desired ans would be 16 as it can be at 16 different places or if thinking symmetrically there can be only 4 combos right? 
// but the solution given by code is like 4 only but all are in top row, just the analogy in first solution that we wanted 
// where we are assuming each space as an individual space/entity, hence eliminating the scope of symmetry over there..   
import java.util.*;
class Main {
    static int count =0;
    static boolean safe(boolean b[][], int r,int c){
        // for a knight -- 
        // left up - b[r-1][c-2] && left down - b[r+1][c-2]
        // up left- b[r-2][c-1] && up right- b[r-2][c+1] 
        // right up - b[r-1][c+2] && right down - b[r+1][c+2]
        // down left- b[r+2][c-1] && down right- b[r+2][c+1] 
        
        //for our case, i dont think we need to check for down !!
        
        if(valid(b,r,c)){
            if(valid(b,r-1,c-2) && b[r-1][c-2]) return false; // left up
            if(valid(b,r-2,c-1) && b[r-2][c-1]) return false; // up left
            if(valid(b,r-2,c+1) && b[r-2][c+1]) return false; // up right
            if(valid(b,r-1,c+2) && b[r-1][c+2]) return false; // right up
        }
        return true;
    }
    static boolean valid(boolean b[][],int r, int c){
        if((c>=0 && c<b.length) && (r>=0 && r<b.length))
            return true;
        return false;
    }
    
    static void print(boolean b[][]){
        for(boolean a[]:b){
            for(boolean x:a){
                if(x)
                    System.out.print(" K ");
                else
                    System.out.print(" ~ ");
            }
            System.out.println();
        }
    }
    static void Knighter(boolean board[][], int r,int num){
        if(num == 0){   
            print(board);
            count++;
            System.out.println();
            return;
        }
        
        if(r == board.length) return;
        
        for(int i=0;i<board.length;i++){
            if(safe(board,r,i)){    
                board[r][i]=true;
                Knighter(board,r+1,num-1);
                board[r][i]=false;
            }
        }
    }
    
    public static void main(String[] args) {
        int n=4;
        boolean[][] b= new boolean[n][n];
        System.out.println("!! Solutions !!");
        Knighter(b,0,1);
        System.out.println("Total Number of Combinations: "+count);
    }
}
