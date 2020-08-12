#include<stdio.h>
#include<pthread.h>
#include <stdlib.h>
typedef struct TypeTableau
{
    int tab[100];
    int nbr_el;
    int x;
}TTab;
void* init(void* arg){
    TTab *info=(TTab*)arg;
    int val;
    for(int i=0;i<info->nbr_el;i++)
    {   val=rand()% 100;
        info->tab[i]=val;
    }
    for(int i=0;i<info->nbr_el;i++)
    {   printf("|%d",info->tab[i]);
    }
    printf("|\n");
}
int main(int argc, char const *argv[])
{   TTab info;
    info.nbr_el=10;
    
    void* (*ptrAff)(void*);
    ptrAff=init;
    pthread_t thread_id;
    pthread_create(&thread_id,NULL,ptrAff,&info);
    
    short b=0;
    scanf("%d",&info.x);
    for(int i=0;i<info.nbr_el;i++){
        if(info.x==info.tab[i])
        b=1;
        }
    if(b)
        printf("l'element %d existe dans le tableau\n",info.x);
        else 
        printf("l'element %d n'existe pas dans le tableau\n",info.x);
    
    pthread_join(thread_id, NULL);
    
    return 0;
}
