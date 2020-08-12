#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *args[])
{
    pid_t pid;
    int choix;
    pid = atoi(args[1]); //recuperer le pid du processus a commander
    do
    {
        printf("----Menu----\n");
        printf("0 - Executer uen tache particulière !\n");
        printf("1 - Mettre en pause le processus !\n");
        printf("2 - Reprendre fonctionnement processus !\n");
        printf("3 - Tuer le processus !\n");
        printf("4 - Quitter !\n");
        printf("Donner votre choix: ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 0:
            kill(pid, SIGUSR1);
            break;
        case 1:
            kill(pid, SIGSTOP);
            break;
        case 2:
            kill(pid, SIGCONT);
            break;
        case 3:
            kill(pid, SIGTERM);
            break;
        }
    } while (choix != 4);
}
