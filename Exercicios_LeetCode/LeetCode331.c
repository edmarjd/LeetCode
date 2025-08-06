bool isValidSerialization(char* preorder) {
    int position  = 1; // vaga para a raiz

    char *token = strtok(preorder, ","); // Modifica a string original

    while (token != NULL) {

        if (--position < 0){
            return false;
        }
    
        //Se o nó atual não for nulo, é um nó com valor um nó com 
        //valor fornece duas possiblidades (esquerda , direita).
        if (strcmp(token, "#") != 0) {
            position += 2;
        }

        token = strtok(NULL, ","); // Move para o próximo termo.
    }
    return position == 0;
}
