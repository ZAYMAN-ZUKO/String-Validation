#include <stdio.h>
#include <ctype.h>

int main() {
    char exp[100];
    int stack[100], top = -1;

    printf("Enter postfix expression (e.g. 231*+9-): ");
    scanf("%s", exp);

    for(int i = 0; exp[i]; i++) {
        if(isdigit(exp[i])) {
            stack[++top] = exp[i] - '0';  // Push digit
        } else {
            int b = stack[top--];  // Pop second operand
            int a = stack[top--];  // Pop first operand
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
