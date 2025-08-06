char* reversePrefix(char* word, char ch) {
    int i = 0;

<<<<<<< HEAD
    while (word[i] != '\0' && word[i] != ch) {
        i++;
    }

    if (word[i] == '\0') {
        return word;
    }

    char* result = strdup(word);

    int start = 0;
    int end = i;

    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }

    return result;
}
=======
    while (word[i] != '\0' && word[i] != ch) {
        i++;
    }

    if (word[i] == '\0') {
        return word;
    }

    char* result = strdup(word);

    int start = 0;
    int end = i;

    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }

    return result;
}

>>>>>>> 7081605aa0e9c57914c84a3636174e86f8a1b378