#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getLucky(char* s, int k) {
   char numero[1000] = {0};
   int indice = 0;

   for (int i = 0; s[i] != '\0'; i++) {
        int valor = s[i] - 'a' + 1;
        if (valor >= 10) {
            numero[indice++] = (valor/10) + '0';
            numero[indice++] = (valor%10) + '0';
        } else {
            numero[indice] = valor + '0';
        }
   }

   numero[indice] = '\0';

   for (int t = 0; t < k; t++) {
    int soma = 0;
        for (int i = 0; numero[i] != '\0'; i++) {
            soma += numero[i] - '0';
        }
    sprintf(numero, "%d", soma);
   }

   return atoi(numero);
}
