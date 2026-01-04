#include <stdio.h>
#include <ctype.h>  // For isdigit() function
#include <stdlib.h> // For atoi() if needed

#define MAX 100  // Maximum size of stack

int stack[MAX];  // Stack to store numbers
int top = -1;    // Index of top element in stack

// Function to push a value onto the stack
void push(int value) {
    if(top >= MAX - 1) {       // Check for stack overflow
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;      // Increment top and add value
}

// Function to pop a value from the stack
int pop() {
    if(top == -1) {            // Check for stack underflow
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];        // Return top value and decrement top
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* exp) {
    int i = 0;
    while(exp[i] != '\0') {    // Scan each character until end of string
        char ch = exp[i];

        if(isdigit(ch)) {      // If the character is a number
            push(ch - '0');    // Convert char to int and push to stack
        }
        else {                 // If the character is an operator
            int val2 = pop();  // Pop the second operand
            int val1 = pop();  // Pop the first operand

            // Apply the operator and push the result back
            switch(ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                default: 
                    printf("Invalid operator %c\n", ch); 
                    return -1;
            }
        }
        i++;  // Move to next character
    }

    // At the end, stack contains the final result
    return pop();
}

int main() {
    char exp[100];
    printf("Enter a postfix expression (e.g. 231*+9-): ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);  // Evaluate the expression
    printf("Result = %d\n", result);    // Print the result

    return 0;
}
