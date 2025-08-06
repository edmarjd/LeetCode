/*Given a string s, return true if s is a good string, or false otherwise.

A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).
*/

bool areOccurrencesEqual(char* s) {
    int count[256] = {0};
    
    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char c = s[i];
        count[c]++;
    }

    int referece = -1;
    
    for (int i = 0; i < 256 ; i++) {

        if (count[i] > 0) {
                if (referece == -1) {
                    referece = count[i];
                } else {
                    if(count[i] != referece) {
                        return false;
                }
            }
        }
    }
       
    return true;
}
