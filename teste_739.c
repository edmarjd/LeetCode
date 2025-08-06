// Arquivo: teste_739.c

#include <stdio.h>
#include <stdlib.h>

// ======================================================================
// 1. Declare as structs e as funções do seu arquivo LeetCode
//    (copie as assinaturas das funções de 739.c para cá)
// ======================================================================

// Exemplo (adapte para a struct e função real do seu 739.c)
typedef struct {
    // Definição da sua pilha ou outra estrutura
    int* data;
    int top;
} Pilha;

void RESET(Pilha *p);
void PUSH(Pilha* p, int elemento);
// ... declare todas as outras funções de 739.c aqui

// ======================================================================
// 2. Inclua o seu código LeetCode.
//    Isso faz com que o compilador enxergue o corpo das funções.
// ======================================================================
#include "739.c"


// ======================================================================
// 3. Crie a função main() para ser a "chave de ignição"
// ======================================================================
int main() {
    printf("--- Iniciando teste para o problema 739 ---\n");

    // Crie aqui os dados de entrada para o seu problema
    // Exemplo:
    Pilha minha_pilha;

    // Chame as funções do seu arquivo 739.c para testá-las
    RESET(&minha_pilha);
    PUSH(&minha_pilha, 10);
    PUSH(&minha_pilha, 20);

    // Imprima resultados para ver se funcionou
    printf("Teste concluido. Verifique os valores no depurador.\n");

    return 0; // Fim do programa
}