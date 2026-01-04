#include <stdio.h>
#include <ctype.h>

int main() {
    char exp[100];
    int stack[100], top = -1;

    printf("Enter prefix expression (e.g. -+2*319): ");
    scanf("%s", exp);

    // Scan from right to left
    for(int i = strlen(exp) - 1; i >= 0; i--) {
        if(isdigit(exp[i])) {
            stack[++top] = exp[i] - '0';  // Push digit
        } else {
            int a = stack[top--];  // Pop first operand
            int b = stack[top--];  // Pop second operand
            switch(exp[i]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
            }
        }
    }

    printf("Result = %d\n", stack[top]);
    return 0;
}
