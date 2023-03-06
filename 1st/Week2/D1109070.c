#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int main(){
    char type='\0',s[] = "Hello,World!";
    printf("The sleep time is:");
    printf("(a:200 b:300 c:500) ");
    int time;
    scanf("%c",&type);
    if(type == 'a'){
        time = 200;
    }else if(type == 'b'){
        time = 300;
    }else if(type == 'c'){
        time = 500;
    }
    int i=0;
    while(1){
        system("cls");
        for(int j = 0;j < 12;j++){
            printf("%c\n",s[(i+j)%12]);
        }
        Sleep(time);
        i = (i+1)%12;
    }
    return 0;
}