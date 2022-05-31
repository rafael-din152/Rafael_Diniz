/**
 * @file com_rc.c
 * @author Rafael Diniz de Oliveira
 * @brief Implementação do TP5 de BCC264 COM Região Crítica
 * @date 2022-05-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef REGIAO_CRITICA
#define REGIAO_CRITICA

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <signal.h>

int saldo = 0;

void *soma(void *arg); // soma
void *subtrai(void *arg); // subtracao


int main(int argc, char **argv) {    
    int n;
    scanf("%d", &n);

    int i = 0;

    pthread_t threads[2];

    int turn = 0;
    while(i <= (n*2)){
        while(1 == 1){
            if(turn == 0){
                pthread_join(threads[0], NULL);
                pthread_create(&(threads[0]), NULL, soma, NULL);
                pthread_kill(threads[0], 0);
                turn++;
                i++;
            }else
                break;
        }

        while(1 == 1){
            if(turn == 1){
                pthread_join(threads[1], NULL);
                pthread_create(&(threads[1]), NULL, subtrai, NULL);
                pthread_kill(threads[1], 0);
                turn--;
                i++;
            }else
                break;
        }
    }

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
