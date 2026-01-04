#include <stdio.h>

int main() {
    char s[100];
    int i = 0, a = 0, b = 0;

    printf("Enter string: ");
    scanf("%s", s);

    /* Count a's */
    while (s[i] == 'a') {
        a++;
        i++;
    }

    /* Count b's */
    while (s[i] == 'b') {
        b++;
        i++;
    }

    /* Validation */
    if (s[i] == '\0' && a == b && a > 0)
        printf("Valid string (a^n b^n)\n");
    else
        printf("Invalid string\n");

    return 0;
}
