char* reversePrefix(char* word, char ch) {
    int i = 0;

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
