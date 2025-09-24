// not correct, just tried at the moment, first attempt!.
// logic change, board will be empty before, we add in true for queen and rest as false..
// base working -- we check from 0 to that place, if any queen exists, we move on..
import java.util.*;
class Main {
    static boolean safe(boolean b[][], int r,int c){
        for(int i=0;i<r;i++)
            if(b[i][c])
                return false;
        for(int i=0;i<c;i++)
            if(b[r][i])
                return false;
        int l_diag_reach = (r>c)?c:r; // these checks were the issue
        for(int i=1;i<=l_diag_reach;i++) // these checks were the issue
            if(b[r-i][c-i])
                return false;
        int r_diag_reach = (r> (b.length - c-1))?(b.length - c-1):r; // these checks were the issue
        for(int i=1;i<=r_diag_reach;i++) // these checks were the issue
            if(b[r-i][c+i])
                return false;
        return true;
    }
    
    static void print(boolean b[][]){
        for(boolean a[]:b){
            for(boolean x:a){
                if(x)
                    System.out.print(" Q ");
                else
                    System.out.print(" ~ ");
            }
            System.out.println();
        }
    }
    static void queener(boolean board[][], int r){
        if(r==board.length){   
            print(board);
            System.out.println();
            return;
        }
        for(int i=0;i<board.length;i++){
            if(safe(board,r,i)){    
                board[r][i]=true;
                queener(board,r+1);
                board[r][i]=false;
            }
        }
    }
    
    public static void main(String[] args) {
        int n=4;
        boolean[][] b= new boolean[n][n];
        System.out.println("!! Solutions !!");
        queener(b,0);
    }
}
