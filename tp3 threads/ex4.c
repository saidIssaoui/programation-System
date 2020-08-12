#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include<semaphore.h>
#define N 10
sem_t _FULL,_VIDE;
pthread_mutex_t mon_mutex;
pthread_mutex_t prod_mutex;
int buffer[100];
int ind_prod=0,ind_cons=0;

void* producteur(void * unused){
    while(1){
        sleep(1);
        int item=rand()%100;
        sem_wait(&_FULL);
        pthread_mutex_lock(&mon_mutex);
        buffer[ind_prod]=item;
        printf("Buffer[%d]=%d  : Produire\n" ,ind_prod,item);
        ind_prod++;
        pthread_mutex_unlock(&mon_mutex);
        sem_post(&_VIDE);
        
    }
    
}
void* consommer(void * unused){
    
    while(1){
        sleep(rand()%3);
        sem_wait(&_VIDE);
        pthread_mutex_lock(&mon_mutex);
            printf("**Buffer[%d]=%d:consommer\n",ind_prod,buffer[ind_prod]);
            ind_prod--;
        pthread_mutex_unlock(&mon_mutex);
        sem_post(&_FULL);
    }
}
int main(int argc,char * args[]){
    sem_init(&_FULL,0,N);
    sem_init(&_VIDE,0,0);

    pthread_t th_prod[3];
    pthread_t th_cons[3];

    for(int i=0;i<3;i++){
        pthread_create(&th_prod[i],NULL,producteur,NULL);
    }
    for(int i=0;i<3;i++){
        pthread_create(&th_cons[i],NULL,consommer,NULL);
    }
    for(int i=0;i<3;i++){
        pthread_join(th_prod[i], NULL);
    }
    for(int i=0;i<3;i++){
         pthread_join(th_cons[i], NULL);
    }
    
}