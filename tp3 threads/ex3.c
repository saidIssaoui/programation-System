#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include<semaphore.h>
#define N 10
sem_t _FULL,_VIDE;
pthread_mutex_t mon_mutex;
int buffer[100];
int ind_prod=0,ind_cons=0;

void* producteur(void * unused){
    while(1){
        sleep(1);
        int item=rand()%100;
        sem_wait(&_FULL);
        buffer[ind_prod]=item;
        printf("Buffer[%d]=%d  : Produire\n" ,ind_prod,item);
        ind_prod++;
        if(ind_prod==N){
            ind_prod=0;
        }
        sem_post(&_VIDE);
        
    }
    
}
void* consommer(void * unused){
    
    while(1){
        sleep(5);
        sem_wait(&_VIDE);
        pthread_mutex_lock(&mon_mutex);
            printf("**Buffer[%d]=%d:consommer\n",ind_cons,buffer[ind_cons]);
            ind_cons++;
            if(ind_cons==N)
                ind_cons=0;
        pthread_mutex_unlock(&mon_mutex);
        sem_post(&_FULL);
    }
}
int main(int argc,char * args[]){
    sem_init(&_FULL,0,N);
    sem_init(&_VIDE,0,0);

    pthread_t th_prod;
    pthread_t th_cons[3];

    
    pthread_create(&th_prod,NULL,producteur,NULL);
    for(int i=0;i<3;i++){
        pthread_create(&th_cons[i],NULL,consommer,NULL);
    }
    
    pthread_join(th_prod, NULL);
    for(int i=0;i<3;i++){
         pthread_join(th_cons[i], NULL);
    }
    
}