#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
        fgets(str, sizeof(str), stdin); // Read a line including spaces

    int n = strlen(str);
    char res[n + 1]; // +1 for null terminator
    int j = 0; // Index for result string
int i;
    for (i = 0; i < n; i++) {
        if (str[i] != ' ') {
            res[j++] = str[i]; // Copy non-space characters to result string
        }
    }
    res[j] = '\0'; // Null terminate the result string

    printf("%s\n", res);
    return 0;
}
