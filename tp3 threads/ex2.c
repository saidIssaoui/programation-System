#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
int cpt=0;
pthread_mutex_t mon_mutex;
void* fonctTh1(void * arg){
    int nbr_it=*((int *)arg);
    int i;
    for(i=0;i<nbr_it;i++){
    pthread_mutex_lock(&mon_mutex);
    cpt++;
    sleep(rand()%5);
    pthread_mutex_unlock(&mon_mutex);
    }
}
void* fonctTh2(void * arg){
        while(1){
             printf("\n%d",cpt);
            sleep(2);
        }
}
int main(int argc,char * args[]){
    int nbr_ite=atoi(args[1]);

    pthread_t th1,th2;
    
    pthread_create(&th1,NULL,fonctTh1,&nbr_ite);
    pthread_create(&th2,NULL,fonctTh2,&nbr_ite);
    
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
}