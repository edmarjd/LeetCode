#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int *dados;
    int topo;
    int capacidade;
} Pilha;


Pilha *RESET(int capacidade);
bool EMPTY(Pilha *pilha);
bool FULL(Pilha *pilha);
bool PUSH(Pilha *pilha, int valor);
int POP(Pilha *pilha);
void CLEAR(Pilha *pilha);


Pilha* RESET(int capacidade){
    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->dados = (int *) malloc(capacidade * sizeof(int));
    pilha->topo = -1;
    pilha->capacidade = capacidade;
    return pilha;
}

bool EMPTY(Pilha *pilha) {
    return pilha->topo == -1;
}

bool FULL(Pilha *pilha) {
    return pilha->topo == pilha->capacidade - 1;  
}

bool PUSH(Pilha *pilha, int valor){
    if (!FULL(pilha)) {
        pilha->dados[++(pilha->topo)] = valor;
        return true;
    } else {
        return false;
    }
}

int POP(Pilha *pilha){
    if (!EMPTY(pilha)) {
        return pilha->dados[(pilha->topo)--];
    } else {
        printf("Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
}

void CLEAR(Pilha *pilha){
    free(pilha->dados);
    free(pilha);
}


int evalRPN(char** tokens, int tokensSize) {
    Pilha *pilha = RESET(tokensSize);

    for (int i = 0; i < tokensSize; i++) {
        char *token = tokens[i];

        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
            strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            
            int x = POP(pilha);  
            int y = POP(pilha);  
            int resultado = 0;

            if (strcmp(token, "+") == 0) resultado = y + x;
            if (strcmp(token, "-") == 0) resultado = y - x;
            if (strcmp(token, "*") == 0) resultado = y * x;
            if (strcmp(token, "/") == 0) resultado = y / x;

            PUSH(pilha, resultado);
        } else {
            PUSH(pilha, atoi(token));
        }
    }

    int final = POP(pilha);
    CLEAR(pilha);
    return final;
}


int main() {
    char *tokens[] = {"2", "1", "+", "3", "*"}; 
    int tokensSize = sizeof(tokens) / sizeof(tokens[0]);

    int resultado = evalRPN(tokens, tokensSize);
    printf("Resultado da expressão RPN: %d\n", resultado);

    return 0;
}
