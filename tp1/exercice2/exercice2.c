#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
void tridecroissant( int a[], int b )
{
    int i=0;
    int x=0;
    int j=0;
 
    for(i=0;i<b;i++)
    {
        for(j=1;j<b;j++)
        {
            if(a[i]>a[j])
            {
                x=a[i];
                a[i]=a[j];
                a[j]=x;
                j--;
                }
 
        }
 
        }
 
    x=a[0];
    for(i=0;i<b;i++)
    a[i]=a[i+1];
    a[b-1]=x;
 
}
void tricroissant( int a[], int b )
{
    int i=0;
    int x=0;
    int j=0;
 
    for(i=0;i<b;i++)
    {
        for(j=1;j<b;j++)
        {
            if(a[i]<a[j])
            {
                x=a[i];
                a[i]=a[j];
                a[j]=x;
                j--;
                }
 
        }
 
        }
 
    x=a[0];
    for(i=0;i<b;i++)
    a[i]=a[i+1];
    a[b-1]=x;
 
}
int main(){

    int tab[100];
    int i;
    for(i=0;i<5;i++){
        printf("saise le %d'eme valeur: ",i+1);
        scanf("%d",&tab[i]);
    }
    for(i=0;i<5;i++){
        printf("|%d|",tab[i]);
    }
    printf("\n");
    pid_t id=fork();
    if(id==0){
        tricroissant(tab,5);
        for(i=0;i<5;i++){
        printf("|%d|",tab[i]);   
    }
    printf("\n");

    }else{
        wait(NULL);
        tridecroissant(tab,5);
        for(i=0;i<5;i++){
        printf("|%d|",tab[i]);   
    }
    printf("\n");
    }

}