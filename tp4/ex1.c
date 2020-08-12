#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc, char* args[]){
    char* monFichier = args[1];
    //creation pipe: 0- lire  1- ecrire
    //le pipe se trouve au niveau du kernel donc va pas etre dupliqué
    int pfd1[2];
    pipe(pfd1);

    int pfd2[2];
    pipe(pfd2);

    pid_t pid = fork();
    //fils
    if(pid==0){
        int result;
        char word[50];
        printf("Mot = ");
        scanf("%s",word);
        close(pfd2[0]); //fermer port de lecture
        write(pfd2[1], word, 50);
        close(pfd2[1]);
        close(pfd1[1]);
        read(pfd1[0], &result, sizeof(int));
        close(pfd1[0]);
        if(result == 0)
            printf("Le mot n'existe pas !\n");
        else
        {
            printf("Mot existe !\n");
            exit(1);
        }
        
    }
    //père
    else{
        char* sword[50];
        char word[50];
        FILE* ptrf = fopen("monFichier.txt", "r");
        int trouve=0;
        close(pfd2[1]);
        read(pfd2[0], word, 50);
        while(!feof(ptrf)){
            fscanf(ptrf, "%s", sword);
            if(strcmp(word,sword) == 0){
                trouve = 1;
                break;
            }
        }
        close(pfd1[0]);
        write(pfd1[1], &trouve, sizeof(int));
        close(pfd1[1]);
        wait(NULL);
    }
}