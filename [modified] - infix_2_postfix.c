#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Function to return precedence of operators
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

//Function to perform infix to postfix conversion
void infix_2_postfix(char* exp) {
    int len = strlen(exp);
    char result[len+1], stack[len];
    int j = 0; //To keep track current position of Result-array
    int top = -1;//To keep track Stack's top-value

    for (int i = 0; i < len; i++) {
        char c = exp[i];

        //If the scanned character is an operand, add it to the output string.
        if (isalnum(c)){
            result[j] = c;
            j++;
        }

        // If the scanned character is an '(', push it to the stack.
        else if (c == '('){
            top++;
            stack[top] = c;
        }

        // If the scanned character is an ')', pop and add to the output string from the stack
        // until an '(' is encountered.
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                result[j] = stack[top];
                j++;
                top--;
            }
            top--; // Remove '(' from the stack
        }

        // If an operator is scanned
        else {
            while (top != -1 && (prec(c) <= prec(stack[top]))) {
                result[j] = stack[top];
                j++;
                top--;
            }
            top++;
            stack[top] = c;
        }
    }
    // Pop all the remaining elements from the stack
    while (top != -1) {
        result[j] = stack[top];
        j++;
        top--;
    }
    result[j] = '\0';
    printf("%s\n", result);
}

int main() {
    char exp[] = "(1+2)+(3*(5+3))";
    infix_2_postfix(exp);
    return 0;
}
