class Solution {
    // so basically we move the array in bottom-left direction until there is no space to move, each traversed element is made -1 to
    static ArrayList<Integer> diagView(int mat[][]) {
        ArrayList<Integer> x = new ArrayList<Integer>();
        int n=mat.length;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int r=i;
                int k=j;
                if(mat[r][k]==-1) continue;
                while(r>=0 && r<n && k>=0 && k<n){
                    x.add(mat[r][k]);
                    mat[r][k]=-1;
                    r++;
                    k--;
                }
            }
        }
        return x;
        
    }
}
