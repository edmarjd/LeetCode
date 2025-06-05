/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int *dados;
    int topo;
    int capacidade;
}Pilha;

Pilha *RESET(int capacidade) {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->dados = (int *) malloc(capacidade * sizeof(int));
    p->topo = -1;
    p->capacidade = capacidade;
    return p; 
}

bool EMPTY (Pilha *p) {
    if (p->topo == -1) {
        return true;
    } else {
        return false;
    }
}

bool FULL(Pilha *p) {
    if(p->topo == p->capacidade - 1) {
        return true;
    } else {
        return false;
    }
}

bool PUSH(Pilha *p, int valor) {
    if(!FULL(p)) {
        p->topo += 1;
        p->dados[p->topo] = valor;
        return true;
    } else {
        return false;
    }
}

int  POP(Pilha *p) {
    if(!EMPTY(p)) {
        int valor = p->dados[p->topo];
        p->topo -= 1;
        return valor;
    } else {
        printf("Erro pilha vazia\n");
        exit(EXIT_FAILURE);
    }
}

void CLEAR(Pilha *p) {
    free(p->dados);
    free(p);
}
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int *resposta = (int*) calloc(temperaturesSize, sizeof(int));
    *returnSize = temperaturesSize;
    Pilha *p = RESET(temperaturesSize);

    for (int i = 0; i < temperaturesSize; i++) {
        while(!EMPTY(p) && temperatures[i] > temperatures[p->dados[p->topo]]){
            int idx = POP(p);
            resposta[idx] = i - idx;
        }
        PUSH(p, i);
    }

    CLEAR (p);

    return resposta;
}
