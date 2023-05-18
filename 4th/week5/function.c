/*
#include<stdio.h>

char *hello(char *name)
{
    char *str = malloc(150);
    sprintf(str,"Hello %s.\n",name);
    return str;
}

char *hi(char *name)
{
    char *str = malloc(150);
    sprintf(str,"Hi %s.\n",name);
    return str;
}

char *hey(char *name)
{
    char *str = malloc(150);
    sprintf(str,"Hey %s.\n",name);
    return str;
}
//*/

char *(*chooseGreetings(int type))(char *){
    if(type == 0){
        return hello;
    }else if(type == 1){
        return hi;
    }else if(type == 2){
        return hey;
    }
}

/*
int main(void) { //容易看懂的版本
    char *name = malloc(100);
    int type;
    char *(*func)(char *);
    while(scanf("%d %s",&type,name) != EOF)
    {
        func = chooseGreetings(type);
        char *str = (*func)(name);
        printf("%s",str);
        free(str);
    }
    free(name);
    return 0;
}
//*/
/*
int main(void) { //測式時實際使用的版本
    char *name = malloc(100);
    int type;
    while(scanf("%d %s",&type,name) != EOF)
    {
        char *str = (*chooseGreetings(type))(name);
        printf("%s",str);
        free(str);
    }
    free(name);
    return 0;
}
//*/