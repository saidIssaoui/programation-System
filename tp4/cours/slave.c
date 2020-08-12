#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void gererSigUtil(int i)
{
    int i = 1;
    printf("Traitement spécifique par le slave !");
    while (i <= 5)
    {
        printf("%d.", i);
    }
}

//fflush(stdout)

int main(int argc, char *args[])
{
    printf("le PID = %d", getpid());
    int cpt = 0;
    signal(SIGUSR1, gererSigUtil); //il faut definir la methode gerer
    while (1)
    {
        printf("Server_Fonctionnement_%d\n", cpt);
        sleep(1);
        cpt++;
    }
}
