#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

float a, b, h;
int t, n;

float func1(float x){
    return 5;
}

float func2(float x){
    float r1, r2;
    r1 = sin(2.0 * x);
    r2 = cos(5.0 * x);
    return (r1 + r2);
}

char notacaoCientifica(){}///////////////////////////////////////////////////////////////////////////////

float regraDoTrapezio(){}


void* hello_word(void *tid){//tid == thread id
    if ((int)(size_t)tid > 0){
        pthread_join(threads[(size_t)tid - 1], &thread_return);
        printf("essa é a thread %d. a thread %d terminou.\n", (int)(size_t)tid, (int)(size_t)tid-1);
    }else{
        printf("essa é a primeira thread.\n");
    }

    soma += 1;
    printf("o valor da soma é: %d\n", soma);
    sleep(1);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){

    for (i = 0; i < NTHREADS; i++){
        printf("processo principal criando thread #%d\n", i);
        status = pthread_create(&threads[i], NULL, hello_word, (void *)(size_t)i);

        if(status != 0){
            printf("erro na criaçao da thread. codigo de erro: %d\n", status);
            return 1;
        }
    }

    
    printf("esperando thread %d finalizar...\n", i-1);
    pthread_join(threads[i-1], &thread_return);
    printf("thread %d finalizada\n", i-1);
    
    printf("processo vai finalizar a soma: %d\n", soma);

    return 0;
}