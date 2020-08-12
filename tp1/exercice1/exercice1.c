#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{

    printf("je suis le père. Mon pid est %d Le pid de mon père est %d Je n’ai pas encore créé de fils\n",getpid(),getppid());
    
    pid_t id=fork();
    if(id>0){
        wait(NULL);
        printf("\nun fils crée de pid :%d",id);
        
        printf("\nJe continu mon execution.\n");
    }else{
        printf("\nJe suis le fils, mon pid est %d et le pid de mon pére est %d",getpid(),getppid());
    exit(1);
    }
    return 0;
}