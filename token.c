#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *keywords[] = {"int","float","if","else","while","for","return"};
int keywordCount = 7;

// Check if a string is a keyword
int isKeyword(char *s) {
    for(int i=0; i<keywordCount; i++)
        if(strcmp(s, keywords[i])==0) return 1;
    return 0;
}

int main() {
    char str[100];
    printf("Enter an expression: ");
    fgets(str, 100, stdin);  // safer than gets()

    for(int i=0; str[i]; ) {
        if(isspace(str[i])) { i++; continue; }

        // Identifier or keyword
        if(isalpha(str[i])) {
            char temp[50]; int k=0;
            while(isalnum(str[i])) temp[k++] = str[i++];
            temp[k]='\0';
            printf("%s: %s\n", isKeyword(temp) ? "Keyword" : "Identifier", temp);
        }
        // Number
        else if(isdigit(str[i])) {
            char temp[50]; int k=0;
            while(isdigit(str[i])) temp[k++] = str[i++];
            temp[k]='\0';
            printf("Number: %s\n", temp);
        }
        // Operator
        else if(strchr("+-*/=<>!", str[i])) {
            if((str[i]=='=' || str[i]=='<' || str[i]=='>' || str[i]=='!') && str[i+1]=='=') {
                printf("Operator: %c%c\n", str[i], str[i+1]); i+=2;
            } else { printf("Operator: %c\n", str[i]); i++; }
        }
        // Parenthesis
        else if(str[i]=='(' || str[i]==')') { printf("Parenthesis: %c\n", str[i]); i++; }
        // Other symbols
        else { printf("Symbol: %c\n", str[i]); i++; }
    }

    return 0;
}
