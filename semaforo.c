#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct Semaforo {
    char nomeVia[50];        
    struct Semaforo* proximo; 
} Semaforo;

Semaforo* criarVia(char* nome) {
    Semaforo* novo = (Semaforo*)malloc(sizeof(Semaforo));
    strcpy(novo->nomeVia, nome);
    novo->proximo = NULL;
    return novo;
}

Semaforo* avancarSemaforo(Semaforo* atual) {
    return atual->proximo;
}

int main() {
    Semaforo *v1 = criarVia("Avenida Principal");
    Semaforo *v2 = criarVia("Rua Lateral A");
    Semaforo *v3 = criarVia("Rua Lateral B");
    Semaforo *v4 = criarVia("Rua Lateral C");

    v1->proximo = v2;
    v2->proximo = v3;
    v3->proximo = v4;
    v4->proximo = v1; 

    Semaforo *atual = v1;

    printf("--- Motor Logico de Trafego Iniciado (Smart Cities) ---\n");

    while (1) {
        printf("\n[SINAL VERDE] -> Via Liberada: %s (8s)\n", atual->nomeVia);
        sleep(8); 
        
        printf("[SINAL AMARELO] -> Atencao: %s (3s)\n", atual->nomeVia);
        sleep(3); 
        
        printf("[SINAL VERMELHO] -> Via Fechada: %s\n", atual->nomeVia);
        
        atual = avancarSemaforo(atual);
    }

}
