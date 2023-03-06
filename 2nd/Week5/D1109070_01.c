#include<stdio.h>
long long f = 0,n,d[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
char m[60][60];
void dfs(int x,int y){
    if(x == n - 1 && y == n - 1 && !f){
        for(int i = 0;i < n;i++){
            printf("%s\n",m[i]);
        }
        f++;
        return;
    }else{
        for(int i = 0;i < 4;i++){
            int xx = x + d[i][0],yy = y + d[i][1];
            if(xx >= 0 && xx < n && yy >= 0 && yy < n){
                if(m[xx][yy] == '.'){
                    m[xx][yy] = 'O';
                    dfs(xx,yy);
                    m[xx][yy] = '.';
                }
            }
        }
    }
}
int main(){
    scanf("%lld",&n);
    getchar();
    for(int i = 0;i < n;i++){
        scanf("%s",m[i]);
    }
    m[0][0] = 'O';
    dfs(0,0);
    return 0;
}