// count number of paths u can take in a 2-d maze from (0,0) to (n,n)
// put paths as n,n to get the desired numeber of paths
int paths_num(int r, int c){
  if(r==1 || c==1)
    return 1;
  return paths_num(r-1,c) + paths_num(r,c-1);
}

// prints all the direction for those n paths 
static void Paths(String p, int r, int c){
  if(c==1 && r==1){
  System.out.println(p);
    return;
  }
  // just a small modification to include diagonal movement as well
  if(c>1 && r>1)
    Paths(p+"Diagonal ",r-1, c-1);
  if(c>1)
    Paths(p+"Right ", r, c-1);
  if(r>1)
    Paths(p+"Down ", r-1, c);
}

// for if there are paths that have restrictions in between...
void Paths_Restrictions(String p,boolean Maze[][], int r, int c){
        if(c==Maze.length-1 && r==Maze.length-1){
            System.out.println(p);
            return;
        }
        if(!Maze[r][c])
            return;
        if(c<Maze.length-1 && r<Maze.length-1)
            Paths_Restrictions(p+ "Diagonal ",Maze, r+1, c+1);
        if(c<Maze.length -1)
            Paths_Restrictions(p+"Right ",Maze, r, c+1);
        if(r<Maze.length-1)
            Paths_Restrictions(p+"Down ",Maze, r+1, c);
    }


/// Here the maze can be traversed in 5 directions -- up, down, left, right, right-down diagonal
/// obstructing osbtacles can be avoided
/// Backtracking is implemented to ensure all paths are discovered without stepping on the same cell during one path itself.
class MazePaths {
    static int count = 1;

    static void Paths_Restrictions(String p, boolean[][] Maze, int r, int c) {
        if (r == Maze.length - 1 && c == Maze[0].length - 1) {
            System.out.println((count++) + ": " + p);
            return;
        }
        if (!Maze[r][c])
            return;

        Maze[r][c] = false;

        if (c < Maze[0].length - 1)
            Paths_Restrictions(p + "Right ", Maze, r, c + 1);
        if (r < Maze.length - 1)
            Paths_Restrictions(p + "Down ", Maze, r + 1, c);
        if (r < Maze.length - 1 && c < Maze[0].length - 1)
            Paths_Restrictions(p + "Diagonal ", Maze, r + 1, c + 1);
        if (c > 0)
            Paths_Restrictions(p + "Left ", Maze, r, c - 1);
        if (r > 0)
            Paths_Restrictions(p + "Up ", Maze, r - 1, c);

        Maze[r][c] = true;
    }

    static void solver(boolean[][] Maze) {
        count = 1;
        Paths_Restrictions("", Maze, 0, 0);
    }

    public static void main(String[] args) {
        int n = 3;
        int m = 4;
        boolean[][] maze = new boolean[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                maze[i][j] = true;

        solver(maze);
    }
}




