#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(int argc, char* args[]){
    //creation pipe: 0- lire  1- ecrire
    //le pipe se trouve au niveau du kernel donc va pas etre dupliqué
    int pfd1[2];
    pipe(pfd1);

    int pfd2[2];
    pipe(pfd2);

    pid_t pid = fork();
    //fils
    if(pid==0){
        int result[5];
        close(pfd1[1]);
        read(pfd1[0], result, sizeof(result));
        close(pfd1[0]);
        
        for(int i=0;i<5;i++){
            printf("|%d|",result[i]);
        }
        printf("\n");
      for(int i=0;i<5;i++){
            result[i]=result[i]*2;
        }
        close(pfd2[0]);
        write(pfd2[1], result, sizeof(result));
        close(pfd2[1]);
    }
    //père
    else{
        int tab[5];
        int tab2[5];
        for(int i=0;i<5;i++){
            printf("Saisie le %déme entier:",i+1);
            scanf("%d",&tab[i]);
        }
        close(pfd1[0]);
        write(pfd1[1], tab, sizeof(tab));
        close(pfd1[1]);

        close(pfd2[1]);
        read(pfd2[0], tab2, sizeof(tab));
        close(pfd2[0]);
        
        for(int i=0;i<5;i++){
            printf("|%d|",tab2[i]);
        }
        printf("\n");
         wait(NULL);
       
    }
}