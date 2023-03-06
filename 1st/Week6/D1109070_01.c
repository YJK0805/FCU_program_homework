int GCD3(int x,int y,int z)
{
    // write your code here
  int gcd(int x,int y){
        if(x % y){
            return gcd(y,x % y);
        }else{
            return y;
        }
    }
    return gcd(gcd(x,y),z);
}