// count number of paths u can take in a 2-d maze from (0,0) to (n,n)
// put paths as n,n to get the desired numeber of paths
int paths(int r, int c){
  if(r==1 || c==1)
    return 1;
  return paths(r-1,c) + paths(r,c-1);
}
