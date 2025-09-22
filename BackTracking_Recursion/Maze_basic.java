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
  if(c>1)
    Paths(p+"Right ", r, c-1);
  if(r>1)
    Paths(p+"Down ", r-1, c);
}
