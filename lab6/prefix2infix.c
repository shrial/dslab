//postfix expression to infix expression
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Define a stack structure to hold strings
typedef struct {
    int top;
    char stack[MAX][MAX];
} St;

// Function to initialize the stack
void init(St* s) {
    s->top = -1;
}

// Function to push a string onto the stack
void push(St* s, const char* str) {
    if (s->top < MAX - 1) {
        strcpy(s->stack[++(s->top)], str);
    } else {
        printf("Stack overflow!\n");
    }
}

// Function to pop a string from the stack
void pop(St* s, char* str) {
    if (s->top >= 0) {
        strcpy(str, s->stack[(s->top)--]);
    } else {
        printf("Stack underflow!\n");
    }
}

// Function to get the top string of the stack without popping
void peek(St* s, char* str) {
    if (s->top >= 0) {
        strcpy(str, s->stack[s->top]);
    } else {
        printf("Stack is empty!\n");
    }
}

// Function to convert postfix expression to infix expression
void con(const char* pre, char* in) {
    St s;
    init(&s);


    int len = strlen(pre);

    for (int i = 0; i < len; i++) {
        if (isdigit(pre[i]) || isalpha(pre[i])) {
            char op[2] = {pre[i], '\0'};
            push(&s, op);
        } else {
            char a[MAX], b[MAX];
            pop(&s, a);
            pop(&s, b);
            char result[MAX];
            snprintf(result, sizeof(result), "(%s%c%s)", b, pre[i], a);
            push(&s, result);
        }
    }

    // The final result should be the only item left in the stack
    peek(&s, in);
}

int main() {
    char pre[MAX];
    char in[MAX];

    printf("Enter prefix expression: ");
    scanf("%s", pre);
    int len = strlen(pre);
    for(int i=0;i<(len/2);i++){
        char temp=pre[i];
        pre[i]=pre[len-1-i];
        pre[len-1-i]=temp;
    }

    con(pre, in);
    int len1 = strlen(in);
for(int i=0;i<(len1/2);i++){
        char temp=in[i];
        in[i]=in[len1-1-i];
        in[len1-1-i]=temp;
    }
    for(int i=0;i<len1;i++){
        if(in[i]=='('){
            in[i]=')';
           }
           else if(in[i]==')'){
            in[i]='(';
           }
    }
    printf("Infix expression: %s", in);


    return 0;
}
