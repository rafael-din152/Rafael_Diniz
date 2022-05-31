/**
 * @file sem_rc.c
 * @author Rafael Diniz de Oliveira
 * @brief Implementação do TP5 de BCC264 SEM Região Crítica
 * @date 2022-05-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SEM_REGIAO_CRITICA
#define SEM_REGIAO_CRITICA

#include <stdio.h>
#include <pthread.h>
#include <signal.h>

int saldo = 0;

void *soma(void *arg); // soma
void *subtrai(void *arg); // subtracao

int main(int argc, char **argv) {    
    int n = 1;
    scanf("%d", &n);
    pthread_t threads[2];

    for (size_t i = 0; i < n; i++)
    {
        pthread_join(threads[0], NULL);
        pthread_create(&(threads[0]), NULL, soma, NULL);
        printf("Operação realizada.\n");

        pthread_join(threads[0], NULL);
        pthread_create(&(threads[0]), NULL, subtrai, NULL);
        printf("Operação realizada.\n");
    }
    
    pthread_kill(threads[0], 0);
    pthread_kill(threads[1], 0);

    return 0;
}

void *soma(void *arg) { 
    printf("Somando...\n");
    saldo += 100;
    printf("Saldo: %d\n\n", saldo);
    pthread_exit(0);
}

void *subtrai(void *arg) { 
    printf("Subtraindo...\n");
    saldo -= 100;
    printf("Saldo: %d\n\n", saldo);
    pthread_exit(0);
}

#endif
