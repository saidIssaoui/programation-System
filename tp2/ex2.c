#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
void question2(int n){
    int cpt=n;
    while(cpt>0){
        pid_t id=fork();
            if(id ==0)
            {   printf("mon pid :%d ,mon ppid:%d \n",getpid(),getppid());
                sleep(2);
                printf("fils terminer.\n");
                exit(0);
            }else
            {
                waitpid(id,NULL,0);
            }
            
        cpt--;

        }
        
exit(0);
}


void question3(int n){
    if(n==0){
        exit(0);
    }
    pid_t id=fork();
        if(id==0){
             printf("mon pid :%d ,mon ppid:%d \n",getpid(),getppid());
             question3(n-1);
        }else
        {
            waitpid(id,NULL,0);
        }
    exit(0);   
}
int main(int arg, char const *args[])
{
    if (arg !=3){
        printf("le nombre d'argument de main est incorrecte.\n");
        exit(0);
    }
    switch(atoi(args[1])){
        case 2:printf("invoquation de question 2\n");
                question2(atoi(args[2]));
                break;

        case 3:printf("invoquation de question 3\n");
                question3(atoi(args[2]));
                break;
        default: return 0;
    }
    return 0;
}
//./ex2.x 2 4