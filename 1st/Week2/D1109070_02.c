#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char a,b;
    while(scanf("%c %c",&a,&b) != EOF){
        getchar();
        int num = (int) a - 'A' + 1 + (int) b - 'A' + 1;
        printf("%c\n",num + 'A' - 1);
    }
    return 0;
}