#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int fds[2];
    pid_t pid;
    pipe(fds);
    pid = fork();
    if(pid == (pid_t)0){
        close(fds[1]);
        dup2(fds[0], STDIN_FILENO);
        execlp("sort", "sort", 0);   // si on specifie un fichier elle va sorter si non sorter l'entree standard
    }
    else{
        FILE* stream;
        close(fds[0]);
        stream = fopen(fds[1], "w");
        fprintf(stream, "C'est un test.\n");
        fprintf(stream, "Un poisson, deux poissons.\n");
        fflush(stream);
        close(fds[1]);
        waitpid(pid, NULL, 0);
    }
    return 0;
}