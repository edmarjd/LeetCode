int romanToInt(char *s) {
    int values[256] = {0};
    values['I'] = 1;
    values['V'] = 5;
    values['X'] = 10;
    values['L'] = 50;
    values['C'] = 100;
    values['D'] = 500;
    values['M'] = 1000;

    int sum = 0;
    int length = strlen(s);

    for (int i = 0; i < length; i++) {
        int current = values[s[i]];
        if (i + 1 < length) {
            int next = values[s[i + 1]];
            if (current < next) {
                sum += (next - current);
                i++;
                continue;
            }
        }
        sum += current;
    }

    return sum;
}
