#include<stdio.h>
int main(){
    unsigned int x;
    char c;
    long long n;
    scanf("%u",&x);
    while(scanf("%c %lld",&c,&n) != EOF){
        switch(c){
            case '&':
                x = x & n;
                printf("%u\n",x); 
                break;
            case '|':
                x = x | n;
                printf("%u\n",x);
                break;
            case '^':
                x = x ^ n;
                printf("%u\n",x);
                break;
            case '<':
                x = x << n;
                printf("%u\n",x);
                break;
            case '>':
                x = x >> n;
                printf("%u\n",x);
                break;
            case '~':
                x = ~x;
                printf("%u\n",x);
                break;
        }
    }
    return 0;
}