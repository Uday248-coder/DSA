// not correct, just tried at the moment, first attempt!.

import java.util.*;
class Main {
    static void print(boolean b[][]){
        for(boolean a[]:b){
            for(boolean x:a){
                if(!x)
                    System.out.print(" Q ");
                else
                    System.out.print(" ~ ");
            }
            System.out.println();
        }
    }
    static void queener(boolean board[][], int r, int c){
        if(r==board.length -1 || c == board.length-1){   
            print(board);
            return;
        }
        if(r==0){
            for(int i=0;i<board.length;i++){
                board[r][c]=false;
                queener(board,i+1,0);
                board[r][c]=true;
            }
        }
        if((c>0 && board[r-1][c-1]) && board[r-1][c] && (board[r-1][c+1]) && c<board.length-1){
            board[r][c]=false;
            queener(board,r+1,0);
            board[r][c]=true;
        }
        else
            queener(board,r,c+1);
    }
    
    public static void main(String[] args) {
        boolean[][] b= {
            {true,true,true},
            {true,true,true},
            {true,true,true}
        };
        queener(b,0,0);
        
        System.out.println("Try programiz.pro");
    }
}
