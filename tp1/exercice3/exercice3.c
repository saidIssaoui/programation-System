#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(int arcg, char *argv[])
{
    int tab[100];
    int i;
    for(i=0;i<5;i++){
        printf("saise le %d'eme valeur: ",i+1);
        scanf("%d",&tab[i]);
    }
    pid_t id=fork();
    if(id==0){
        execl("/home/akrem/Desktop/programation System/tp1/exercice2/ex2","",NULL);
    }else{
        wait(NULL);
        for(i=0;i<5;i++){
        printf("|%d|",tab[i]);
    }
    printf("\n");
    }
}