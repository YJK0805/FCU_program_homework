int tribonacci(int n)
{
    if(n == 0 || n == 1 || n == 2){
        return n;
    }else{
        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
}
