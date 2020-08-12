#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *args[])
{
    char choix;
    int i;
    pid_t pid = fork();

    if (pid == 0)
    {
        int cpt = 0;
        while (1)
        {
            printf("\nServer_Fonctionnement_%d\n", cpt);
            sleep(2);
            cpt++;
        }
    }
    else
    {
        do
        {
            printf("----Menu----\n");
            printf("s - Proc père endort son fils !\n");
            printf("r - Proc père redémarre son fils !\n");
            printf("q - Proc père tue son fils avant de se terminer !\n");
            printf("a - Quitter !\n");
            printf("Donner votre choix: ");
            choix = getchar();
            getchar();
            switch (choix)
            {
            case 's':
                kill(pid, SIGSTOP);
                break;
            case 'r':
                kill(pid, SIGCONT);
                break;
            case 'q':
                kill(pid, SIGTERM);
                break;
            default:
                choix = 'a';
                break;
            }
        } while (choix != 'a');
        
    }
}
