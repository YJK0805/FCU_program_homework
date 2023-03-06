/*
#include <stdio.h>

int   my_strlen(const char*);
char* my_strcpy(char*,const char*);
int   my_strcmp(const char*,const char*);
char* my_strcat(char*,const char*);
int   my_atoi(const char*);
//*/

int my_strlen(const char* str)
{
    /* Write your code here */
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

char* my_strcpy(char* destination,const char* source)
{
    /* Write your code here */
    int i = 0;
    while(source[i] != '\0'){
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
    return destination;
}

int my_strcmp(const char* str1,const char* str2)
{
    /* Write your code here */
    int i = 0;
    while(str1[i] != '\0' && str2[i] != '\0'){
        if(str1[i] > str2[i]){
            return 1;
        }else if(str1[i] < str2[i]){
            return -1;
        }
        i++;
    }
    if(str1[i] == '\0' && str2[i] == '\0'){
        return 0;
    }else if(str1[i] == '\0'){
        return 1;
    }else{
        return -1;
    }
}

char* my_strcat(char* destination,const char* source)
{
    /* Write your code here */
    int i = 0,j = 0;
    while(destination[j] != '\0'){
        j++;
    }
    while(source[i] != '\0'){
        destination[j + i] = source[i];
        i++;
    }
    destination[j + i] = '\0';
    return destination;
}

int my_atoi(const char* str)
{
    /* Write your code here */
    int num = 0,i = 0;
    if(str[i] == '-' || str[i] == '+'){
        i++;
    }
    while(str[i] != '\0'){
        if(str[i] >= '0' && str[i] <= '9'){
            num = num * 10 + (str[i] - '0');
        }
        i++;
    }
    if(str[0] == '-'){
        num *= -1;
    }
    return num;
}

/*
int main(void)
{
    int cmd;
    // cmd meaning:
    // 1: strlen
    // 2: strcpy
    // 3: strcmp
    // 4: strcat
    // 5: atoi
    
    char string1[1000] = "";
    char string2[1000] = "";
    char* result_string;
    int result_int;
    while(scanf(" %d",&cmd) != EOF)
    {
        switch(cmd)
        {
        case 1:
            scanf(" %s",string1);
            result_int = my_strlen(string1);
            printf("%d\n",result_int);
            break;
        case 2:
            scanf(" %s",string2);
            result_string = my_strcpy(string1,string2);
            printf("string1 = %s\n",string1);
            printf("result = %s\n",result_string);
            break;
        case 3:
            scanf(" %s %s",string1,string2);
            result_int = my_strcmp(string1,string2);
            printf("%d\n",result_int);
            break;
        case 4:
            scanf(" %s %s",string1,string2);
            result_string = my_strcat(string1,string2);
            printf("string1 = %s\n",string1);
            printf("result = %s\n",result_string);
            break;
        case 5:
            scanf(" %s",string1);
            result_int = my_atoi(string1);
            printf("%d\n",result_int);
            break;
        }
    }
}
//*/