#include<stdio.h>
#include<unistd.h>

int main(int arg, char const *args[])
{
    printf("%s\n",*(args+2));
    printf("%d\n",arg);
    return 0;
}
//gcc -o ex.x exercice.c
//./ex.x mphamed 1 ahmed 12

//arg =5 
//args[]=['./ex.x' ,'mphamed' , '1' ,'ahmed' , '12']