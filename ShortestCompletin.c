char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int letrasPlaca[26] = {0};

    for (int i = 0; licensePlate[i]; i++) {
        if (isalpha(licensePlate[i])) {
            letrasPlaca[tolower(licensePlate[i]) - 'a']++;
        }
    }

    char* resultado = NULL;

    for (int i = 0; i < wordsSize; i++) {
        int letrasPalavra[26] = {0};

        for (int j = 0; words[i][j]; j++) {
            if (isalpha(words[i][j])) {
                letrasPalavra[tolower(words[i][j]) - 'a']++;
            }
        }

        int completa = 1; 
        for (int k = 0; k < 26; k++) {
            if (letrasPalavra[k] < letrasPlaca[k]) {
                completa = 0;
                break;
            }
        }

        if (completa) {
            if (resultado == NULL || strlen(words[i]) < strlen(resultado)) {
                resultado = words[i];
            }
        }
    }

    return resultado;
}
